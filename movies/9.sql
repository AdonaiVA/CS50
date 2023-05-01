SELECT DISTINCT people.name
FROM people
JOIN roles ON people.id = roles.person_id
JOIN movies ON movies.id = roles.movie_id
WHERE roles.role = 'actor' AND movies.year = 2004 AND people.birth_year IS NOT NULL
ORDER BY people.birth_year ASC;