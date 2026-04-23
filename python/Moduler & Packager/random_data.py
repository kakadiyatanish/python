import random
def random_data():
    while True:
        print("Random Data Generation:")
        print("1. Generate Random Number")
        print("2. Generate Random List")
        print("3. Create Random Password")
        print("4. Generate Random OTP")
        print("5. Back to Main menu")
        user = input("Enter your choice: ")
        
        match user:
            case "1":
                print("Random Number:", random.randint(1, 100))
                print("========================================")
            case "2":
                print("Random List:", random.sample(range(1, 100), 5))
                print("========================================")
            case "3":
                length = int(input("Enter password length: "))
                chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"
                pwd = "".join(random.choices(chars, k=length))
                print("Generated Password:", pwd)
                print("========================================")
            case "4":
                otp = ''.join(random.choices("0123456789", k=6))
                print("Generated OTP:", otp)
                print("========================================")
            case "5":
                break
            case _:
                print("Invalid choice")