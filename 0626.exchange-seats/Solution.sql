# Write your MySQL query statement below
SELECT 
(
    CASE
    WHEN MOD(s.id, 2) = 1 AND s.id = sc.count THEN s.id
    ELSE s.id - MOD(s.id + 1, 2) + (1 - MOD(s.id + 1, 2))
    END
) AS id, 
s.student AS student
FROM seat s, (SELECT COUNT(*) AS count FROM seat) AS sc
ORDER BY id 
