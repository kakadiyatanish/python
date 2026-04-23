
CREATE DATABASE IF NOT EXISTS data_trans;
USE data_trans;

CREATE TABLE IF NOT EXISTS customers (
    CustomerID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(50),
    RegistrationDate DATE
);

INSERT INTO customers (CustomerID, FirstName, LastName, Email, RegistrationDate) VALUES
(1, 'tanish', 'kakadiya', 'tkb@email.com', '2022-03-15'),
(2, 'vasu', 'ramani', 'vasu@email.com', '2021-11-02');

CREATE TABLE IF NOT EXISTS orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    OrderDate DATE,
    TotalAmount DECIMAL(10,2),
    FOREIGN KEY (CustomerID) REFERENCES customers(CustomerID)
);

INSERT INTO orders (OrderID, CustomerID, OrderDate, TotalAmount) VALUES
(101, 1, '2023-07-01', 150.50),
(102, 2, '2023-07-03', 200.75);

CREATE TABLE IF NOT EXISTS employees (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Department VARCHAR(50),
    HireDate DATE,
    Salary DECIMAL(10,2)
);

INSERT INTO employees (EmployeeID, FirstName, LastName, Department, HireDate, Salary) VALUES
(1, 'aadi', 'savliya', 'Sales', '2020-01-15', 50000.00),
(2, 'rani', 'Lee', 'HR', '2021-03-20', 55000.00);

SELECT * 
FROM orders 
INNER JOIN customers ON orders.CustomerID = customers.CustomerID;

SELECT * 
FROM customers 
LEFT JOIN orders ON customers.CustomerID = orders.CustomerID;

SELECT * 
FROM customers 
RIGHT JOIN orders ON customers.CustomerID = orders.CustomerID;

SELECT * 
FROM customers 
LEFT JOIN orders ON customers.CustomerID = orders.CustomerID
UNION
SELECT * 
FROM customers 
RIGHT JOIN orders ON customers.CustomerID = orders.CustomerID;

SELECT CustomerID, TotalAmount 
FROM orders 
WHERE TotalAmount > (SELECT AVG(TotalAmount) FROM orders);

SELECT EmployeeID 
FROM employees 
WHERE Salary > (SELECT AVG(Salary) FROM employees);

SELECT CustomerID, OrderID, YEAR(OrderDate) AS year_of_order 
FROM orders;

SELECT CustomerID, OrderID, MONTH(OrderDate) AS month_of_order 
FROM orders;

SELECT DATEDIFF('2025-07-27', OrderDate) AS Days_Between 
FROM orders;

SELECT DATE_FORMAT(OrderDate, '%d-%m-%y') AS FormattedDate 
FROM orders;

SELECT CONCAT(FirstName, ' ', LastName) AS FullName 
FROM customers;

SELECT REPLACE(FirstName, 'tanish', 'savliya') AS ReplacedName 
FROM customers;

SELECT UPPER(FirstName) AS Uppercase, LOWER(LastName) AS Lowercase 
FROM customers;

SELECT TRIM(BOTH ' ' FROM Email) AS TrimmedEmail 
FROM customers;

SELECT *, 
       SUM(TotalAmount) OVER (ORDER BY OrderDate) AS RunningTotal 
FROM orders;

SELECT *, 
       RANK() OVER (ORDER BY TotalAmount DESC) AS Ranking 
FROM orders;

SELECT *, 
       CASE 
           WHEN TotalAmount > 180 THEN '10% off' 
           ELSE 'No Offer' 
       END AS Offer 
FROM orders;

SELECT *, 
       CASE 
           WHEN Salary > 50000 THEN 'High' 
           WHEN Salary <= 50000 THEN 'Medium' 
           ELSE 'Low' 
       END AS Salary_Category 
FROM employees;
