SELECT movies.title
FROM movies
JOIN roles ON movies.id = roles.movie_id
JOIN people ON roles.person_id = people.id
WHERE roles.role = 'actor' AND people.name = 'Chadwick Boseman'
ORDER BY movies.rating DESC
LIMIT 5;
