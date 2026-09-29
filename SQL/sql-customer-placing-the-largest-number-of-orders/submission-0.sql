-- Write your query below

WITH CTE AS (
    SELECT customer_number, COUNT(*) AS total_orders
    FROM orders
    GROUP BY customer_number
)
SELECT customer_number
FROM CTE
WHERE total_orders = (
    SELECT MAX(total_orders)
    FROM CTE
)