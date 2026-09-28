-- Write your query below

WITH ranked_scores_per_student AS (
    SELECT student_id, exam_id, score, RANK() OVER (
        PARTITION BY student_id ORDER BY score DESC, exam_id
    ) AS rnk
    FROM exam_results
)
SELECT student_id, exam_id, score
FROM ranked_scores_per_student
WHERE rnk = 1
ORDER BY student_id