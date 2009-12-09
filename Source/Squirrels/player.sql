create table mofo_player (
    id integer primary key,
    name varchar(255),
    account_balance integer,
    avatar data,
    homepage_name varchar(255),
    homepage_url varchar(255).
    homepage_icon data,
    homepage_image data,
);

create table mofo_player_characters (
    mofo_player_id integer,
    mofo_character_id integer,
);
