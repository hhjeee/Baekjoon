-- 코드를 작성해주세요
SELECT b.ID, i.FISH_NAME, b.LENGTH
FROM FISH_INFO b JOIN FISH_NAME_INFO i
ON b.FISH_TYPE = i.FISH_TYPE
WHERE (b.FISH_TYPE, b.LENGTH) IN (
    SELECT FISH_TYPE, MAX(LENGTH) as LENGTH
    FROM FISH_INFO 
    GROUP BY FISH_TYPE
)
ORDER BY b.ID ASC
