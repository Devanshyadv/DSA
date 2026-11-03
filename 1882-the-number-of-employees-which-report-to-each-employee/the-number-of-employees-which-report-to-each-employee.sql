# Write your MySQL query statement below
SELECT m.employee_id ,m.name,COUNT(e.employee_id) as reports_count,ROUND(AVG(e.age)) as average_age
FROM Employees as m
JOIN Employees as e 
 ON e.reports_to = m.employee_id
GROUP BY m.employee_id,m.name
Order BY m.employee_id;