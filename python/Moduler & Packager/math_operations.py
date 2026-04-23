import math
def math_operations():
    while True:
        print("Mathematical Operations:")
        print("1. Calculate Factorial")
        print("2. Solve Compound Interest")
        print("3. Trigonometric Calculations")
        print("4. Area of Geometric Shapes")
        print("5. Back to Main Menu")
        
        user = input("Enter your choice: ")
        match user:
            case "1":
                num = int(input("Enter a number: "))
                print("Factorial:", math.factorial(num))
                print("========================================")
            case "2":
                p = float(input("Enter principal amount: "))
                r = float(input("Enter rate of interest (in %): ")) / 100
                t = float(input("Enter time (in years): "))
                ci = p * ((1 + r) ** t)
                print(f"Compound Interest: {ci:.2f}")
                print("========================================")
            case "3":
                angle = float(input("Enter angle in degrees: "))
                rad = math.radians(angle)
                print(f"sin({angle}) = {math.sin(rad):.4f}")
                print(f"cos({angle}) = {math.cos(rad):.4f}")
                print(f"tan({angle}) = {math.tan(rad):.4f}")
                print("========================================")
            case "4":
                print("1. Circle\n2. Rectangle\n3. Triangle")
                shape = input("Choose shape: ")
                match shape:
                    case "1":
                        r = float(input("Enter radius: "))
                        print(f"Area: {math.pi * r * r:.2f}")
                        print("=======================")
                    case "2":
                        l = float(input("Enter length: "))
                        b = float(input("Enter breadth: "))
                        print(f"Area: {l * b}")
                        print("========================")
                    case "3":
                        b = float(input("Enter base: "))
                        h = float(input("Enter height: "))
                        print(f"Area: {0.5 * b * h}")
                        print("=========================")
                    case _:
                        print("Invalid shape")
            case "5":
                break
            case _:
                print("Invalid choice")