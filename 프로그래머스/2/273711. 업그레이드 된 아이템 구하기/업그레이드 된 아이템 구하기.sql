-- 코드를 작성해주세요
SELECT i.ITEM_ID, i.ITEM_NAME, i.RARITY
FROM ITEM_INFO i JOIN ITEM_TREE t
ON i.ITEM_ID = t.ITEM_ID
AND t.PARENT_ITEM_ID IN (
    SELECT i.ITEM_ID
    FROM ITEM_INFO i JOIN ITEM_TREE t
    ON i.ITEM_ID = t.ITEM_ID
    WHERE i.RARITY = 'RARE'
)
ORDER BY i.ITEM_ID DESC