-- Write your query below

SELECT left_operand,
    operator,
    right_operand,
    CASE 
        WHEN operator = '>' AND lv.value > rv.value THEN 'true'
        WHEN operator = '<' AND lv.value < rv.value THEN 'true'
        WHEN operator = '=' AND lv.value = rv.value THEN 'true'
        ELSE 'false'
    END AS value
FROM expressions
INNER JOIN variables lv ON left_operand = lv.name
INNER JOIN variables rv ON right_operand = rv.name