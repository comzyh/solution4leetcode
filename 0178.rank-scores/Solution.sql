# Write your MySQL query statement below
SELECT 
    Score, 
    (
        SELECT Count(*) FROM (SELECT DISTINCT Score FROM Scores) ds WHERE ds.Score >= s.Score
        
    ) AS Rank
    FROM Scores s ORDER BY Score DESC
    
