class person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def get_display(self):
        return f"Person Name: {self.name}, Person Age: {self.age}"


class employee(person):
    def __init__(self, name, age, E_id, salary):
        super().__init__(name, age)
        self.E_id = E_id  # Fixed variable name
        self.salary = float(salary)

    def get_display(self):
        return f"{super().get_display()}, Employee ID: {self.E_id}, Employee Salary: {self.salary}"


class manager(employee):
    def __init__(self, name, age, E_id, salary, Department):
        super().__init__(name, age, E_id, salary)
        self.Department = Department  # Fixed variable name

    def get_display(self):
        return f"{super().get_display()}, Department: {self.Department}"


person1 = []
Employee1 = []
Manager1 = []

print("--- Python OOP project: Employee Management System ---")

while True:
    print("Choose an option:")
    print("1. Create a Person")
    print("2. Create an Employee")
    print("3. Create a Manager")
    print("4. Show Details")
    print("5. Compare Salaries")
    print("6. Exit")

    user = int(input("Enter your choice: "))

    match user:
        case 1:
            name = input("Enter name: ")
            age = int(input("Enter age: "))
            p = person(name, age)
            person1.append(p)
            print(f"Person created: Name={name}, Age={age}")

        case 2:
            name = input("Enter name: ")
            age = int(input("Enter age: "))
            E_id = input("Enter Employee ID: ")
            salary = float(input("Enter Employee Salary: "))
            e = employee(name, age, E_id, salary)
            Employee1.append(e)
            print(f"employee created with name: {name}, age: {age}, ID:{E_id} and salary:{salary}.")

        case 3:
            name = input("Enter name: ")
            age = int(input("Enter age: "))
            E_id = input("Enter Employee ID: ")
            salary = float(input("Enter Employee Salary: "))
            Department = input("Enter Department: ")
            m = manager(name, age, E_id, salary, Department)
            Manager1.append(m)  # Fixed appending the correct instance
            print(f"manager created with name:{name}, age:{age}, ID:{E_id} , salary:{salary}, Department: {Department} .")
            
        case 4:
            print("Choose details to show:")
            print("1. Person")
            print("2. Employee")
            print("3. Manager")
            
            user_in = int(input("Enter your choice: "))
            match user_in:
                case 1:
                 
                        print(p.get_display())
                case 2:
                        print(e.get_display())
                case 3:
                        print(m.get_display())

        case 5:
            all_emps = Employee1 + Manager1
            if len(all_emps) < 2:
                print("Need at least two employees/managers to compare.")
            else:
                print("\nSelect two people to compare salaries:")
                for i, emp in enumerate(all_emps):
                    print(f"{i + 1}. {emp.name} (Salary: {emp.salary})")

                idx1 = int(input("Enter the number of the first person: ")) - 1
                idx2 = int(input("Enter the number of the second person: ")) - 1

                if 0 <= idx1 < len(all_emps) and 0 <= idx2 < len(all_emps):
                    if all_emps[idx1].salary > all_emps[idx2].salary:
                        print(f"{all_emps[idx1].name} has a higher salary.")
                    elif all_emps[idx1].salary < all_emps[idx2].salary:
                        print(f"{all_emps[idx2].name} has a higher salary.")
                    else:
                        print("Both have equal salaries.")
                else:
                    print("Invalid selection. Please choose valid numbers.")

        case 6:
            print("Exiting the program. Goodbye!")
            break
