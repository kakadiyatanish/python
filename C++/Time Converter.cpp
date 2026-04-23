#include <iostream>
using namespace std;

class TimeConverter 
{
public:
    int hours, minutes, seconds;

    TimeConverter(int totalSeconds) 
    {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << seconds << endl;
    }

    void timetos() 
    {
        int a, b, c, d;
        cout << "Enter Hours: ";
        cin >> a;
        cout << "Enter Minutes: ";
        cin >> b;
        cout << "Enter Seconds: ";
        cin >> c;

        d = (c + (b * 60) + (a * 3600));
        cout << "Total seconds: " << d << endl;
    }
};

int main()
{
    int choice;
    cout << "Enter 0 for seconds to Time" << endl;
    cout << "Enter 1 for Time to seconds" << endl;
    cout << "Enter Your choice: ";
    cin >> choice;

    if (choice == 0) 
    {
        int totalSeconds;
        cout << "Enter seconds: ";
        cin >> totalSeconds;
        TimeConverter time(totalSeconds);
    } 
    else if (choice == 1) 
    {
        TimeConverter time(0);  
        
        time.timetos();  
        
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
