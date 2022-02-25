-- In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
-- Your query should output a table with a single column for the name of each person.

SELECT name FROM people
JOIN movies, directors, ratings
ON ratings.movie_id = movies.id
AND directors.person_id = people.id
AND directors.movie_id = movies.id
WHERE rating >= 9
GROUP BY people.id;


-- SELECT name FROM people WHERE id IN
-- (SELECT person_id FROM directors WHERE movie_id IN
-- (SELECT movie_id FROM ratings WHERE rating >= 9.0))
-- GROUP BY people.id;



-- (SELECT title FROM movies JOIN ratings ON movie_id = movies.id WHERE rating >= 9.0);

-- (SELECT title FROM movies JOIN ratings ON movie_id = movies.id WHERE rating >= 9.0); 1891

-- SELECT rating FROM ratings WHERE rating >= 9.0; 1891



