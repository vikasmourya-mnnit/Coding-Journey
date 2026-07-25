# Write your MySQL query statement below
SELECT e1.name
FROM Employee e1
JOIN (
    SELECT e2.managerId 
    FROM Employee e2
    GROUP BY e2.managerId
    HAVING count(e2.managerId)>=5
    
) e2
ON e1.id =e2.managerId;

