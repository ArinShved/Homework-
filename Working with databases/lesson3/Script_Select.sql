
SELECT name FROM track
WHERE duration = (
SELECT MAX(duration) from track);

SELECT name FROM track 
WHERE duration > '00:03:50';

SELECT name FROM collection
WHERE releasedata BETWEEN '2018-01-01' AND '2020-01-01';

SELECT name FROM performer 
WHERE name NOT LIKE '% %'

SELECT name FROM track
WHERE name ILIKE '%My%' OR name ILIKE '%мой%';
 



SELECT g.name, COUNT(DISTINCT p.name) AS name_count 
FROM performer p
JOIN genreperformer gf ON p.id = gf.performer_id
JOIN genre g ON gf.genre_id =g.id 
GROUP BY g.name;

SELECT COUNT(t.name) FROM track t
WHERE albom_id IN (
SELECT id FROM album a 
WHERE releasedata BETWEEN '2019-01-01' AND '2020-01-01'
);

SELECT a.name, AVG(t.duration) AS av_tr_d
FROM track t 
JOIN album a ON a.id = t.albom_id 
GROUP BY a.name;

SELECT p.name
FROM performer p 
JOIN performeralbum p2 ON p2.performer_id = p.id 
JOIN album a ON a.id = p2.album_id
WHERE EXTRACT(YEAR FROM a.releasedata) != 2020; 

SELECT c.name 
FROM collection c 
JOIN collectiontrack c2 ON c.id = c2.collection_id 
JOIN track t ON t.id = c2.track_id 
JOIN album a ON a.id = t.albom_id 
JOIN performeralbum p2 ON p2.album_id =a.id 
JOIN performer p ON p.id = p2.performer_id 
WHERE p.id = 102;

