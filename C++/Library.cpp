#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Abstract Base Class
class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    // Setters
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    // Virtual functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    // Virtual destructor
    virtual ~LibraryItem() {}
};

// Derived Class - Book
class Book : public LibraryItem {
private:
    string ISBN;

public:
    Book(string title, string author, string dueDate, string isbn) {
        if (isbn.length() != 13)
            throw invalid_argument("Invalid ISBN format. Must be 13 characters.");
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        ISBN = isbn;
    }

    void checkOut() override {
        cout << "Book \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "Book \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "\n[Book]\nTitle: " << getTitle()
             << "\nAuthor: " << getAuthor()
             << "\nDue Date: " << getDueDate()
             << "\nISBN: " << ISBN << endl;
    }
};

// Derived Class - DVD
class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string title, string author, string dueDate, int duration) {
        if (duration <= 0)
            throw invalid_argument("Duration must be positive.");
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        this->duration = duration;
    }

    void checkOut() override {
        cout << "DVD \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "DVD \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "\n[DVD]\nTitle: " << getTitle()
             << "\nDirector: " << getAuthor()
             << "\nDue Date: " << getDueDate()
             << "\nDuration: " << duration << " minutes\n";
    }
};

// Derived Class - Magazine
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int issueNumber) {
        if (issueNumber <= 0)
            throw invalid_argument("Issue number must be positive.");
        setTitle(title);
        setAuthor(author);
        setDueDate(dueDate);
        this->issueNumber = issueNumber;
    }

    void checkOut() override {
        cout << "Magazine \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "Magazine \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "\n[Magazine]\nTitle: " << getTitle()
             << "\nEditor: " << getAuthor()
             << "\nDue Date: " << getDueDate()
             << "\nIssue No: " << issueNumber << endl;
    }
};

// Main Menu
int main() {
    const int MAX_ITEMS = 100;
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        try {
            if (choice == 1 && itemCount < MAX_ITEMS) {
                string title, author, dueDate, isbn;
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter Due Date: "; getline(cin, dueDate);
                cout << "Enter ISBN (13 digits): "; getline(cin, isbn);
                libraryItems[itemCount++] = new Book(title, author, dueDate, isbn);
                cout << "Book added successfully.\n";

            } else if (choice == 2 && itemCount < MAX_ITEMS) {
                string title, author, dueDate;
                int duration;
                cout << "Enter DVD Title: "; getline(cin, title);
                cout << "Enter Director: "; getline(cin, author);
                cout << "Enter Due Date: "; getline(cin, dueDate);
                cout << "Enter Duration (minutes): "; cin >> duration; cin.ignore();
                libraryItems[itemCount++] = new DVD(title, author, dueDate, duration);
                cout << "DVD added successfully.\n";

            } else if (choice == 3 && itemCount < MAX_ITEMS) {
                string title, author, dueDate;
                int issueNumber;
                cout << "Enter Magazine Title: "; getline(cin, title);
                cout << "Enter Editor: "; getline(cin, author);
                cout << "Enter Due Date: "; getline(cin, dueDate);
                cout << "Enter Issue Number: "; cin >> issueNumber; cin.ignore();
                libraryItems[itemCount++] = new Magazine(title, author, dueDate, issueNumber);
                cout << "Magazine added successfully.\n";

            } else if (choice == 4) {
                for (int i = 0; i < itemCount; i++) {
                    libraryItems[i]->displayDetails();
                }

            } else if (choice == 5) {
                int index;
                cout << "Enter item index to check out (0 to " << itemCount - 1 << "): ";
                cin >> index; cin.ignore();
                if (index >= 0 && index < itemCount) {
                    libraryItems[index]->checkOut();
                } else {
                    cout << "Invalid index.\n";
                }

            } else if (choice == 6) {
                int index;
                cout << "Enter item index to return (0 to " << itemCount - 1 << "): ";
                cin >> index; cin.ignore();
                if (index >= 0 && index < itemCount) {
                    libraryItems[index]->returnItem();
                } else {
                    cout << "Invalid index.\n";
                }
            } else if (choice == 0) {
                cout << "Exiting...\n";
            } else {
                cout << "Invalid choice or max items reached.\n";
            }

        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    // Memory cleanup
    for (int i = 0; i < itemCount; i++) {
        delete libraryItems[i];
    }

    return 0;
}