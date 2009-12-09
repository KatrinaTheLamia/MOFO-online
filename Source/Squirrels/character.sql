
create table mofo_character (
    id integer primary key,
    name varchar(255),
    mofo_level integer,
    curr_hp integer,
    max_hp integer,
    curr_pp integer,
    max_pp integer,
    offense integer,
    defense integer,
    iq integer,
    speed integer,
    experience integer,
    next_level integer,
    mofo_class_id integer,
);

create table mofo_class (
    id integer primary key,
    name varchar(255),
    ; fill in more crap here
);

create table mofo_class_type_def (
    mofo_class_id integer,
    mofo_type_name varchar(255),
    ammount integer,
);

create table mofo_type (
    name varchar(255),
    description varchar(255),
    icon data,
);

create table mofo_skill (
    mofo_type_name varchar(255),
    mofo_type_ammount varchar(255),
    name varchar(255),
    menu_description varchar(255),
    battle_description varchar(255),
    mofo_item_id integer,
    dispose_item boolean,
    pp_cost integer,
    script text,
);

create table mofo_item (
    id integer primary key,
    buy_dp integer,
    sell_dp integer,
    name varchar(255),
    description varchar(255),
    stat_recover varchar(255),
    stat_ammount signed integer,
    is_key_item boolean,
);
