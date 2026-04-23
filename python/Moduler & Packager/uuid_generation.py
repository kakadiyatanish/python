import uuid
def uuid_generation():
    print("""
Generate Unique Identifiers :
1. Generate UUID1 (based on timestamp and MAC address)
2. Generate UUID4 (random UUID)
3. Back to Main menu
    """)
    user = input("Enter your choice: ")
    match user:
        case "1":
            print("Generated UUID:", uuid.uuid1())
            print("========================================")
        case "2":
            print("Generated UUID:", uuid.uuid4())
            print("========================================")
        case "3":
            return
        case _:
            print("Invalid choice")