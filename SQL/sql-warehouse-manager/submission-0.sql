-- Write your query below

SELECT name AS warehouse_name, SUM(
    units * width * length * height
) AS volume
FROM warehouse INNER JOIN products
    ON warehouse.product_id = products.product_id
GROUP BY name