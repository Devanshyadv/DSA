WITH CTE AS (
    SELECT
        account_id,
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            WHEN income > 50000 THEN 'High Salary'
        END AS category
    FROM Accounts
),
Categories AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)
SELECT
    c.category,
    COUNT(t.account_id) AS accounts_count
FROM Categories c
LEFT JOIN CTE t
    ON c.category = t.category
GROUP BY c.category;