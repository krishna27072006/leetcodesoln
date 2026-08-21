# Write your MySQL query statement below

select Visits.customer_id , COUNT(*) AS count_no_trans
from Transactions
right join Visits
on Visits.visit_id=Transactions.visit_id 
where Transactions.transaction_id is null
GROUP BY Visits.customer_id;
