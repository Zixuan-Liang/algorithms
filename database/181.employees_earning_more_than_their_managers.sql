# Write your MySQL query statement below
select T1.Name as Employee
from 
(Employee T1 join Employee T2
 on T1.ManagerId = T2.Id)
where T1.Salary > T2.Salary
