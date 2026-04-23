create database messo;
use messo;

CREATE TABLE Products (
    productid INT PRIMARY KEY,
    productname VARCHAR(100),
    category_id INT,
    price DECIMAL(10, 2),
    stock_quantity INT,
    added_date DATE,
    FOREIGN KEY (category_id) REFERENCES Categories(categoryid)
);
INSERT INTO Products(productid, productname, category_id, price, stock_quantity, added_date) VALUES
(1, 'Smartphone', 1, 299.99, 100, '2025-08-01'),
(2, 'Laptop', 1, 899.99, 50, '2025-08-01'),
(3, 'T-Shirt', 3, 19.99, 200, '2025-08-02'),
(4, 'Basketball', 6, 29.99, 80, '2025-08-03'),
(5, 'Toy Car', 5, 14.99, 150, '2025-08-04'),
(6, 'Dining Table', 7, 499.99, 10, '2025-08-05'),
(7, 'Lipstick', 8, 9.99, 300, '2025-08-06'),
(8, 'Car Oil', 9, 24.99, 60, '2025-08-07'),
(9, 'Hammer', 10, 15.99, 75, '2025-08-08'),
(10, 'Novel Book', 2, 12.49, 120, '2025-08-09');

CREATE TABLE Categories (
    categoryid INT PRIMARY KEY,
    cate_name VARCHAR(100)
);
INSERT INTO Categories(categoryid, cate_name) VALUES
(1, 'Electronics'), (2, 'Books'), (3, 'Clothing'), (4, 'Groceries'), (5, 'Toys'),
(6, 'Sports'), (7, 'Furniture'), (8, 'Beauty'), (9, 'Automotive'), (10, 'Tools');
select * from Categories;

CREATE TABLE Customers (
    cusid INT PRIMARY KEY,
    cus_name VARCHAR(100),
    email VARCHAR(100),
    phone_number VARCHAR(20),
    address VARCHAR(255),
    registration_date DATE
);
INSERT INTO Customers(cusid, cus_name, email, phone_number, address, registration_date) VALUES
(1, 'Alice', 'alice@example.com', '1234567890', 'New York', '2025-07-01'),
(2, 'Bob', 'bob@example.com', '1234567891', 'Los Angeles', '2025-07-02'),
(3, 'Charlie', 'charlie@example.com', '1234567892', 'Chicago', '2025-07-03'),
(4, 'David', 'david@example.com', '1234567893', 'Houston', '2025-07-04'),
(5, 'Eve', 'eve@example.com', '1234567894', 'Phoenix', '2025-07-05'),
(6, 'Fiona', 'fiona@example.com', '1234567895', 'Philadelphia', '2025-07-06'),
(7, 'George', 'george@example.com', '1234567896', 'San Antonio', '2025-07-07'),
(8, 'Helen', 'helen@example.com', '1234567897', 'San Diego', '2025-07-08'),
(9, 'Ian', 'ian@example.com', '1234567898', 'Dallas', '2025-07-09'),
(10, 'Jane', 'jane@example.com', '1234567899', 'San Jose', '2025-07-10');

CREATE TABLE Orders (
    orderid INT PRIMARY KEY,
    cusid INT,
    order_date DATE,
    total_amount DECIMAL(10, 2),
    cus_status VARCHAR(20),
    FOREIGN KEY (cusid) REFERENCES Customers(cusid)
);
INSERT INTO Orders(orderid, cusid, order_date, total_amount, cus_status) VALUES
(1, 1, '2025-08-01', 319.98, 'Shipped'),
(2, 2, '2025-08-02', 919.98, 'Delivered'),
(3, 3, '2025-08-03', 49.98, 'Pending'),
(4, 4, '2025-08-04', 44.97, 'Cancelled'),
(5, 5, '2025-08-05', 499.99, 'Delivered'),
(6, 6, '2025-08-06', 19.98, 'Shipped'),
(7, 7, '2025-08-07', 24.99, 'Pending'),
(8, 8, '2025-08-08', 15.99, 'Shipped'),
(9, 9, '2025-08-09', 12.49, 'Delivered'),
(10, 10, '2025-08-10', 59.97, 'Cancelled');
select * from  Orders;

CREATE TABLE Order_Items (
    order_item_id INT PRIMARY KEY,
    orderid INT,
    productid INT,
    quantity INT,
    subtotal DECIMAL(10, 2),
    FOREIGN KEY (orderid) REFERENCES Orders(orderid),
    FOREIGN KEY (productid) REFERENCES Products(productid)
);
INSERT INTO Order_Items(order_item_id, orderid, productid, quantity, subtotal) VALUES
(1, 1, 1, 1, 299.99),
(2, 1, 9, 1, 15.99),
(3, 2, 2, 1, 899.99),
(4, 2, 10, 1, 12.49),
(5, 3, 4, 1, 29.99),
(6, 3, 5, 1, 14.99),
(7, 4, 7, 3, 29.97),
(8, 5, 6, 1, 499.99),
(9, 6, 3, 1, 19.99),
(10, 10, 7, 3, 29.97);

CREATE TABLE Payments (
    payment_id INT PRIMARY KEY,
    orderid INT,
    payment_date DATE,
    payment_method VARCHAR(50),
    payment_status VARCHAR(20),
    FOREIGN KEY (orderid) REFERENCES Orders(orderid)
);
INSERT INTO Payments(payment_id, orderid, payment_date, payment_method, payment_status) VALUES
(1, 1, '2025-08-01', 'Credit Card', 'Paid'),
(2, 2, '2025-08-02', 'PayPal', 'Paid'),
(3, 3, '2025-08-03', 'UPI', 'Pending'),
(4, 4, '2025-08-04', 'Credit Card', 'Failed'),
(5, 5, '2025-08-05', 'UPI', 'Paid'),
(6, 6, '2025-08-06', 'Credit Card', 'Paid'),
(7, 7, '2025-08-07', 'PayPal', 'Pending'),
(8, 8, '2025-08-08', 'Credit Card', 'Paid'),
(9, 9, '2025-08-09', 'UPI', 'Paid'),
(10, 10, '2025-08-10', 'Credit Card', 'Failed');

CREATE TABLE Shipping (
    shipping_id INT PRIMARY KEY,
    orderid INT,
    shipping_date DATE,
    delivery_date DATE,
    shipping_status VARCHAR(20),
    FOREIGN KEY (orderid) REFERENCES Orders(orderid)
);
INSERT INTO Shipping(shipping_id, orderid, shipping_date, delivery_date, shipping_status) VALUES
(1, 1, '2025-08-02', '2025-08-05', 'Delivered'),
(2, 2, '2025-08-03', '2025-08-06', 'Delivered'),
(3, 3, '2025-08-04', NULL, 'Dispatched'),
(4, 4, NULL, NULL, 'Cancelled'),
(5, 5, '2025-08-06', '2025-08-09', 'Delivered'),
(6, 6, '2025-08-07', NULL, 'In Transit'),
(7, 7, NULL, NULL, 'Pending'),
(8, 8, '2025-08-09', NULL, 'In Transit'),
(9, 9, '2025-08-10', '2025-08-12', 'Delivered'),
(10, 10, NULL, NULL, 'Cancelled');


INSERT INTO Products (productid int primary key, productname, category_id, price, stock_quantity, added_date)
VALUES (11, 'Wireless Earbuds', 1, 59.99, 120, '2025-08-12');


INSERT INTO Customers (cusid, cus_name, email, phone_number, address, registration_date)
VALUES (11, 'Kevin', 'kevin@example.com', '9876543210', 'Seattle', '2025-08-12');

INSERT INTO Orders (orderid, cusid, order_date, total_amount, cus_status)
VALUES (11, 11, '2025-08-12', 119.98, 'Pending');

INSERT INTO Order_Items (order_item_id, orderid, productid, quantity, subtotal)
VALUES (11, 11, 11, 2, 119.98);

INSERT INTO Payments (payment_id, orderid, payment_date, payment_method, payment_status)
VALUES (11, 11, '2025-08-12', 'Credit Card', 'Pending');

UPDATE Products
SET stock_quantity = stock_quantity - (
    SELECT quantity
    FROM Order_Items
    WHERE Order_Items.productid = Products.productid
      AND Order_Items.orderid = 11
)
WHERE productid IN (
    SELECT productid
    FROM Order_Items
    WHERE orderid = 11
);


DELETE FROM Order_Items
WHERE orderid IN (
    SELECT orderid
    FROM Orders
    WHERE cus_status = 'Cancelled'
      AND order_date < CURDATE() - INTERVAL 30 DAY
);

DELETE FROM Payments
WHERE orderid IN (
    SELECT orderid
    FROM Orders
    WHERE cus_status = 'Cancelled'
      AND order_date < CURDATE() - INTERVAL 30 DAY
);

DELETE FROM Shipping
WHERE orderid IN (
    SELECT orderid
    FROM Orders
    WHERE cus_status = 'Cancelled'
      AND order_date < CURDATE() - INTERVAL 30 DAY
);

DELETE FROM Orders
WHERE cus_status = 'Cancelled'
  AND order_date < CURDATE() - INTERVAL 30 DAY;


SELECT *
FROM Orders
WHERE order_date >= CURDATE() - INTERVAL 6 MONTH;

SELECT productid, productname, price
FROM Products
ORDER BY price DESC
LIMIT 5;

SELECT c.cusid, c.cus_name, COUNT(o.orderid) AS total_orders
FROM Customers c
JOIN Orders o ON c.cusid = o.cusid
GROUP BY c.cusid, c.cus_name
HAVING COUNT(o.orderid) > 3;

SELECT o.orderid, o.cusid, o.order_date, o.cus_status, p.payment_status
FROM Orders o
JOIN Payments p ON o.orderid = p.orderid
WHERE o.cus_status = 'Pending'
  AND p.payment_status = 'Paid';

SELECT productid, productname, stock_quantity
FROM Products
WHERE NOT stock_quantity = 0;

SELECT c.cusid, c.cus_name, c.registration_date, 
       COALESCE(SUM(o.total_amount), 0) AS total_spent
FROM Customers c
LEFT JOIN Orders o ON c.cusid = o.cusid
GROUP BY c.cusid, c.cus_name, c.registration_date
HAVING c.registration_date > '2022-12-31'
   OR SUM(o.total_amount) > 10000;

SELECT *
FROM Products
ORDER BY price DESC;

SELECT c.cusid, c.cus_name, COUNT(o.orderid) AS total_orders
FROM Customers c
LEFT JOIN Orders o ON c.cusid = o.cusid
GROUP BY c.cusid, c.cus_name;

SELECT cat.cate_name, SUM(oi.subtotal) AS total_revenue
FROM Categories cat
JOIN Products p ON cat.categoryid = p.category_id
JOIN Order_Items oi ON p.productid = oi.productid
GROUP BY cat.cate_name;

SELECT SUM(subtotal) AS total_revenue
FROM Order_Items;

SELECT p.productid, p.productname, SUM(oi.quantity) AS total_quantity_sold
FROM Order_Items oi
JOIN Products p ON oi.productid = p.productid
GROUP BY p.productid, p.productname
ORDER BY total_quantity_sold DESC
LIMIT 1;

SELECT AVG(total_amount) AS average_order_value
FROM Orders;

SELECT 
    p.productid,
    p.productname,
    c.cate_name AS category_name,
    p.price,
    p.stock_quantity
FROM Products p
INNER JOIN Categories c ON p.category_id = c.categoryid;

SELECT 
    o.orderid,
    o.order_date,
    o.total_amount,
    o.cus_status,
    c.cus_name,
    c.email,
    c.phone_number
FROM Orders o
LEFT JOIN Customers c ON o.cusid = c.cusid;

SELECT 
    o.orderid,
    o.order_date,
    o.cus_status,
    s.shipping_id,
    s.shipping_status
FROM Orders o
LEFT JOIN Shipping s ON o.orderid = s.orderid
WHERE s.shipping_id IS NULL;

-- Customers with no orders (LEFT JOIN part)
SELECT 
    c.cusid,
    c.cus_name,
    o.orderid
FROM Customers c
LEFT JOIN Orders o ON c.cusid = o.cusid
WHERE o.orderid IS NULL

UNION

-- Orders with no matching customers (RIGHT JOIN part — just in case)
SELECT 
    c.cusid,
    c.cus_name,
    o.orderid
FROM Customers c
RIGHT JOIN Orders o ON c.cusid = o.cusid
WHERE c.cusid IS NULL;

SELECT 
    o.orderid,
    o.order_date,
    o.total_amount,
    c.cus_name,
    c.registration_date
FROM Orders o
JOIN Customers c ON o.cusid = c.cusid
WHERE c.registration_date > '2022-12-31';

SELECT 
    c.cus_name,
    c.email,
    SUM(o.total_amount) AS total_spent
FROM Customers c
JOIN Orders o ON c.cusid = o.cusid
GROUP BY c.cus_name, c.email
ORDER BY total_spent DESC
LIMIT 1;

SELECT 
    p.productid,
    p.productname,
    p.price,
    p.stock_quantity
FROM Products p
LEFT JOIN Order_Items oi ON p.productid = oi.productid
WHERE oi.productid IS NULL;

SELECT MONTH(order_date) AS order_month, COUNT(*) AS orders_per_month
FROM Orders GROUP BY MONTH(order_date);

SELECT 
    orderid, 
    shipping_date, 
    delivery_date, 
    DATEDIFF(delivery_date, shipping_date) AS delivery_time_days
FROM Shipping WHERE shipping_date IS NOT NULL AND delivery_date IS NOT NULL;

SELECT 
    orderid, 
    DATE_FORMAT(order_date, '%d-%m-%Y') AS formatted_order_date
FROM Orders;

SELECT 
    productid,
    UPPER(productname) AS product_name_uppercase
FROM Products;

SELECT 
    cusid,
    TRIM(cus_name) AS trimmed_customer_name
FROM Customers;

SELECT 
    cusid,
    cus_name,
    IFNULL(email, 'Not Provided') AS email_status
FROM Customers;

SELECT 
    c.cusid,
    c.cus_name,
    SUM(o.total_amount) AS total_spent,
    RANK() OVER (ORDER BY SUM(o.total_amount) DESC) AS spending_rank
FROM Customers c
JOIN Orders o ON c.cusid = o.cusid
GROUP BY c.cusid, c.cus_name;

SELECT 
    order_month,
    monthly_revenue,
    SUM(monthly_revenue) OVER (ORDER BY order_month) AS cumulative_revenue
FROM (
    SELECT 
        DATE_FORMAT(order_date, '%Y-%m') AS order_month,
        SUM(total_amount) AS monthly_revenue
    FROM Orders
    GROUP BY DATE_FORMAT(order_date, '%Y-%m')) AS monthly_data;

SELECT 
    orderid,
    order_date,
    COUNT(*) OVER (ORDER BY order_date 
                   ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS running_total_orders
FROM Orders
ORDER BY order_date;

SELECT 
    c.cusid,
    c.cus_name,
    SUM(o.total_amount) AS total_spent,
    CASE
        WHEN SUM(o.total_amount) > 50000 THEN 'Gold'
        WHEN SUM(o.total_amount) BETWEEN 20000 AND 50000 THEN 'Silver'
        ELSE 'Bronze'
    END AS Loyalty_Status
FROM Customers c JOIN Orders o ON c.cusid = o.cusid GROUP BY c.cusid, c.cus_name;

SELECT 
    p.productid,
    p.productname,
    SUM(oi.quantity) AS total_units_sold,
    CASE
        WHEN SUM(oi.quantity) > 500 THEN 'Best Seller'
        WHEN SUM(oi.quantity) BETWEEN 200 AND 500 THEN 'Popular'
        ELSE 'Regular'
    END AS product_category
FROM Products p
LEFT JOIN Order_Items oi 
       ON p.productid = oi.productid
GROUP BY p.productid, p.productname;