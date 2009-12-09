
create table mofo_monster (
    id integer primary key,
    name varchar(255),
    description varchar(255),
    mofo_level integer,
    hp integer,
    pp integer,
    offense integer,
    defense integer,
    iq integer,
    speed integer,
    experience integer,
    dp integer,
    mofo_item_id integer,
    item_chance float,
    mofo_class_id integer,
);

create table mofo_tactics ( 
    id integer primary key,
    name varchar(255),
    description varchar(225),
    script text,
);

create table mofo_monster_tactics (
    id integer primary key,
    mofo_monster_id integer,
    mofo_tactics_id integer,
);

create table mofo_monster_skills (
    mofo_monster_id integer,
    mofo_skill_id integer,
);

