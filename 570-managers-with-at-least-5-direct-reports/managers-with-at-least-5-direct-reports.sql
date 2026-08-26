# Write your MySQL query statement below
select manager.name 
from  Employee as manager
join Employee as employee
on manager.id = employee.managerId
group by manager.id,manager.name 
having count(manager.id)>=5;
