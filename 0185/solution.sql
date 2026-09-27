WITH ranked AS (
    SELECT
        e.name AS Employee,
        e.salary,
        e.departmentId,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS salary_rank
    FROM Employee AS e
)
SELECT
    d.name AS Department,
    r.Employee,
    r.salary AS Salary
FROM ranked AS r
JOIN Department AS d
    ON d.id = r.departmentId
WHERE r.salary_rank <= 3;
