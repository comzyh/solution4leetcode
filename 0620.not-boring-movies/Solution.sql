# Write your MySQL query statement below
SELECT c.* FROM cinema c
WHERE MOD(c.id, 2) = 1 AND description != 'boring'
ORDER BY c.rating DESC
