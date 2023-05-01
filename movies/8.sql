SELECT name
FROM people
JOIN roles ON people.id = roles.persons_id
JOIN movies ON movies.id = roles.movie_id
WHERE movies.title = 'Toy Story' AND roles.role = 'actor';