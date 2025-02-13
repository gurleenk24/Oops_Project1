// Registration & Login Form
// *************************
// 1. Register
// 2. Login
// 3. Exit
// Enter your choice:
// **************************

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Login
{

private:
    string LoginID, Password;

public:
    // constructor (Keeping the values of variables as null)
    Login() : LoginID(""), Password("") {}

    // setter (id)
    void setID(string id)
    {
        LoginID = id;
    }

    // setter (pass)
    void setPW(string PW)
    {
        Password = PW;
    }

    //  getter (id)
    string getID()
    {
        return LoginID;
    }

    // getter(pass)
    string getPW()
    {
        return Password;
    }
};

// Function for choice 1 i.e., Registeration.
void registration(Login log)
{

    system("cls");
    string id, pw;
    cout << "\tEnter login id: ";
    cin >> id;
    log.setID(id);

start:
    cout << "\tEnter a strong password: ";
    cin >> pw;
    if (pw.length() >= 8)
    {
        log.setPW(pw);
    }
    else
    {
        cout << "Password must be at least 8 characters long." << endl;
        goto start;
    }

    // ofstream is used to write data in a file.
    ofstream outfile("D:/Login.txt", ios::app);
    if (!outfile)
    {
        cout << "\tError: File can't be open!" << endl;
    }
    else
    {
        outfile << "\t" << log.getID() << " , " << log.getPW() << endl
                << endl;
        cout << "\tUSER REGISTERED SUCCESSFULLY!!" << endl;
    }
    outfile.close();
    Sleep(3000);
}

// Function for choice 2 i.e., Login.
void login()
{
    system("cls");
    string id, pw;
    cout << "\tEnter login id: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    // ifstream is used to read data from a file.
    ifstream infile("D:/Login.txt");
    if (!infile)
    {
        cout << "\tError: File can't be open!" << endl;
    }
    else
    {
        string line;
        bool found = false;
        while (getline(infile, line))
        {
            stringstream ss;
            ss << line;
            string userID, userPW;
            char delimiter;
            ss >> userID >> delimiter >> userPW;

            if (id == userID && pw == userPW)
            {
                found = true;

                cout << "\tPlease Wait";
                // "Will have a limit of 3."
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "\tWelome to this page, Login Successful!!" << endl;
            }
        }
        if (!found)
        {
            cout << "\tError: Invalid Login ID or Password!!" << endl;
        }
    }

    infile.close();

    Sleep(5000);
}

int main()
{
    Login log;
    bool exit = false;

    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome To The Registration & Login Form" << endl;
        cout << "\t****************************************" << endl;
        cout << "\t1. Registration" << endl;
        cout << "\t2. Login" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        if (val == 1)
        {
            registration(log);
        }

        else if (val == 2)
        {
            login();
        }

        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tGood Luck!!" << endl;
            Sleep(3000);
        }

        Sleep(3000);
    }
    return 0;
}