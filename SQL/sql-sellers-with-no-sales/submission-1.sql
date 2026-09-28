-- Write your query below

SELECT seller_name
FROM seller
WHERE seller_id NOT IN (
    SELECT DISTINCT seller_id
    FROM orders
    WHERE EXTRACT(YEAR FROM sale_date) = 2020
)

ORDER by seller_name