-- Write your query below

SELECT first_name, last_name, city, state
FROM person LEFT OUTER JOIN address
    ON address.person_id = person.person_id