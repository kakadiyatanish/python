CREATE DATABASE final;
USE final;


CREATE TABLE departments (
    departmentid INT PRIMARY KEY,
    departmentname VARCHAR(100) NOT NULL
);

INSERT INTO departments (departmentID, departmentname) VALUES
(101, 'Computer Science'),
(102, 'Mathematics'),
(103, 'Physics'),
(104, 'Chemistry'),
(105, 'Biology'),
(106, 'Electrical Engineering'),
(107, 'Mechanical Engineering'),
(108, 'Civil Engineering'),
(109, 'Economics'),
(110, 'English Literature');


CREATE TABLE students (
    studentid INT PRIMARY KEY,
    firstname VARCHAR(50) NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    email VARCHAR(100),
    birthdate DATE,
    enrollmentdate DATE
);

INSERT INTO students (studentID, firstname, lastname, email, birthdate, enrollmentdate) VALUES
(1, 'John', 'Doe', 'johndoe@example.com', '2000-04-15', '2018-09-01'),
(2, 'Jane', 'Smith', 'janesmith@example.com', '2001-07-22', '2019-09-01'),
(3, 'Michael', 'Johnson', 'michaelj@example.com', '1999-12-10', '2017-09-01'),
(4, 'Emily', 'Davis', 'emilyd@example.com', '2002-03-08', '2020-09-01'),
(5, 'Daniel', 'Miller', 'danielm@example.com', '2000-11-30', '2018-09-01'),
(6, 'Sarah', 'Wilson', 'sarahw@example.com', '2001-06-18', '2019-09-01'),
(7, 'David', 'Anderson', 'davida@example.com', '1998-09-25', '2016-09-01'),
(8, 'Laura', 'Thomas', 'laurat@example.com', '2002-01-05', '2020-09-01'),
(9, 'James', 'Moore', 'jamesm@example.com', '2000-05-20', '2018-09-01'),
(10, 'Olivia', 'Taylor', 'oliviat@example.com', '2001-10-12', '2019-09-01');


CREATE TABLE courses (
    courseid INT PRIMARY KEY,
    coursename VARCHAR(100) NOT NULL,
    departmentid INT,
    credits INT,
    FOREIGN KEY (departmentid) REFERENCES departments(departmentid)
);

INSERT INTO courses (courseID, courseName, departmentID, credits) VALUES
(11, 'Introduction to Computer Science', 101, 3),
(12, 'Data Structures and Algorithms', 101, 4),
(13, 'Calculus I', 102, 4),
(14, 'General Chemistry', 103, 3),
(15, 'World History', 104, 3),
(16, 'English Literature', 105, 3),
(17, 'Operating Systems', 101, 4),
(18, 'Linear Algebra', 102, 3),
(19, 'Organic Chemistry', 103, 4),
(20, 'Modern European History', 104, 3);


CREATE TABLE instructors (
    instructorid INT PRIMARY KEY,
    firstname VARCHAR(50),
    lastname VARCHAR(50),
    email VARCHAR(100),
    departmentid INT,
    salary DECIMAL(10,2),
    FOREIGN KEY (departmentid) REFERENCES departments(departmentid)
);

INSERT INTO instructors (instructorID, firstname, lastname, email, departmentID, salary) VALUES
(1, 'Alice', 'Johnson', 'alice.johnson@univ.com', 101, 75000.00),
(2, 'Bob', 'Lee', 'bob.lee@univ.com', 102, 68000.00),
(3, 'Priya', 'Das', 'priya.das@univ.com', 103, 72000.00),
(4, 'David', 'Kim', 'david.kim@univ.com', 104, 70000.00),
(5, 'Sara', 'Nguyen', 'sara.nguyen@univ.com', 105, 69000.00),
(6, 'John', 'White', 'john.white@univ.com', 106, 71000.00),
(7, 'Meera', 'Rao', 'meera.rao@univ.com', 107, 73000.00),
(8, 'Elena', 'Moreno', 'elena.moreno@univ.com', 108, 76000.00),
(9, 'James', 'Smith', 'james.smith@univ.com', 109, 67000.00),
(10, 'Amelia', 'Brown', 'amelia.brown@univ.com', 110, 74000.00);


CREATE TABLE enrollments (
    enrollmentid INT PRIMARY KEY,
    studentid INT,
    courseid INT,
    enrollmentdate DATE,
    FOREIGN KEY (studentid) REFERENCES students(studentid),
    FOREIGN KEY (courseid) REFERENCES courses(courseid)
);

INSERT INTO enrollments (enrollmentID, studentID, courseID, enrollmentDate) VALUES
(1, 1, 11, '2018-09-01'),
(2, 2, 12, '2019-09-01'),
(3, 3, 13, '2017-09-01'),
(4, 4, 14, '2020-09-01'),
(5, 5, 15, '2018-09-01'),
(6, 6, 16, '2019-09-01'),
(7, 7, 17, '2016-09-01'),
(8, 8, 18, '2020-09-01'),
(9, 9, 19, '2018-09-01'),
(10, 10, 20, '2019-09-01');




SELECT * FROM students WHERE YEAR(enrollmentdate) >= 2022;

SELECT c.*
FROM courses c
JOIN departments d ON c.departmentid = d.departmentid
WHERE d.departmentname = 'Mathematics'
LIMIT 5;


SELECT courseid, COUNT(studentid) AS student_count
FROM enrollments
GROUP BY courseid
HAVING COUNT(studentid) = 1;



SELECT studentid FROM enrollments
WHERE courseid IN (
    SELECT courseid FROM courses
    WHERE coursename = 'Introduction to SQL' OR coursename = 'Data Structures and Algorithms'
);

SELECT AVG(credits) AS avg_credits FROM courses;


SELECT MAX(salary) AS max_salary FROM instructors WHERE departmentID = 101;


SELECT d.departmentid, d.departmentname, COUNT(DISTINCT e.studentid) AS student_count
FROM departments d
JOIN courses c ON d.departmentid = c.departmentid
JOIN enrollments e ON c.courseid = e.courseid
GROUP BY d.departmentid, d.departmentname;


SELECT s.studentid, c.courseid, c.coursename
FROM students s
JOIN enrollments e ON s.studentid = e.studentid
JOIN courses c ON e.courseid = c.courseid;


SELECT s.studentid, c.courseid, c.coursename
FROM students s
LEFT JOIN enrollments e ON s.studentid = e.studentid
LEFT JOIN courses c ON e.courseid = c.courseid;


SELECT s.studentid, s.firstname, s.lastname
FROM students s
WHERE s.studentid IN (
    SELECT e.studentid
    FROM enrollments e
    WHERE e.courseid IN (
        SELECT courseid
        FROM enrollments
        GROUP BY courseid
        HAVING COUNT(studentid) > 10
    )
);


SELECT studentid, YEAR(enrollmentdate) AS enrollment_year FROM students;


SELECT CONCAT(firstname, ' ', lastname) AS fullname FROM instructors;


SELECT enrollmentid, studentid, courseid, enrollmentdate,
       COUNT(*) OVER (ORDER BY enrollmentdate, enrollmentid ROWS UNBOUNDED PRECEDING) AS running_total
FROM enrollments
ORDER BY enrollmentdate, enrollmentid;