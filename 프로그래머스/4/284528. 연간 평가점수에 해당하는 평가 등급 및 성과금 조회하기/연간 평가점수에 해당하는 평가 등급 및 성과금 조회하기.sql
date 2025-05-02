-- 코드를 작성해주세요
SELECT e.EMP_NO, e.EMP_NAME, g.GRADE,
    CASE
        WHEN g.GRADE = 'S' THEN e.SAL * 0.2
        WHEN g.GRADE = 'A' THEN e.SAL * 0.15
        WHEN g.GRADE = 'B' THEN e.SAL * 0.1
        ELSE e.SAL * 0
    END as BONUS
FROM HR_EMPLOYEES e JOIN (
    SELECT EMP_NO,
        CASE
            WHEN AVG(SCORE) >= 96 THEN 'S'
            WHEN AVG(SCORE) >= 90 THEN 'A'
            WHEN AVG(SCORE) >= 80 THEN 'B'
            ELSE 'C'
        END as GRADE
    FROM HR_GRADE
    GROUP BY EMP_NO
) g
ON e.EMP_NO = g.EMP_NO
ORDER BY e.EMP_NO ASC