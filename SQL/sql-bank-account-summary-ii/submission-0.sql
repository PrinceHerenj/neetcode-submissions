-- Write your query below

SELECT name, SUM(amount) AS balance
FROM users INNER JOIN transactions
    ON users.account = transactions.account
GROUP BY name
HAVING SUM(amount) > 10000;