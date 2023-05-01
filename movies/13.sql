SELECT DISTINCT people.name
FROM people 
JOIN stars s1 ON s1.person_id = p.id
JOIN movies m1 ON m1.id = s1.movie_id
JOIN stars s2 ON s2.movie_id = m1.id AND s2.person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth_year = 1958)
WHERE p.name <> 'Kevin Bacon' AND p.id <> s2.person_id;
