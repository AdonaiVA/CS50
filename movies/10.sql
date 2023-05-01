SELECT DISTINCT people.name
FROM people
JOIN directing ON people.id = directing.person_id
JOIN movies ON movies.id = directing.movie_id
WHERE movies.rating >= 9.0;