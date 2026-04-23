#include <iostream>
#include <cstring>
using namespace std;

class Railway
{
public:
    int trainNumber;
    char trainName[50];    
    char source[50];
    char destination[50];      
    char trainTime[10];
    static int trainCount;

    Railway(int tnum, const char* tname, const char* tsource, const char* des, const char* ttime) 
    {
        trainNumber = tnum;
        strcpy(trainName, tname);
        strcpy(source, tsource);
        strcpy(destination, des);
        strcpy(trainTime, ttime);
        trainCount++;
    }

    ~Railway() 
    {
        trainCount--;
    }

    void TrainDetails()
    {
        cout << "Enter train Number: ";
        cin >> trainNumber;
        cin.ignore(); 
        cout << "Enter train name: ";
        cin.getline(trainName, 50); 
        cout << "Enter source: ";
        cin.getline(source, 50); 
        cout << "Enter destination: ";
        cin.getline(destination, 50); 
        cout << "Enter train time: ";
        cin.getline(trainTime, 10); 
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount() 
    {
        return trainCount;
    }

    int getTrainNumber() 
    {
        return trainNumber;
    }
};

int Railway::trainCount = 0;

class RailwaySystem 
{
private:
    Railway* trains[100]; 
    int totalTrain;

public:
    RailwaySystem() 
    {
        totalTrain = 0;
    }

    void addTrain() 
    {
        if (totalTrain < 100) 
        {
            int tnum;
            char tname[50], source[50], destination[50], ttime[10];

            cout << "Enter train Number: ";
            cin >> tnum;
            cin.ignore();
            cout << "Enter train name: ";
            cin.getline(tname, 50); 
            cout << "Enter source: ";
            cin.getline(source, 50); 
            cout << "Enter destination: ";
            cin.getline(destination, 50);
            cout << "Enter train time: ";
            cin.getline(ttime, 10); 

            trains[totalTrain] = new Railway(tnum, tname, source, destination, ttime);
            totalTrain++;
        } 
        else 
        {
            cout << "Cannot add more trains. Maximum limit reached!" << endl;
        }
    }

    void displayAllTrains() 
    {
        if (totalTrain == 0) 
        {
            cout << "No train records found." << endl;
            return;
        }
        for (int i = 0; i < totalTrain; i++) 
        {
            cout << "\nTrain " << i + 1 << ":" << endl;
            trains[i]->displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) 
    {
        for (int i = 0; i < totalTrain; i++) 
        {
            if (trains[i]->getTrainNumber() == number) 
            {
                cout << "Train found!" << endl;
                trains[i]->displayTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << " not found!" << endl;
    }
};

int main()
{
    RailwaySystem system;
    int n;
    
    do
    {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;

        switch (n)  
        {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3:
                int trainNumber;
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                system.searchTrainByNumber(trainNumber);
                break;
            case 4:
                cout << "Exiting the System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid option." << endl;
                break;
        }
    } while (n != 4); 
    return 0;
}
