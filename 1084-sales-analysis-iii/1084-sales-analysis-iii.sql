-- Write your MySQL query statement below
-- Solution for LeetCode 1084: Sales Analysis III
-- Finds the products that were only sold within the exact date range of 2019-01-01 to 2019-03-31.

SELECT p.product_id, p.product_name
FROM Product p
JOIN Sales s
ON p.product_id = s.product_id
GROUP BY p.product_id, p.product_name
HAVING
    MIN(s.sale_date) >= '2019-01-01'
    AND MAX(s.sale_date) <= '2019-03-31';