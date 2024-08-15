

CREATE TABLE IF NOT EXISTS Genre(
    id SERIAL PRIMARY KEY,
    name VARCHAR(80) NOT NULL
);

CREATE TABLE IF NOT EXISTS Performer(
    id SERIAL PRIMARY KEY,
    name VARCHAR(80) NOT NULL
);

CREATE TABLE IF NOT EXISTS Album(
id SERIAL PRIMARY KEY,
name VARCHAR(80) NOT NULL,
releasedata DATE
);

CREATE TABLE IF NOT EXISTS Track(
id SERIAL PRIMARY KEY,
name VARCHAR(80) NOT NULL,
duration TIME,
album_id INT REFERENCES Album(id)
);

CREATE TABLE IF NOT EXISTS Collection(
id SERIAL PRIMARY KEY,
name VARCHAR(80) NOT NULL,
releasedata date
);


CREATE TABLE IF NOT EXISTS PerformerAlbum(
album_id INTEGER REFERENCES Album(id),
performer_id INTEGER REFERENCES Performer(id), 
CONSTRAINT lk PRIMARY KEY(album_id, performer_id)
);

CREATE TABLE IF NOT EXISTS CollectionTrack(
track_id INTEGER REFERENCES Track(id),
collection_id INTEGER REFERENCES Collection(id),
CONSTRAINT jk PRIMARY KEY(track_id, collection_id)
);

CREATE TABLE IF NOT EXISTS GenrePerformer(
genre_id INT REFERENCES genre(id),
performer_id INT REFERENCES performer(id),
CONSTRAINT op PRIMARY KEY(genre_id, performer_id)
);
