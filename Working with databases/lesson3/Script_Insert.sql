
INSERT INTO genre(id, name)
VALUES (1, 'ПОП');
INSERT INTO genre
VALUES (2, 'ТЕХНО');
INSERT INTO genre
VALUES(3, 'РОК');         
INSERT INTO genre
VALUES (4, 'PEП');        


INSERT INTO performer(id, name)
VALUES (101,'Андрю');
INSERT INTO performer
VALUES (102,'Айсберг');
INSERT INTO performer 
VALUES(103,'Дон');         
INSERT INTO performer 
VALUES (104,'Халго'); 
INSERT INTO performer 
VALUES (105,'Неизвестно'); 


INSERT INTO album 
VALUES (501, 'Дождь', '2022-07-01');
INSERT INTO album
VALUES (502, 'Академия', '2019-01-29');
INSERT INTO album 
VALUES(503, 'Сон', '2020-03-03');         
INSERT INTO album 
VALUES (504, 'Pен', '2003-04-09');


INSERT INTO track(id, name, duration, albom_id) 
VALUES (1001, 'Дождь в ночи', '00:04:09', 502);
INSERT INTO track(id, name, duration, albom_id)  
VALUES (1002,'Мой сигнал', '00:03:09', 502);
INSERT INTO track(id, name, duration, albom_id)  
VALUES(1003, 'Зеркало', '00:02:56', 501);         
INSERT INTO track(id, name, duration, albom_id)  
VALUES (1004,'Pен_6', '00:05:00', 503);
INSERT INTO track(id, name, duration, albom_id)  
VALUES(1005,'З.К.', '00:03:54', 504);
INSERT INTO track(id, name, duration, albom_id)  
VALUES(1006,'Небеса', '00:07:03', 501);


INSERT INTO collection(id, name, releasedata) 
VALUES (2001,'Для учебы', '2023-04-09');
INSERT INTO collection 
VALUES (2002,'Золотые хиты', '2024-03-19');
INSERT INTO collection  
VALUES(2003,'12', '2020-02-16');         
INSERT INTO collection  
VALUES (2004,'Pен лучшее', '2023-05-21');
INSERT INTO collection  
VALUES (2005,'56', '2019-03-20');


INSERT INTO performeralbum(album_id, performer_id)
VALUES (501, 101);
INSERT INTO performeralbum(album_id, performer_id)
VALUES (501, 103);
INSERT INTO performeralbum(album_id, performer_id)
VALUES (502, 102);
INSERT INTO performeralbum(album_id, performer_id)
VALUES (503, 105);
INSERT INTO performeralbum(album_id, performer_id)
VALUES (504, 104);


INSERT INTO genreperformer(genre_id, performer_id)
VALUES (1, 101);
INSERT INTO genreperformer(genre_id, performer_id)
VALUES (1, 103);
INSERT INTO genreperformer(genre_id, performer_id)
VALUES (2, 102);
INSERT INTO genreperformer(genre_id, performer_id)
VALUES (4, 105);
INSERT INTO genreperformer(genre_id, performer_id)
VALUES (3, 104);


INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2001, 1001);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2001, 1002);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2001, 1003);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2002, 1001);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2002, 1004);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2003, 1005);
INSERT INTO collectiontrack(collection_id, track_id)
VALUES (2004, 1004);

