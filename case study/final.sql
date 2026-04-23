create database messo;
use messo;
select * from sales_data;

SELECT 
    DATE_FORMAT(Date, '%Y-%m') AS month,
    Region,
    SUM(Total_amount) AS total_sales
FROM sales_data
WHERE Order_status = 'Completed'
GROUP BY month, Region
ORDER BY month, Region;

SELECT 
    Region,
    SUM(CASE WHEN Order_status IN ('Cancelled', 'Returned') THEN 1 END) * 100.0 / COUNT(*) 
        AS cancel_return_percentage
FROM sales_data
GROUP BY Region;

SELECT 
    Region,
    SUM(Total_amount) AS revenue_loss
FROM sales_data
WHERE Order_status IN ('Cancelled', 'Returned')
GROUP BY Region
ORDER BY revenue_loss DESC
LIMIT 3;

SELECT 
    Product_name,
    SUM(Total_amount) AS revenue_loss
FROM sales_data
WHERE Order_status IN ('Cancelled', 'Returned')
GROUP BY Product_name
ORDER BY revenue_loss DESC
LIMIT 3;

SELECT 
    Category,
    AVG(Total_amount) AS avg_order_value
FROM sales_data
WHERE Order_status = 'Completed'
GROUP BY Category;

SELECT 
    Sales_agent,
    SUM(Total_amount) AS total_revenue
FROM sales_data
WHERE Order_status = 'Completed'
GROUP BY Sales_agent
ORDER BY total_revenue;

SELECT 
    Customer_id,
    COUNT(*) AS return_count
FROM sales_data
WHERE Order_status = 'Returned'
GROUP BY Customer_id
HAVING COUNT(*) >= 3
ORDER BY return_count DESC;


