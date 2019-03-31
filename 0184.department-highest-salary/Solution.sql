# Write your MySQL query statement below
SELECT 
    m.Department AS Department,
    e.Name AS Employee,
    e.Salary AS Salary
FROM 
    Employee e
    INNER JOIN
    (
        SELECT d.Name as Department, e.DepartmentId AS DepartmentId, MAX(Salary) AS Salary 
        FROM Employee e INNER JOIN Department d 
        ON e.DepartmentId = d.Id
        GROUP BY e.DepartmentId
    ) m
    ON e.DepartmentId = m.DepartmentId
WHERE e.Salary = m.Salary
