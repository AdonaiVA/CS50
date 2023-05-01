SELECT movies.title
FROM movies
JOIN stars s1 ON s1.movie_id = m.id AND s1.person_id = (SELECT id FROM people WHERE name = 'Johnny Depp')
JOIN stars s2 ON s2.movie_id = m.id AND s2.person_id = (SELECT id FROM people WHERE name = 'Helena Bonham Carter');