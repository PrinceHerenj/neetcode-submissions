-- Write your query below
WITH exam_scores AS
(
    SELECT exam_id, MIN(score) AS mins , MAX(score) AS maxs
    FROM exam
    GROUP BY exam_id
),
ITM_QUERY AS (
    SELECT DISTINCT student_id
    FROM exam 
        JOIN exam_scores
        ON exam_scores.exam_id = exam.exam_id
    WHERE exam.score = maxs OR exam.score = mins
)

SELECT student.student_id, student.student_name
FROM student
WHERE student.student_id IN (SELECT student_id FROM exam)
    AND student.student_id NOT IN (SELECT student_id FROM ITM_QUERY)
ORDER BY student.student_id