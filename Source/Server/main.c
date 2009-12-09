/*nimh-doc
 * Project : %(Mofo Online)project
 * File : %(Mofo-server-source)path/main.c
 * License : %(Mofo-server-docs)path/License.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group , %(RaddTeam)group, %(EchidnaTribe)group
 * Created : 2009-12-08
 * Revisions :
 * 2009-12-08 Original draft up of this here file
 * TODO:
 * * nil
 * Purpose :
 * Main Mofo Online Server source file. Send the appropriate information to 
 * the client and Recv the appropriate information. Validation of the 
 * information is handled elsewhere.
 */

/*
 * Mofo Libraries
 */

#include <Mofo/Config.h>
#include <Mofo/Types.h>
#include <Mofo/Arguments.>
#include <Mofo/Regions.h>
#include <Mofo/Players.h>
#include <Mofo/Threads.h>
#include <Mofo/Errors.h>

void mofo_handle_sockets(mofo_arguments,mofo_thread);

int main(int argc, char **argv) {
    mofo_arguments *args = mofo_handle_arguments(argc, argv);

    mofo_players* accounts = mofo_player_connection(mofo_arguments);
    mofo_regions* regions = mofo_region_connection(mofo_arguments);
    
    mofo_state *information = mofo_generate_state();
    mofo_state(information, nimh_string("EN-Ca","Arguments"), mofo_handle_arguments(&argc, argv));
    mofo_state(information, nimh_string("EN-Ca","Accounts"), mofo_player_connection(information));
    mofo_state(information, nimh_string("EN-Ca","Regions"), mofo_regions(information));
    mofo_state(information, nimh_string("EN-Ca","Threads"), mofo_create_thread_head());
    mofo_state(information, nimh_string("EN-Ca","Sockets"), mofo_create_socket_head());
    
    mofo_thread_create(mofo_state(information,nimh_string("EN-Ca","threads")),
		       nimh_string("EN-Ca","Socket Thread"),mofo_handle_sockets);
    mofo_thread_create(mofo_state(information,nimh_string("EN-Ca","threads")),
		       nimh_string("EN-Ca","Error Thread"),mofo_handle_errors)

    while(MOFO_RULES) {
	if(NULL == (mofo_error = grab_mofo_error())) {
	    pthread_exit(mofo_error.pthread_code);
            return mofo_error.return_code;
	}
        sleep 5;
    }

    pthread_exit(NULL);
    return 0;
}

void mofo_handle_sockets(void* state) {
    /* grab the mofo state information*/
    mofo_state_p *information = (mofo_state*) state;
    /* create socket 
     * will put give an error if the thread cannot be created
     */
    mofo_logs(information, debug_information,
              nimh_description("EN-Ca","Try Create Socket", "Attempting to create our login socket"));
    mofo_socket(information, nimh_string("EN-Ca", "Login Socket"), AF_INET, SOCK_STREAM, 0)

    /* bind our listening thread.
     */
    mofo_logs(informaton, debug_information.
	      nimh_description("EN-Ca","Try Bind Socket", "Attempting to bind our login socket"));
    mofo_socket_bind(information, AF_INET. nimh_string("En-Ca","In Address"), nimh_string("EN-Ca","Login Socket"), nimh_string("EN-Ca","Port"))
    /* set out max listen ammount
     */
    mofo_log(information, debug_information,
             nimh_description("EN-Ca","Try Limit Socket", "Attempting to limit our login socket"));
    mofo_socket_listen(information, nimh_string("EN-Ca", "Login Socket"), nimh_string("EN-Ca","Max Listen"));
    /* and now, the login loop
     */
    while(MOFO_RULES) {
	/* Grab our client socket */
	mofo_log(information, debug_information,
	         nimh_description("EN-Ca","Check Client", "Checking for Mofo Client"));
        mofo_socket_select(information, nimh_string("EN-Ca", "Client Socket"), nimh_string("EN-Ca", "In Address"));
	/* Add our log entry */
	mofo_logs(information, log_information, nimh_description("EN-Ca","Got Client", "Client has connected"));
	/* It should be noted this makes a thread for the player of %(Player)-Thread */
	mofo_socket_login(information, nimh_string("EN-Ca", "Client Socket"));
	/* and we will sleep for now--no reason to have the login accepting stuff constantly*/
	sleep 1;
    }

    mofo_end_thread();
}

