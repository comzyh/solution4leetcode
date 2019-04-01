# Write your MySQL query statement below
# SELECT DISTINCT DepartmentId, Salary  FROM Employee e GROUP BY DepartmentId, Salary 
# HAVING (SELECT Count(Id) FROM (
#     SELECT DISTINCT e3.DepartmentId AS DepartmentId, e3.Salary AS Salary FROM Employee e3 GROUP BY DepartmentId, Salary
#     ) e2 WHERE e2.DepartmentId = e.DepartmentId AND e2.Salary >= e.Salary) <= 3
# ORDER BY DepartmentId, Salary DESC


# SELECT e4.DepartmentId AS DepartmentId, MIN(e4.Salary) as Salary
# FROM
# (SELECT e1.DepartmentId AS DepartmentId, e1.Salary AS Salary FROM 
#     (SELECT DISTINCT e3.DepartmentId AS DepartmentId, e3.Salary AS Salary FROM Employee e3 GROUP BY DepartmentId, Salary) e1
# WHERE (SELECT COUNT(e2.DepartmentId) FROM 
#         (SELECT DISTINCT e3.DepartmentId AS DepartmentId, e3.Salary AS Salary FROM Employee e3 GROUP BY DepartmentId, Salary) e2 WHERE e2.DepartmentId = e1.DepartmentId AND e2.Salary >= e1.Salary) <= 3) e4
# GROUP BY e4.DepartmentId
    


SELECT 
d.Name AS Department, 
e1.Name AS Employee,
e1.Salary AS Salary
FROM Employee e1 INNER JOIN Department d ON e1.DepartmentId = d.Id
WHERE 
(SELECT COUNT(e2.DepartmentId) FROM 
        (SELECT DISTINCT e3.DepartmentId AS DepartmentId, e3.Salary AS Salary FROM Employee e3 GROUP BY DepartmentId, Salary) e2 WHERE e2.DepartmentId = e1.DepartmentId AND e2.Salary >= e1.Salary) <= 3
ORDER BY d.Name, e1.Salary DESC
