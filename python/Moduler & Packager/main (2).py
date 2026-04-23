import datetime_time_operations
import math_operations
import random_data
import uuid_generation
import file_operations


def explore_module():
    module_name = input("Enter module name to explore: ")
    try:
        print(f"Available Attributes in {module_name} module:\n{dir(module_name)}")
    except ImportError:
        print("Module not found.")


def main():
    while True:
        print("==============================")
        print("Wel-come to Multi-Utility Toolkit")
        print("==============================")        
        print("""
Choose an option:
1. Datetime and Time Operations
2. Mathematical Operations
3. Random Data Generation
4. Generate Unique Identifiers (UUID)
5. File Operations (Custom Module)
6. Explore Module Attributes (dir())
7. Exit
==============================================
        """)
        choice = input("Enter your choice: ")
        match choice:
            case "1":
                datetime_time_operations.datetime_time_operations()
            case "2":
                math_operations.math_operations()
            case "3":
                random_data.random_data()
            case "4":
                uuid_generation.uuid_generation()
            case "5":
                file_operations.file_operations()
            case "6":
                explore_module()
            case "7":
                print("==============================")
                print("Thank you for using the Multi-Utility Toolkit!")
                print("==============================")
                break
            case _:
                print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()