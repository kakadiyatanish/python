def display(*args):
    return min(args), max(args), sum(args), sum(args) / len(args)

print("Welcome to the Data Analyzer and Transformer Program")

user_list = []

while True:
    print("\nMain Menu:")
    print("1. Input data")
    print("2. Display Data Summary (Built-in-functions)")
    print("3. Calculate factorial (Recursion)")
    print("4. Filter Data by threshold (Lambda function)")
    print("5. Sort Data")
    print("6. Display Dataset Statistics")
    print("7. Exit program")
    
  
    user = int(input("Please enter your choice: "))

    match user:
        case 1:
            user_input = input("Enter data for a 1D array (separated by spaces): ")
            user_list = [int(x) for x in user_input.split()]
            print("Data has been stored successfully!")
            
        case 2:
            if not user_list:
                print("No data available. Please input data first.")
                continue
            print("Data Summary:")
            print(f" - Total elements: {len(user_list)}")
            print(f" - Minimum value: {min(user_list)}")
            print(f" - Maximum value: {max(user_list)}")
            print(f" - Sum of all values: {sum(user_list)}")
            print(f" - Average value: {sum(user_list)/len(user_list)}")
        
        case 3:
            User_fac = int(input("Enter a number to calculate its factorial: "))
            if User_fac < 0:
                print("Factorial is not defined for negative numbers.")
            else:
                def factorial(n):
                    if n == 0 or n == 1:
                        return 1
                    return n * factorial(n - 1)
                print(f"The factorial of {User_fac} is {factorial(User_fac)}")

        case 4:
            if not user_list:
                print("No data available. Please input data first.")
                continue
            user_thre = int(input("Enter a threshold value: "))
            my_above_list = list(filter(lambda x: x > user_thre, user_list))
            print(f"Numbers Above Threshold: {my_above_list}")
        
        case 5:
            if not user_list:
                print("No data available. Please input data first.")
                continue
            print("Choose sorting option:")
            print("1. Ascending")
            print("2. Descending")
            user_sort = int(input("Enter your choice: "))
            if user_sort == 1:
                print(sorted(user_list))
            else:
                print(sorted(user_list, reverse=True))
        
        case 6:
            if not user_list:
                print("No data available. Please input data first.")
                continue
            minimum, maximum, sum1, average = display(*user_list)
            print("Dataset Statistics:")
            print(f"Minimum Value: {minimum}")
            print(f"Maximum Value: {maximum}")
            print(f"Sum of all values: {sum1}")
            print(f"Average: {average}")
        
        case 7:
            print("Thank you for using the Data Analyzer and Transformer Program. Goodbye!")
            break
        
        case _:
            print("Invalid choice. Please select a valid option.")
