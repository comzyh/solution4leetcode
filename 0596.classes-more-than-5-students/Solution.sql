# Write your MySQL query statement below
SELECT co.class FROM(
    SELECT c.class AS class, COUNT(DISTINCT c.student) AS count FROM courses c
    GROUP BY c.class
) co
WHERE co.count >= 5;
