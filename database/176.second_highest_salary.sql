# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary
from 
(select * from Employee
 where Salary != (select max(Salary) from Employee) ) as T
