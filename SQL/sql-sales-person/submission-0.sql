-- Write your query below

SELECT name
FROM sales_person 
WHERE sales_id NOT IN
    (SELECT sales_id
    FROM orders INNER JOIN company
        ON orders.com_id = company.com_id
    WHERE name = 'CRIMSON')