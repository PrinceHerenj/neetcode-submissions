-- Write your query below

SELECT name, CASE
        WHEN SUM(distance) > 0 THEN SUM(distance)
        ELSE 0
    END AS travelled_distance
FROM users LEFT JOIN rides
    ON users.id = rides.user_id
GROUP BY users.id, name
ORDER BY travelled_distance DESC, name