-- Write your query below

WITH CTE AS (
    SELECT c.customer_id, 
        c.name, 
        p.product_id, 
        p.price, 
        o.quantity, 
        EXTRACT(MONTH FROM o.order_date) AS month,
        EXTRACT(YEAR FROM o.order_date) AS year
    FROM customers c INNER JOIN orders o ON c.customer_id = o.customer_id
        INNER JOIN product p ON o.product_id = p.product_id
),
SUB_Q AS (
    SELECT month, year, customer_id, name, SUM(price * quantity) AS spend
    FROM CTE
    GROUP BY customer_id, name, month, year
)
SELECT DISTINCT customer_id, name
FROM SUB_Q s1
WHERE EXISTS (
    SELECT 1 FROM SUB_Q s2 WHERE year = 2020 AND month = 6 AND spend >= 100
    AND s1.customer_id = s2.customer_id
) AND EXISTS (
    SELECT 1 FROM SUB_Q s3 WHERE year = 2020 AND month = 7 AND spend >= 100
    AND s1.customer_id = s3.customer_id
)