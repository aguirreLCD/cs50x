-- In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
-- Your query should output a table with a single column and a single row (not including the header)
-- containing the average rating.

-- SELECT id FROM movies WHERE year="2012";

-- SELECT rating FROM ratings WHERE movie_id = (SELECT id FROM movies WHERE year=2012);

-- SELECT ROUND(AVG(rating), 2) FROM ratings WHERE movie_id = (SELECT movie_id FROM movies WHERE year = 2012);

-- SELECT ROUND(AVG(rating), 2) FROM ratings;

SELECT AVG(rating) FROM ratings JOIN movies ON movie_id = movies.id WHERE year = 2012;