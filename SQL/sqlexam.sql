
CREATE DATABASE  exam1;
USE exam1;

CREATE TABLE customers (
    cus_id INT PRIMARY KEY,
    cus_name VARCHAR(50),
    email VARCHAR(100),
    address VARCHAR(50)
);


INSERT INTO customers (cus_id, cus_name, email, address) VALUES
(1, 'tanish', 'tanish@gmail.com', 'surat'),
(2, 'raju', 'rajesh@ex.com', 'MP'),
(3, 'meet', 'meet@example.com', 'UP'),
(4, 'aadi', 'bob@example.com', 'amreli'),
(5, 'rahul', 'rani@example.com', 'patna');

SELECT * FROM customers;

UPDATE customers
SET address = 'rajula'
WHERE cus_id = 3;

DELETE FROM customers
WHERE cus_id = 3;

INSERT INTO customers (cus_id, cus_name, email, address)
VALUES (3, 'meet', 'meet@gm.com', 'vapi');

SELECT * FROM customers
WHERE cus_name = 'raju';

--------------------------------------------------------------------------

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    cus_id INT,
    order_date DATE,
    totalamount DECIMAL(10,2),
    FOREIGN KEY (cus_id) REFERENCES customers(cus_id)
);

INSERT INTO orders (order_id, cus_id, order_date, totalamount) VALUES
(101, 1, '2025-07-20', 1500),
(102, 2, '2025-07-18', 2300),
(103, 3, '2025-06-30', 1200),
(104, 4, '2025-07-10', 3000),
(105, 5, '2025-07-21', 1800);

SELECT * FROM orders;

SELECT * FROM orders WHERE cus_id = 3;

UPDATE orders SET totalamount = 2500 WHERE order_id = 102;

DELETE FROM orders WHERE order_id = 103;

SELECT * FROM orders
WHERE order_date >= CURDATE() - INTERVAL 30 DAY;

SELECT
  MAX(totalamount) AS HighestOrder,
  MIN(totalamount) AS LowestOrder,
  AVG(totalamount) AS AverageOrder
FROM orders;

--------------------------------------------------------------------------

CREATE TABLE products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(50),
    Price DECIMAL(10,2),
    Stock INT
);

INSERT INTO products (ProductID, ProductName, Price, Stock) VALUES
(1001, 'Laptop', 55000.00, 10),
(1002, 'Mouse', 700.00, 50),
(1003, 'Keyboard', 1500.00, 25),
(1004, 'Monitor', 12000.00, 5),
(1005, 'Webcam', 2500.00, 0);

SELECT * FROM products ORDER BY Price DESC;

UPDATE products SET Price = 12500.00 WHERE ProductID = 1004;

DELETE FROM products WHERE Stock = 0;

SELECT * FROM products WHERE Price BETWEEN 500 AND 20000;

SELECT MAX(Price) AS MostExpensive, MIN(Price) AS Cheapest FROM products;

-------------------------------------------------------------------------------

CREATE TABLE OrderDetails (
    OrderDetailID INT PRIMARY KEY,
    order_id INT,
    ProductID INT,
    Quantity INT,
    SubTotal DECIMAL(10,2),
    FOREIGN KEY (order_id) REFERENCES orders(order_id),
    FOREIGN KEY (ProductID) REFERENCES products(ProductID)
);

INSERT INTO OrderDetails (OrderDetailID, order_id, ProductID, Quantity, SubTotal) VALUES
(111, 101, 1001, 2, 110000.00),  
(112, 102, 1002, 1, 700.00),     
(113, 103, 1003, 3, 4500.00),  
(114, 104, 1004, 1, 12500.00),  
(115, 105, 1005, 1, 2500.00);    

SELECT * FROM OrderDetails WHERE order_id = 101;

SELECT SUM(SubTotal) AS TotalRevenue FROM OrderDetails;

SELECT ProductID, SUM(Quantity) AS TotalOrdered
FROM OrderDetails
GROUP BY ProductID
ORDER BY TotalOrdered DESC
LIMIT 3;

SELECT COUNT(*) AS TimesSold
FROM OrderDetails
WHERE ProductID = 1003;

-------------------------------------------------------------------------------


