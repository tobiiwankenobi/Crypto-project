#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include "windows.h"
#include <string>
#include "manager.h"
#include "account.h"
#include "cryptocurrency.h"
#include "Functions.h"

using namespace std;

Manager::Manager()
{
    //ctor
}

 vector<Account> Manager::initialise_all_accounts()
{
    vector<Account> Accounts;
    vector<string> data;
    string textline;
    fstream file;
    file.open("profiles.txt", ios::in);
    while (getline(file, textline))
        data.emplace_back(textline);
    if(data.size()>0)
    {
    for(int i=0; i<data.size(); i+=8)
    {
        Account Object(data.at(i), data.at(i+1), data.at(i+2), data.at(i+3), stod(data.at(i+4)), stod(data.at(i+5)), stod(data.at(i+6)), stod(data.at(i+7)));
        Accounts.emplace_back(Object);
    }
    }
    else
    {
        Account Object("initial", "initial", "initial", "initial", 0, 0, 0, 0);
        Accounts.emplace_back(Object);
    }
    file.close();
    return Accounts;
}

void Manager::create_account(vector<Account> &Accounts)
{
    system("cls");
    bool occupied_login;
    string login, password, name, surname;
    do{
        occupied_login = false;
        cout << "Enter login: ";
        cin >> login;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your surname: ";
        cin >> surname;

        for(int i=0; i<Accounts.size(); i++)
        {
            if(login==Accounts.at(i).get_login() || password==Accounts.at(i).get_password())
            {
                cout << "This login or password is already occupied. Please choose another one."<< endl;
                cout << " ...press any key to continue...";
                occupied_login = true;
                getch();
                system("cls");
                break;
            }

            else if(occupied_login == false && i == Accounts.size()-1)
            {
                cout << "\nYou have successfully created your account" << endl;
                Account Object(login, password, name, surname, 0, 0, 0, 0);
                Accounts.emplace_back(Object);
                break;
            }
        }
      }while(occupied_login == true);
    cout << endl << " ...press any key to continue...";
    getch();
    system("cls");
}

int Manager::sign_in(vector<Account> &Accounts)
{
    string login, password;
    int logged = -1;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    for(int i=0; i<Accounts.size(); i++)
    {
        if(Accounts.at(i).get_login()==login)
        {
            if (Accounts.at(i).get_password()==password) {
                cout << "\nLogin attempt successful." << endl;
                logged = i;
                break;
            }
            else if(Accounts.at(i).get_password()!=password)
            {
                cout << "\nWrong login or password." << endl;
                logged = -1;
                break;
            }
        }
        else if(i==Accounts.size()-1)
        {
            cout << "\nWrong login or password." << endl;
            logged = -1;
            break;
        }
    }
    Sleep(1000);
    system("cls");
    return logged;
}

void Manager::delete_account(vector<Account> &Accounts)
{
    bool found = true;
    string login, password;
    char choice;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    cout << "Are you sure, that you want to delete this account? The changes are irreversible. y/n" << endl;
    cin >> choice;
    switch (choice) {
        case 'y':
            for(int i=0; i<Accounts.size(); i++)
            {
             if(login == Accounts.at(i).get_login())
             {
                 if(password == Accounts.at(i).get_password())
                 {
                     Accounts.erase(Accounts.begin()+i);
                     cout << "This account has been successfully deleted." << endl;
                     break;
                 }
                 else if(password != Accounts.at(i).get_password())
                 {
                     cout << "Wrong login or password." << endl;
                     break;
                 }
             }
                else if(i == Accounts.size()-1 && Accounts.at(i).get_login() != login)
                    found = false;
            }
            if(found == false)
                cout << "Wrong login or password." << endl;
            break;

        case 'n':
            cout << "Going back to main menu..." << endl << endl;
            break;
    }
    cout << endl << " ...press any key to continue...";
    getch();
    system("cls");
}


void save_all_data(vector<Account> &Accounts)
{
    fstream data_file;
    data_file.open("profiles.txt", ios::out);
    for(int i=0; i<Accounts.size(); i++)
    {
        data_file << Accounts.at(i).get_login();
        data_file << Accounts.at(i).get_password();
        data_file << Accounts.at(i).get_name();
        data_file << Accounts.at(i).get_surname();
        data_file << Accounts.at(i).get_EUR();
        data_file << Accounts.at(i).get_BTC();
        data_file << Accounts.at(i).get_ETH();
        data_file << Accounts.at(i).get_LTC();
    }
    data_file.close();
}

void Manager::print_all_accounts(vector<Account> &Accounts)
{
    for(int i=1; i<Accounts.size(); i++)
    {
        cout << "Account #" << i << endl;
        cout << "-----------------------------" << endl;
        cout << "Login:" << Accounts.at(i).get_login() << endl;
        cout << "Password:" << Accounts.at(i).get_password() << endl;
        cout << "Name:" << Accounts.at(i).get_name() << endl;
        cout << "Surname:" << Accounts.at(i).get_surname() << endl;
        cout << "Euro:" << Accounts.at(i).get_EUR() << endl;
        cout << "Bitcoin:" << Accounts.at(i).get_BTC() << endl;
        cout << "Ethereum:" << Accounts.at(i).get_ETH() << endl;
        cout << "Litecoin:" << Accounts.at(i).get_LTC() << endl;
        cout << "-----------------------------" << endl << endl;
    }
    cout << endl << " ...press any key to continue...";
    getch();
    system("cls");
}

void Manager::run()
{
    fstream file;
    file.open("profiles.txt", ios::out | ios::app);
    file.close();
    int action;
    Bitcoin BTC;
    Ethereum ETH;
    Litecoin LTC;
    Cryptocurrency* ptr;
    ptr = &BTC;
    ptr->assign_current_value(check_BTC());
    ptr = &ETH;
    ptr->assign_current_value(check_ETH());
    ptr = &LTC;
    ptr->assign_current_value(check_LTC());
    vector<Account> Accounts = initialise_all_accounts();
    do{
    cout << " ----------------------------------------------------------------------------- " << endl;
    cout << "|                                                                             |" << endl;
    cout << "|             ***  WELCOME TO THE CRYPTOCURRENCY STOCK SIMULATOR  ***         |" << endl;
    cout << "|                                                                             |" << endl;
    cout << "|             1. Create account                                               |" << endl;
    cout << "|             2. Sign in to an existing account                               |" << endl;
    cout << "|             3. Delete an existing account                                   |" << endl;
    cout << "|             4. Print all accounts                                           |" << endl;
    cout << "|             5. Exit                                                         |" << endl;
    cout << "|                                                                             |" << endl;
    cout << " ----------------------------------------------------------------------------- " << endl << endl;
    cout << "Pick your action and press enter->";
    cin >> action;

    switch (action)
    {
        case 1:
        {
            this->create_account(Accounts);
            break;
        }

        case 2:
        {
            int signed_account = this->sign_in(Accounts);
            do{
            if(signed_account != -1)
            {
                int action_2;
                cout << " ----------------------------------------------------------------------------- " << endl;
                cout << "|                                                                             |" << endl;
                cout << "|             ***  WHAT WOULD YOU LIKE TO DO?  ***                            |" << endl;
                cout << "|                                                                             |" << endl;
                cout << "|             1. Show my balance                                              |" << endl;
                cout << "|             2. Deposit euros                                                |" << endl;
                cout << "|             3. Buy cryptocurrency                                           |" << endl;
                cout << "|             4. Sell cryptocurrency                                          |" << endl;
                cout << "|             5. Send money or cryptocurrency                                 |" << endl;
                cout << "|             6. Log out                                                      |" << endl;
                cout << "|                                                                             |" << endl;
                cout << " ----------------------------------------------------------------------------- " << endl << endl;
                cout << "Pick your action and press enter->";
                cin >> action_2;
                switch (action_2)
                {
                    case 1:
                    {
                        Accounts.at(signed_account).show_balance();
                        break;
                    }

                    case 2:
                    {
                        Accounts.at(signed_account).deposit_euro();
                        break;
                    }

                    case 3:
                    {
                        Accounts.at(signed_account).buy_crypto(ptr, BTC, ETH, LTC);
                        break;
                    }

                    case 4:
                    {
                        Accounts.at(signed_account).sell_crypto(ptr, BTC, ETH, LTC);
                        break;
                    }

                    case 5:
                    {
                        Accounts.at(signed_account).send(Accounts);
                        break;
                    }

                    case 6:
                    {
                        signed_account = -1;
                        cout << endl << " logging out.." << endl;
                        Sleep(800);
                        system("cls");
                        break;
                    }
                    default:
                    {
                        system("cls");
                        cout << endl << " *error* pick number between 1-6" << endl;
                        Sleep(1000);
                        system("cls");
                        break;
                    }
                }
            }
            else break;
            }while(signed_account!=-1);
            break;
        }

        case 3:
        {
            this->delete_account(Accounts);
            break;
        }

        case 4:
        {
            this->print_all_accounts(Accounts);
            break;
        }

        case 5:
        {
            system("cls");
            action = 0;
            remove("profiles.txt");
            file.open("profiles.txt", ios::out | ios::app);
            for(int i = 0; i<Accounts.size(); i++)
            {
            file << Accounts.at(i).get_login() << endl;
            file << Accounts.at(i).get_password() << endl;
            file << Accounts.at(i).get_name() << endl;
            file << Accounts.at(i).get_surname() << endl;
            file << Accounts.at(i).get_EUR() << endl;
            file << Accounts.at(i).get_BTC() << endl;
            file << Accounts.at(i).get_ETH() << endl;
            file << Accounts.at(i).get_LTC() << endl;
            }
            file.close();
            cout << "you have closed Stock Simulator latest version 4.2.0.";
            break;
        }
        default:
            {
            system("cls");
            cout << endl << " *error* pick number between 1-5" <<  endl;
            Sleep(1000);
            system("cls");
            break;
            }
    }
    }while(action!=0);
}
