#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class PersonalAssistent
{
    public:
        void start();
    private:
        void openApp(string prompt);
        void filehandling();
        void showtime();
        void calculate();
        template <typename T>
        void calculateTemplate();
};
void PersonalAssistent :: openApp(string prompt)
{
    transform(prompt.begin(),prompt.end(),prompt.begin(), :: tolower);
    if(prompt == "open chatgpt")
    {
        system("start https://chatgpt.com/");
    }
    else if(prompt == "open youtube")
    {
        system("start https://www.youtube.com/");
    }
    else if(prompt == "open chrome")
    {
        system("start chrome");
    }
    else if(prompt == "open calculator")
    {
        system("start calc");
    }
    else 
    {
        cout << "Äpplication not found" << endl;
    }
}
template <typename T>
void PersonalAssistent :: calculateTemplate()
{
    T a,b;
    char op;
    cout << "Enter two numbers for calculation (+,-,*,/) like (5+8): ";
    cin >> a >> op >> b;
    switch(op)
    {
        case '+':
        cout << "Addition of " << a << " and " << b << " is: " << a + b;
        break;
        case '-':
        cout << "Subtraction of " << a << " and " << b << " is: " << a - b;
        break;
        case '*':
        cout << "Multiplication of "<< a << " and " << b << " is: " << a * b;
        break;
        case '/':
        if(b != 0)
        {
            cout << "Division of " << a << " and " << b << " is: " << a / b << endl;
        }
        else 
        {
            cout << "Not divisible by 0";
        }
        break;
        default:
        cout << "Invalid operation!" << endl;
    }
    cin.ignore();
}
void PersonalAssistent :: calculate() 
{
    int choice;
    cout << "Choose data type:\n";
    cout << "1. int" << endl;
    cout << "2. float" << endl;
    cout << "3. double" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
        case 1:
            calculateTemplate<int>();
            break;
        case 2:
            calculateTemplate<float>();
            break;
        case 3:
            calculateTemplate<double>();
            break;
        default:
            cout << "Invalid choice!\n";
    }
    cin.ignore();
}
void PersonalAssistent :: showtime()
{
    time_t now = time(0);
    cout << "Current date & time: " << ctime(&now);
}
void PersonalAssistent :: filehandling()
{
    ofstream file("notes.txt" , ios::app);
    string note;
    cin.ignore();
    getline(cin,note);
    file << note << endl;
    file.close();
    cout << "Note saved succesfully" << endl;
}
void PersonalAssistent :: start()
{
    string command;
    cout << "*****************\nPersonal Assistent\n*****************" << endl;
    cout << "Commands: " << endl;
    cout << "-open chatgpt" << endl;
    cout << "-open chrome" << endl;
    cout << "-open youtube" << endl;
    cout << "-open calculator" << endl;
    cout << "-calculate (+,-,*,/)" << endl;
    cout << "-show time" << endl;
    cout << "-write note" << endl;
    cout << "-exit (To exit the personal assistent)" << endl;
    while(true)
    {
        cout << "\n>";
        getline(cin, command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        if(command == "exit")
            break;
        else if(command.find("open") != string::npos)
            openApp(command);
        else if(command == "calculate")
            calculate();
        else if(command == "show time")
            showtime();
        else if(command == "write note")
            filehandling();
        else 
            cout << "Unknown Command!" << endl;
    }
    cout << "Goodbye" << endl;
}
int main()
{
    PersonalAssistent assistent;
    assistent.start();
    return 0;
}