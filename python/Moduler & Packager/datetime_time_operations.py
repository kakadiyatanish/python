import time
import datetime
def datetime_time_operations():
    
    while True:
        print("Datetime and Time Operations:")
        print("1. Display current date and time")
        print("2. Calculate difference between two dates/ times")
        print("3. Format date into custom format")
        print("4. Stopwatch")
        print("5. Countdown Timer")
        print("6. Back to Main Menu")        

        user = input("Enter your choice: ")
        match user:
            case "1":
                print("Current Date and Time:", datetime.datetime.now())
                print("========================================")
            case "2":
                d1 = input("Enter the first date (YYYY-MM-DD): ")
                d2 = input("Enter the second date (YYYY-mm-DD): ")
                date1 = datetime.datetime.strptime(d1, "%Y-%m-%d")
                date2 = datetime.datetime.strptime(d2, "%Y-%m-%d")
                diff = abs((date2 - date1).days)
                print(f"Difference: {diff} days")
                print("========================================")
            case "3":
                now = datetime.datetime.now()
                fmt = input("Enter format (e.g., %d/%m/%Y %H:%M): ")
                print("Formatted date:", now.strftime(fmt))
                print("========================================")
            case "4":
                input("Press Enter to start the stopwatch")
                start = time.time()
                input("Press Enter to stop the stopwatch")
                end = time.time()
                print(f"Elapsed time: {round(end - start, 2)} seconds")
                print("========================================")
            case "5":
                sec = int(input("Enter countdown time in seconds: "))
                while sec:
                    print(sec, end='\r')
                    time.sleep(1)
                    sec -= 1
                print("Time's up!")
                print("========================================")
            case "6":
                break
            case _:
                print("Invalid choice")
