#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void sign_up();
bool log_in();


int main ()
{
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\t\tHR MANAGEMENT OPERATION SYSTEM " << endl;
        cout << "\t\t\t==============================================\n";
        cout << "\t\t\tPress any key to continue.";
        cin.get();
        system("cls");

        int choice;
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tMENU: \n";
        cout << "\t\t\t1. Sign up\n";
        cout << "\t\t\t2. Log in\n";
        cout << "\t\t\t3. Exit\n";
        cout << "\t\t\t==============================================";
        cout << "\n\n\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: 
                sign_up();
                break;

            case 2:
                if (log_in())
                    {
                        cout << "\t\t\tYou are now logged in." << endl;
                        //dito ilalagay yung kay mervs at yas
                        cout << "\t\t\t==============================================\n";
                        cout << "\t\t\tPress any key to return to the main menu.";
                        cin.ignore();
                        cin.get();
                    }
                    break;

            case 3:
                cout << "\t\t\tExiting program. . .";
                cin.get();
                break;
            
            default:
                system("cls");
                cout << "\t\t\t Pleae select from the option given above \n" << endl;
                main();
        }
    }
}

void sign_up()
{
   string username, password;

   while (true)
   {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tCreate username and password: \n";
        cout << "\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        cout << "\t\t\t==============================================";

        if (username.length() >= 8 && password.length() >= 8)
        {
            ofstream f1 ("records.txt", ios::app);
            f1 << username << " "<< password << endl;
            f1.close();

            system("cls");
            cout << "\n\n\t\t\t==============================================\n";
            cout << "\t\t\tRegistration successfull!\n";
            cout << "\t\t\tGoing back to main menu now. . .\n";
            cout << "\t\t\t==============================================";
            cin.ignore();
            cin.get();
            return;
        }
        else
        {
            cout << "\n\t\t\tUsername and password must be at least 8 characters long. Please try again. ";
            cin.ignore();
            cin.get();
        }
   }
}

bool log_in()
{
    string username, password, fileUsername, filePassword;
    bool loggedIn = false;

    system("cls");
    cout << "\n\n\t\t\t==============================================\n";
    cout << "\t\t\tLog in to your account: \n";
    cout << "\t\t\tUsername: ";
    cin >> username;
    cout << "\t\t\tPassword: ";
    cin >> password;
    cout << "\t\t\t==============================================";

    ifstream f1("records.txt");
    while (f1 >> fileUsername >> filePassword)
    {
        if (fileUsername == username && filePassword == password)
        {
            loggedIn = true;
            break;
        }
    }
    f1.close ();

    if (loggedIn)
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tLogin successfull! \n";
        return true;
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tInvalid username or password. Please try again. \n";
        cout << "\t\t\t==============================================\n";
        cin.ignore();
        cin.get();
        return false;
    }

}