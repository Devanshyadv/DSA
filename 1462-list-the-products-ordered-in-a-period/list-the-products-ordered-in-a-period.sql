# Write your MySQL query statement below
WITH CTE AS(
    SELECT product_id, SUM(unit) AS unit 
    FROM Orders WHERE order_date >= '2020-02-01' AND order_date < '2020-03-01' GROUP BY product_id 
    HAVING SUM(unit) >= 100
)
SELECT p.product_name ,c.unit FROM 
Products as p
JOIN CTE as c
ON p.product_id =c.product_id