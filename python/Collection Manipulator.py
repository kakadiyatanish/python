student_data = []

while True:
    print("\nSelect an option:")
    print("1. Add student")
    print("2. Display all students")
    print("3. Update student information")
    print("4. Delete student")
    print("5. Display subjects offered")
    print("6. Exit")

    try:
        user = int(input("Enter your choice: "))
    except ValueError:
        print("Invalid input! Please enter a number.\n")
        continue

    match user:
        case 1:
            student = []
            print("Enter student details:")
            student.append(int(input("Student ID: ")))
            student.append(input("Name: "))
            student.append(input("Age: "))
            student.append(input("Grade: "))
            student.append(input("Date of Birth (yyyy-mm-dd): "))
            student.append(input("Subjects (comma-separated): "))
            student_data.append(student)
            print("Student added successfully!\n")

        case 2:
            if not student_data:
                print("No students to display.\n")
            else:
                for s in student_data:
                    print(f"\nStudent ID: {s[0]}")
                    print(f"Name: {s[1]}")
                    print(f"Age: {s[2]}")
                    print(f"Grade: {s[3]}")
                    print(f"Date of Birth: {s[4]}")
                    print(f"Subjects: {s[5]}\n")

        case 3:
            sid = int(input("Enter the student ID to update: "))
            found = False
            for student in student_data:
                if student[0] == sid:
                    print("1. Update Age")
                    print("2. Update Subjects")
                    choice = input("Choose an option: ")
                    if choice == "1":
                        student[2] = input("Enter new age: ")
                    elif choice == "2":
                        student[5] = input("Enter new subjects (comma-separated): ")
                    print("Student information updated.")
                    found = True
                    break
            if not found:
                print("Student ID not found.")

        case 4:
            sid = int(input("Enter Student ID to delete: "))
            for i, s in enumerate(student_data):
                if s[0] == sid:
                    student_data.pop(i)
                    print("Student deleted successfully.\n")
                    break
            else:
                print("Student ID not found.\n")

        case 5:
            subjects = set()
            for s in student_data:
                subjects.update(map(str.strip, s[5].split(",")))
            print("Subjects Offered:", ", ".join(sorted(subjects)) + "\n")

        case 6:
            print("Exiting program.")
            break

        case _:
            print("Invalid input!\n")
