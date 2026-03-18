# Write your MySQL query statement below
SELECT Customer_number 
from Orders 
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;