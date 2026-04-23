import datetime
import os

filename = "journal.txt"

if os.path.exists(filename):
    print(f"The file '{filename}' already exists.")
else:
    with open(filename, 'x') as file:
        file.write("") 
    print(f"The file '{filename}' was not found, so it has been created.")

def current_time():
    return datetime.datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")

def create_file():
    if not os.path.exists(filename):
        with open(filename, 'x') as file:
            pass
        print(f"The file '{filename}' was not found, so it has been created.")
    else:
        print(f"The file '{filename}' already exists.")

def readfile():
    file = open("journal.txt","r")
    data = file.read()
    return data

def writefile(n):
    file = open("journal.txt","a")
    data = file.write(f"{current_time()} {n}\n")
    return data
def search(keyword):
    file = open("journal.txt","r")
    lines = file.readlines()
    return [line for line in lines if keyword.lower() in line.lower()]

def delete():
        file = open("journal.txt","w")
        data = file.write("")
        return data

print("Welcome to personal journal Manager!")
create_file()

while True:
    
    print("please select an option:")
    print("1. add a new entry")
    print("2. view all entries")
    print("3. search for a entry")
    print("4. delete all entries")
    print("5. exit")
    
    user = int(input("enter your choice:-"))
    
    match user:
        case 1:
            writefile(input("Enter Your journal Entry :\n"))
            print("Entry added successfully.")
            
        case 2:
            content = readfile()
            if content.strip():
                print("\n--- Journal Entries ---\n")
                print(content)
            else:
                print("\n data is empry please enter the data \n")
                
        case 3:
            keyword = input("Enter keyword to search: ")
            results = search(keyword)
            if results:
                print("\n--- Search Results ---\n")
                print("".join(results))
            else:
                print("No matching entries found.")
        case 4:
            confirm = input("Are you sure you want to delete all entries? (y/n): ").lower()
            if confirm == 'y':
                delete()
                print("All entries have been deleted.")
        case 5:
            print("Exiting the program. Goodbye!")
            break
        