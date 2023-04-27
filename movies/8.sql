SELECT name FROM people
JOIN stars ON person_id = id
WHERE movie_id IN(
SELECT id FROM movies
WHERE title ="Toy Story");