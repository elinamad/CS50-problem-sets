SELECT title FROM movies
JOIN ratings ON movies.id = movie_id
WHERE movies.id IN(
SELECT movie_id FROM stars
WHERE person_id IN(
SELECT people.id FROM people
WHERE name = "Chadwick Boseman"))
ORDER BY rating DESC LIMIT 5;