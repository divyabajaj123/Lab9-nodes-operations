#include <iostream>
using namespace std;

class DateTime{
    int month, day, year, hour, min, sec;
    public:
    DateTime(int m = 0, int d = 0, int y = 0, int h = 0, int mi = 0, int s = 0)
        : month(m), day(d), year(y), hour(h), min(mi), sec(s) {} // assuming valid values
        
    void print()
    {
        cout << month << "-" << day << "-" << year  << " " << hour << "::" << min << "::" << sec << endl;
    }
};

class Email{
    string sender, receiver;
    DateTime dt;
    string message;

    public:
    Email(string s, string r, DateTime d, string m="This email is empty.")
    {
        sender=s; receiver=r; dt=d; message=m;
    }
    void print()
    {
        cout << "Sender: " << sender << endl;
        cout << "Receiver: " << receiver << endl;
        cout << "Date Time: ";
        dt.print();
        cout << "Message: " << message << endl;
    }

    string getMessage()
    {
        return message;
    }

    string getSender()
    {
        return sender;
    }

    string getReceiver()
    {
        return receiver;
    }
};