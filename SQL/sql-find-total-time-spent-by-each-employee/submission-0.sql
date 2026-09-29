-- Write your query below

WITH CTE AS (
    SELECT emp_id, event_day, out_time - in_time AS time_spend
    FROM employees
)
SELECT event_day AS day,
    emp_id, SUM(time_spend) AS total_time
FROM CTE
GROUP BY event_day, emp_id