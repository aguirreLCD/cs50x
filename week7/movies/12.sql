-- In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.



SELECT title FROM movies WHERE id IN
(SELECT movie_id FROM stars
JOIN movies, people
ON movie_id = movies.id
AND person_id = people.id
WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp"))
AND id IN
(SELECT movie_id FROM stars
JOIN movies, people
ON movie_id = movies.id
AND person_id = people.id
WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter"));



-- SELECT title FROM movies WHERE id IN
-- (SELECT movie_id FROM stars
-- JOIN movies, people
-- ON movie_id = movies.id
-- AND person_id = people.id
-- WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp"))
-- AND id IN
-- (SELECT movie_id FROM stars
-- JOIN movies, people
-- ON movie_id = movies.id
-- AND person_id = people.id
-- WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter"));

-- SELECT title FROM movies
-- JOIN stars, people
-- ON stars.movie_id = movies.id
-- AND stars.person_id = people.id
-- WHERE name = "Johnny Depp" AND name = "Helena Bonham Carter";






-- SELECT movie_id FROM stars
-- JOIN movies, people
-- ON movie_id = movies.id
-- AND person_id = people.id
-- WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp");

-- SELECT movie_id FROM stars
-- JOIN movies, people
-- ON movie_id = movies.id
-- AND person_id = people.id
-- WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter");

-- SELECT id FROM people WHERE name = "Johnny Depp";
-- SELECT id FROM people WHERE name = "Helena Bonham Carter";
