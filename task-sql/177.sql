Create table If Not Exists Employee (id int, salary int)
Truncate table Employee
insert into Employee (id, salary) values ('1', '100')
insert into Employee (id, salary) values ('2', '200')
insert into Employee (id, salary) values ('3', '300')

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE offset_val INT;
    SET offset_val = N-1;
    RETURN (
            select IFNULL((select distinct(Employee.salary) from Employee
                           order by Employee.salary DESC
                           limit 1 offset offset_val),null)
        );
END