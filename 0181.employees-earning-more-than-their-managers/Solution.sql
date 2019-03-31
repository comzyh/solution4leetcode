# Write your MySQL query statement below
Select e1.Name AS Employee FROM Employee e1 INNER JOIN Employee e2 ON e1.ManagerId = e2.Id Where e1.Salary > e2.Salary
