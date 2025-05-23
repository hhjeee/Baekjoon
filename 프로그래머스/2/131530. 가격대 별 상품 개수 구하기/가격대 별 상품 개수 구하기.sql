-- 코드를 입력하세요
SELECT 
    CASE
        WHEN PRICE DIV 10000 != 0 THEN CONCAT(PRICE DIV 10000, '0000')
        ELSE 0
    END as PRICE_GROUP, COUNT(*) as PRODUCTS
FROM PRODUCT
GROUP BY PRICE_GROUP
ORDER BY PRICE_GROUP ASC