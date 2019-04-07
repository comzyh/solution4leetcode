# Write your MySQL query statement below
SELECT s.id AS id, s.visit_date AS visit_date, s.people AS people
FROM stadium s
WHERE 
    s.id IN
    (SELECT a.id AS id
    FROM stadium a, stadium b, stadium c
    WHERE a.people >= 100 AND b.id = a.id + 1 AND b.people >= 100 AND c.id = a.id + 2 AND c.people >= 100)
    OR 
    s.id IN
    (SELECT a.id + 1 AS id 
    FROM stadium a, stadium b, stadium c
    WHERE a.people >= 100 AND b.id = a.id + 1 AND b.people >= 100 AND c.id = a.id + 2 AND c.people >= 100)
    OR
    s.id IN
    (SELECT a.id + 2 AS id
    FROM stadium a, stadium b, stadium c
    WHERE a.people >= 100 AND b.id = a.id + 1 AND b.people >= 100 AND c.id = a.id + 2 AND c.people >= 100)
    
