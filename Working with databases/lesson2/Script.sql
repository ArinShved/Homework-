

create table if not exists Genre(
    id SERIAL primary key,
    name VARCHAR(80) not null
);

create table if not exists Performer(
    id SERIAL primary key,
    name VARCHAR(80) not null
);

create table if not exists Album(
id SERIAL primary key,
name VARCHAR(80) not null,
releasedata date
);

create table if not exists Track(
id SERIAL primary key,
name VARCHAR(80) not null,
duration TIME,
album_id int references Album(id)
);

create table if not exists Collection(
id SERIAL primary key,
name VARCHAR(80) not null,
releasedata date
);


create table if not exists PerformerAlbum(
album_id INTEGER references Album(id),
performer_id INTEGER references Performer(id), 
constraint lk primary key(album_id, performer_id)
);

create table if not exists CollectionTrack(
track_id INTEGER references Track(id),
collection_id INTEGER references Collection(id),
constraint jk primary key(track_id, collection_id)
);

create table if not exists GenrePerformer(
genre_id INT references genre(id),
performer_id INT references performer(id),
constraint op primary key(genre_id, performer_id)
);
