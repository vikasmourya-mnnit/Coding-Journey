# Write your MySQL query statement below
-- //DAY 15

SELECT * 
FROM Cinema c
WHERE c.id%2=1 && c.description!='boring'
ORDER BY rating DESC;