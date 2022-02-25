-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

-- select only Kevin Bacon born in 1958.
-- SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958;

-- select movies id where Kevin Bacon born in 1958 starred
-- SELECT movie_id FROM stars
-- JOIN movies, people
-- ON movie_id = movies.id
-- AND person_id = people.id
-- WHERE person_id =  (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958);

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN
(SELECT movie_id FROM stars
JOIN movies, people
ON stars.movie_id = movies.id
AND stars.person_id = people.id
WHERE person_id =  (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)))
AND name != "Kevin Bacon";


