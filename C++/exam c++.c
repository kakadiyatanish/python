#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
    string title;
    string genre;
    int releasedYear;

    void display() 
    {
        cout << "Title: " << title << ", Genre: " << genre << ", Year: " << releasedYear << endl;
    }
};

class BankAccount 
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int accNum, string owner, double bal)
    {
        accountNumber = accNum;
        ownerName = owner;
        balance = bal;
    }

    void credit(double amount) 
    {
        balance += amount;
    }

    void debit(double amount) 
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void displayBalance() 
    {
        cout << "Account Number: " << accountNumber
             << ", Owner: " << ownerName
             << ", Balance: " << balance << endl;
    }
};

int main() 
{
    
    Movie m1;
    cout << "Enter movie title: ";
    getline(cin, m1.title);
    cout << "Enter movie genre: ";
    getline(cin, m1.genre);
    cout << "Enter release year: ";
    cin >> m1.releasedYear;
    m1.display();

    
    cin.ignore();

    
    int accNum;
    string owner;
    double bal;
    cout << "\nEnter account number: ";
    cin >> accNum;
    cin.ignore(); 
    cout << "Enter owner's name: ";
    getline(cin, owner);
    cout << "Enter initial balance: ";
    cin >> bal;

    BankAccount acc(accNum, owner, bal);
    acc.displayBalance();

   
    double creditAmt, debitAmt;
    cout << "\nEnter amount to credit: ";
    cin >> creditAmt;
    acc.credit(creditAmt);

    cout << "Enter amount to debit: ";
    cin >> debitAmt;
    acc.debit(debitAmt);

    acc.displayBalance();

    return 0;
}

----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int accNum, string owner, double bal)
    {
        accountNumber = accNum;
        ownerName = owner;
        balance = bal;
    }

    void credit(double amount)
    {
        if (amount > 0) 
        {
            balance += amount;
            cout << "Credited: " << amount << endl;
        }
        else 
        {
            cout << "Invalid credit amount." << endl;
        }
    }

    void debit(double amount) 
    {
        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            cout << "Debited: " << amount << endl;
        } 
        else 
        {
            cout << "Invalid or insufficient balance." << endl;
        }
    }

    void displayBalance() const 
    {
        cout << "Account Number: " << accountNumber
             << ", Owner: " << ownerName
             << ", Balance: " << balance << endl;
    }
};

int main() 
{
    int accNum;
    string owner;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cin.ignore();

    cout << "Enter Owner Name: ";
    getline(cin, owner);

    cout << "Enter Initial Balance: ";
    cin >> bal;

    BankAccount acc1(accNum, owner, bal);

    acc1.displayBalance();

    double creditAmount, debitAmount;

    cout << "Enter amount to credit: ";
    cin >> creditAmount;
    acc1.credit(creditAmount);

    cout << "Enter amount to debit: ";
    cin >> debitAmount;
    acc1.debit(debitAmount);

    acc1.displayBalance();

    return 0;
}

----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
private:
    string model;
    double speed; 

public:
    void setDetails(string m, double s)
    {
        model = m;
        speed = s;
    }

    string getModel() const
    {
        return model;
    }

    double getSpeed() const
    {
        return speed;
    }

    double calculateTime(double distance) const
    {
        if (speed <= 0) 
        {
            cout << "Invalid speed!" << endl;
            return 0;
        }
        return distance / speed;
    }
};

class Car : public Vehicle
{
   
};

class Bike : public Vehicle
{
   
};

int main()
{
    Car myCar;
    Bike myBike;
    string carModel, bikeModel;
    double carSpeed, bikeSpeed, distance;

    
    cout << "Enter Car model: ";
    getline(cin, carModel);
    cout << "Enter Car speed (km/h): ";
    cin >> carSpeed;


    cin.ignore();

    
    cout << "Enter Bike model: ";
    getline(cin, bikeModel);
    cout << "Enter Bike speed (km/h): ";
    cin >> bikeSpeed;

   
    cout << "Enter distance to travel (km): ";
    cin >> distance;

    myCar.setDetails(carModel, carSpeed);
    myBike.setDetails(bikeModel, bikeSpeed);

    cout << "Car (" << myCar.getModel() << ") Time to cover " << distance
         << " km: " << myCar.calculateTime(distance) << " hours" << endl;

    cout << "Bike (" << myBike.getModel() << ") Time to cover " << distance
         << " km: " << myBike.calculateTime(distance) << " hours" << endl;

    return 0;
}

----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
protected:
    string model;
    double speed;

public:
    void setDetails(string m, double s) 
    {
        model = m;
        speed = s;
    }

    virtual void displayDetails() 
    {
        cout << "Vehicle Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle 
{
public:
    void displayDetails() override 
    {
        cout << "[Car] Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle 
{
public:
    void displayDetails() override
    {
        cout << "[Bike] Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() 
{
    Vehicle* vehicles[2];

    string carModel, bikeModel;
    double carSpeed, bikeSpeed;

   
    cout << "Enter car model: ";
    getline(cin, carModel);
    cout << "Enter car speed (in km/h): ";
    cin >> carSpeed;
    cin.ignore(); 

    Car* myCar = new Car();
    myCar->setDetails(carModel, carSpeed);
    vehicles[0] = myCar;

   
    cout << "Enter bike model: ";
    getline(cin, bikeModel);
    cout << "Enter bike speed (in km/h): ";
    cin >> bikeSpeed;

    Bike* myBike = new Bike();
    myBike->setDetails(bikeModel, bikeSpeed);
    vehicles[1] = myBike;

    for (int i = 0; i < 2; ++i)
    {
        vehicles[i]->displayDetails();
    }

    delete myCar;
    delete myBike;

    return 0;
}

----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class BankAccount 
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int accNum = 0, string owner = "", double bal = 0.0) 
    {
        accountNumber = accNum;
        ownerName = owner;
        balance = bal;
    }

    void display() const 
    {
        cout << "Account Number: " << accountNumber
             << ", Owner: " << ownerName
             << ", Balance: " << balance << endl;
    }

    double operator+(const BankAccount& other) const 
    {
        return this->balance + other.balance;
    }
};

int main() 
{
    int accNum1, accNum2;
    string owner1, owner2;
    double bal1, bal2;

    cout << "Enter details for Account 1:" << endl;
    cout << "Account Number: ";
    cin >> accNum1;
    cin.ignore(); 
    cout << "Owner Name: ";
    getline(cin, owner1);
    cout << "Balance: ";
    cin >> bal1;

    cout << "\nEnter details for Account 2:" << endl;
    cout << "Account Number: ";
    cin >> accNum2;
    cin.ignore();
    cout << "Owner Name: ";
    getline(cin, owner2);
    cout << "Balance: ";
    cin >> bal2;

    BankAccount acc1(accNum1, owner1, bal1);
    BankAccount acc2(accNum2, owner2, bal2);

    cout << "\nAccount Details:\n";
    acc1.display();
    acc2.display();

    double totalBalance = acc1 + acc2;
    cout << "Total Balance (acc1 + acc2):  " << totalBalance << endl;

    return 0;
}

----------------------------------------------------------------------------------

#include <iostream>
#include <stdexcept>
using namespace std;

class MathOperations 
{
public:
    double divide(double a, double b) 
    {
        if (b == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }
        return a / b;
    }
};

int main() 
{
    MathOperations math;
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    try 
    {
        double result = math.divide(num1, num2);
        cout << "Result of division: " << result << endl;
    } catch (const exception& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


----------------------------------------------------------------------------------
#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
     virtual double Area() const = 0;
     virtual void Draw() const = 0;
     virtual ~Shape() {}
      };

 class Circle : public Shape 
 {
 private:
     double radius;

 public:
     Circle(double r) : radius(r) {}

     double Area() const override 
     {
        return M_PI * radius * radius;
     }

    void Draw() const override 
    {
        cout<<"Circle ";
    }
 };

 class Rectangle : public Shape 
 {
 private:
    double width, height;

 public:
     Rectangle(double w, double h) : width(w), height(h) {}

     double Area() const override
     {
         return width * height;
    }

    void Draw() const override 
    {
      cout << "Rectangle ";
   }
 };

 int main() 
 {
     double radius, width, height;
     cout << "Enter radius: ";
     cin >> radius;

     cout << "Enter width: ";
     cin >> width;

    cout << "Enter height: ";
    cin >> height;

     Shape* shapes[2];
     shapes[0] = new Circle(radius);
     shapes[1] = new Rectangle(width, height);

   for (int i = 0; i < 2; ++i)
   {
        shapes[i]->Draw();
        cout << "Area: " << shapes[i]->Area() << endl;
     }
     return 0;
 }
 
 ----------------------------------------------------------------------------------