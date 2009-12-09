create table mofo_region (
    id integer primary key,
    name varchar(255),
    description varchar(255),
    mofo_tileset_id integer,
    tilemap data,
    eventmap data,
);

create table mofo_tileset (
    id integer primary key,
    mofo_tile_id integer,
);

create table mofo_tile (
    id integer primary key,
    mofo_palette_id integer,
    tile data,
);

create table mofo_region_monsters (
    id integer primary key,
    mofo_monster_tactics_id integer,
    mofo_bound_id integer,
);

create table mofo_bound (
    id integer primary key,
    x integer,
    y integer,
    length integer,
    modifier integer,
    area_shape integer,
);

create table mofo_bit_events (
    id integer primary key.
    name varchar(255),
    description varchar(255),
    script text,
);

