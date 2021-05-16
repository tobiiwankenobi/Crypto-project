#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include "Cryptocurrency.h"
#include "account.h"


using namespace std;

//getters

string Account::get_login()
{
    return login;
}

string Account::get_password()
{
    return password;
}

string Account::get_name()
{
    return name;
}

string Account::get_surname()
{
    return surname;
}

double Account::get_EUR()
{
    return EUR;
}

double Account::get_BTC()
{
    return BTC;
}

double Account::get_ETH()
{
    return ETH;
}

double Account::get_LTC()
{
    return LTC;
}


//setters
void Account::set_login(string log)
{
    login = log;
}

void Account::set_password(string pass)
{
    password = pass;
}

void Account::set_name(string nam)
{
    name = nam;
}

void Account::set_surname(string srnam)
{
    surname = srnam;
}

void Account::set_EUR(double EU)
{
    EUR = EU;
}

void Account::set_BTC(double BT)
{
    BTC = BT;
}

void Account::set_ETH(double ET)
{
    ETH = ET;
}

void Account::set_LTC(double LT)
{
    LTC = LT;
}

//constructors
Account::Account(string login_, string password_, string name_, string surname_, double Euro, double BTC_, double ETH_, double LTC_)
:login{login_}, password{password_}, name{name_}, surname{surname_}, EUR{Euro}, BTC{BTC_}, ETH{ETH_}, LTC{LTC_}{}

Account::Account()
{};

//methods
void Account::show_balance()
{
    cout<<endl<<"       |YOUR BALANCE|";
    cout<<endl<<" EUR: "<<EUR;
    cout<<endl<<" BTC: "<<BTC;
    cout<<endl<<" ETH: "<<ETH;
    cout<<endl<<" LTC: "<<LTC << endl;
    cout<<endl<<" ...press any key to continue...";
    getch();
    system("cls");
}

void Account::deposit_euro()
{
    double new_eur;
    cout<<endl<<" How much money would you like to deposit?"<<endl<<"EUR: ";
    cin>>new_eur;
    EUR+=new_eur;
    cout<<endl<<" ...press any key to continue...";
    getch();
    system("cls");
}

void Account::buy_crypto(Cryptocurrency* ptr, Bitcoin BTC_, Ethereum ETH_, Litecoin LTC_)
{
    cout << endl << "Current prices:                            " << endl;
    ptr = &BTC_;
    cout << "1. Bitcoin: " << ptr->get_current_value() << " Euro"  << endl;
    ptr = &ETH_;
    cout << "2. Ethereum: " << ptr->get_current_value() << " Euro" << endl;
    ptr = &LTC_;
    cout << "3. Litecoin: " << ptr->get_current_value() << " Euro" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Your current balance: " << EUR << "Euro." << endl;
    cout << "Which cryptocurrency would you like to buy? (Enter 0, if you want to quit)" << endl;
    int choice;
    double amount;
    cin >> choice;
    switch (choice) {
        case 1:
        {
            ptr = &BTC_;
            cout << "You can buy " << EUR/ptr->get_current_value() << " Bitcoin in total." << endl;
            cout << "How much Bitcoin would you like to buy?" << endl;
            cin >> amount;
            if(amount*ptr->get_current_value() <= EUR)
            {
                EUR-=amount*ptr->get_current_value();
                BTC+=amount;
                cout << "You have bought Bitcoin successfully." << endl << endl;
            }
            else cout << "You do not have that much money." << endl << endl;
            break;
        }

        case 2:
        {
            ptr = &ETH_;
            cout << "You can buy " << EUR/ptr->get_current_value() << " Ethereum in total." << endl;
            cout << "How much Ethereum would you like to buy?" << endl;
            cin >> amount;
            if(amount*ptr->get_current_value() <= EUR)
            {
                EUR-=amount*ptr->get_current_value();
                ETH+=amount;
                cout << "You have bought Ethereum successfully." << endl << endl;
            }
            else cout << "You do not have that much money." << endl << endl;
            break;
        }

        case 3:
        {
            ptr = &LTC_;
            cout << "You can buy " << EUR/ptr->get_current_value() << " Litecoin in total." << endl;
            cout << "How much Litecoin would you like to buy?" << endl;
            cin >> amount;
            if(amount*ptr->get_current_value() <= EUR)
            {
                EUR-=amount*ptr->get_current_value();
                LTC+=amount;
                cout << "You have bought Litecoin successfully." << endl << endl;
            }
            else cout << "You do not have that much money." << endl << endl;
            break;
        }

        case 0:
        {
            break;
        }
    }
    cout<<endl<<" ...press any key to continue...";
    getch();
    system("cls");
}

void Account::sell_crypto(Cryptocurrency* ptr, Bitcoin BTC_, Ethereum ETH_, Litecoin LTC_)
{
    cout << endl << "Current prices:                            " << endl;
    ptr = &BTC_;
    cout << "1. Bitcoin: " << ptr->get_current_value() << " Euro"  << endl;
    ptr = &ETH_;
    cout << "2. Ethereum: " << ptr->get_current_value() << " Euro" << endl;
    ptr = &LTC_;
    cout << "3. Litecoin: " << ptr->get_current_value() << " Euro" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Your current balance: "<< endl;
    cout << BTC << " BTC." << endl;
    cout << ETH << " ETH." << endl;
    cout << LTC << " LTC." << endl;
    cout << "Which cryptocurrency would you like to sell? (Enter 0, if you want to quit)" << endl;
    int choice;
    double amount;
    cin >> choice;
    switch (choice) {
        case 1:
        {
            ptr = &BTC_;
            cout << "You can sell your Bitcoin for: " << ptr->get_current_value()*BTC << " Euro" << endl;
            cout << "How much Bitcoin would you like to sell?" << endl;
            cin >> amount;
            if(amount<=BTC)
            {
                BTC-=amount;
                EUR+=amount*ptr->get_current_value();
                cout << "You have sold Bitcoin successfully." << endl;
            }
            else cout << "You do not have that much Bitcoin." << endl;
            break;
        }

        case 2:
        {
            ptr = &ETH_;
            cout << "You can sell your Ethereum for: " << ptr->get_current_value()*ETH << " Euro" << endl;
            cout << "How much Ethereum would you like to sell?" << endl;
            cin >> amount;
            if(amount<=ETH)
            {
                ETH-=amount;
                EUR+=amount*ptr->get_current_value();
                cout << "You have sold Ethereum successfully." << endl;
            }
            else cout << "You do not have that much Ethereum." << endl;
            break;
        }

        case 3:
        {
            ptr = &LTC_;
            cout << "You can sell your Bitcoin for: " << ptr->get_current_value()*LTC << " Euro" << endl;
            cout << "How much Litecoin would you like to sell?" << endl;
            cin >> amount;
            if(amount<=LTC)
            {
                LTC-=amount;
                EUR+=amount*ptr->get_current_value();
                cout << "You have sold Litecoin successfully." << endl;
            }
            else cout << "You do not have that much Litecoin." << endl;
            break;
        }
        case 0:
        {
            break;
        }
    }
    cout<<endl<<" ...press any key to continue...";
    getch();
    system("cls");
}

void Account::send(vector<Account> &Accounts)
{
    cout << "What do you want to send?" << endl;
    cout << "1. Euro" << endl;
    cout << "2. Bitcoin" << endl;
    cout << "3. Ethereum" << endl;
    cout << "4. Litecoin" << endl;
    cout << "5. Nothing" << endl;
    bool found = false;
    int choice;
    int index;
    double amount;
    string login;
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            cout << "Enter username: ";
            cin >> login;
            cout << "How much euro (you can send " << EUR << " in total): ";
            cin >> amount;
            for(int i=1; i<Accounts.size(); i++)
            {
             if(login == Accounts.at(i).get_login())
             {
                 index = i;
                 found = true;
                if (amount<=EUR)
                {
                    EUR-=amount;
                    Accounts.at(index).EUR+=amount;
                    cout << "Money transferred successfully." << endl;
                    break;
                }
                else cout << "You do not have that much money." << endl;
             }
            else if(found == false && i == Accounts.size()-1)
                cout << "There is no such user." << endl;
            }
            break;
        }

        case 2:
        {
            cout << "Enter username: ";
            cin >> login;
            cout << "How much Bitcoin (you can send " << BTC << " in total): ";
            cin >> amount;
            for(int i=1; i<Accounts.size(); i++)
            {
             if(login == Accounts.at(i).get_login())
             {
                 index = i;
                 found = true;
                if (amount<=BTC)
                {
                    BTC-=amount;
                    Accounts.at(index).BTC+=amount;
                    cout << "Bitcoin transferred successfully." << endl;
                }
                else cout << "You do not have that much Bitcoin." << endl;
             }
            else if(found == false && i == Accounts.size()-1)
                cout << "There is no such user." << endl;
            }
            break;
        }

        case 3:
        {
            cout << "Enter username: ";
            cin >> login;
            cout << "How much Ethereum(you can send " << ETH << " in total): ";
            cin >> amount;
            for(int i=1; i<Accounts.size(); i++)
            {
             if(login == Accounts.at(i).get_login())
             {
                 index = i;
                 found = true;
                if (amount<=ETH)
                {
                    ETH-=amount;
                    Accounts.at(index).ETH+=amount;
                    cout << "Ethereum transferred successfully." << endl;
                }
                else cout << "You do not have that much Ethereum." << endl;
             }
            else if(found == false && i == Accounts.size()-1)
                cout << "There is no such user." << endl;
            }
            break;
        }

        case 4:
        {
            cout << "Enter username: ";
            cin >> login;
            cout << "How much Litecoin(you can send " << LTC << " in total): ";
            cin >> amount;
            for(int i=1; i<Accounts.size(); i++)
            {
             if(login == Accounts.at(i).get_login())
             {
                 index = i;
                 found = true;
                if (amount<=LTC)
                {
                    LTC-=amount;
                    Accounts.at(index).LTC+=amount;
                    cout << "Litecoin transferred successfully." << endl;
                }
                else cout << "You do not have that much Litecoin." << endl;
             }
            else if(found == false && i == Accounts.size()-1)
                cout << "There is no such user." << endl;
            }
            break;
        }

        case 5:
        {
            break;
        }
    }
    cout<<endl<<" ...press any key to continue...";
    getch();
    system("cls");
}
