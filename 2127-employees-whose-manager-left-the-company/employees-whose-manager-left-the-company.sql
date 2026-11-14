# Write your MySQL query statement below
SELECT m.employee_id
FROM Employees as m
LEFT JOIN Employees as e
ON m.manager_id=e.employee_id
where m.salary < 30000
AND e.employee_id IS NULL
AND m.manager_id IS NOT NULL
ORDER BY employee_id