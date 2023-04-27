SELECT name FROM people
JOIN directors ON id = person_id
WHERE movie_id IN(
SELECT id FROM movies
WHERE id IN(
SELECT movie_id FROM ratings
WHERE rating >= 9.0));