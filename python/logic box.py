print("Welcome to the Pattern Generator and Number Analyzer!")

while True :
    print("Select an option:-")
    print("1. Generate a pattern")
    print("2. Analyze a Range of Numbers")
    print("3. Exiting")

    User = int(input("Enter your choice : "))
    match User :
        case 1 :
            print("Choose a pattern type:-")
            print("1. Right-angle triangle")
            print("2. pyramid")
            print("3. left-angled triangle")
            
            choice = int(input("Enter your Choice :-"))
            rows = int(input("Enter The number of rows for the pattern :- "))
            
            if choice == 1:
    
                for i in range(1, rows + 1):
                    print(" " * (rows - i) + "*" * i)

            elif choice == 2:
   
                for i in range(1, rows + 1):
                    print(" " * (rows - i) + "*" * (2 * i - 1))

            elif choice == 3:
                for i in range(1, rows + 1):
                    print("*" * i)

        case 2 :
            start = int(input("Enter start of the range :"))
            end = int(input("Enter end of the range"))
            count = 0
            for i in range(start,end + 1,1):
                count += i 
                if i % 2 == 0 :
                    print(f"Number {i} is Even")
                else :
                    print(f"Number {i} is Odd")
            print(count)
        case 3 :
            print("Exiting the program. Goodbye!")
            break