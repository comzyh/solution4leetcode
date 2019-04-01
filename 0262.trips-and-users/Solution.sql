# Write your MySQL query statement below
# SELECT
# d.Day AS Day,
# (
#     (SELECT COUNT(Id) FROM Trips t2 INNER JOIN Users u ON t2.Driver_Id = u.Users_Id WHERE t2.Request_at = d.Day AND t2.Status = 'cancelled_by_driver' AND u.Banned = 'No') 
#     +
#     (SELECT COUNT(Id) FROM Trips t2 INNER JOIN Users u ON t2.Client_Id = u.Users_Id WHERE t2.Request_at = d.Day AND t2.Status = 'cancelled_by_client' AND u.Banned = 'No')
# ) / (SELECT COUNT(Id) FROM Trips t2 
#      INNER JOIN Users u1 ON t2.Client_Id = u1.Users_Id
#      INNER JOIN Users u2 ON t2.Driver_Id = u2.Users_Id
#      WHERE t2.Request_at = d.Day AND u1.Banned = 'No' AND u2.Banned = 'No')
# AS 'Cancellation Rate '
# FROM 
# (SELECT DISTINCT t1.Request_at as Day FROM Trips t1) d

# SUM(Case t.Status WHEN 'completed' THEN 0 ELSE 1)


SELECT t.Day AS Day, ROUND(SUM(t.Status) / COUNT(t.Day), 2)AS 'Cancellation Rate'
FROM
(SELECT 
     CASE t2.Status WHEN 'completed' THEN 0 ELSE 1 END AS Status,
     t2.Request_at AS Day
 FROM Trips t2 
     INNER JOIN Users u1 ON t2.Client_Id = u1.Users_Id
     INNER JOIN Users u2 ON t2.Driver_Id = u2.Users_Id
     WHERE u1.Banned = 'No' AND u2.Banned = 'No') t
GROUP BY t.Day
HAVING t.Day >= DATE('2013-10-01') AND t.Day <= DATE('2013-10-03')

