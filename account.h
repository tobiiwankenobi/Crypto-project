#include <iostream>
#include <vector>
#include "Cryptocurrency.h"
#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

using namespace std;

class Account
{
    //attributes
    string login;
    string password;
    string name;
    string surname;
    double EUR;
    double BTC;
    double ETH;
    double LTC;
    int acc_index;


    public:
    //constructors
        Account();
        Account(string login_, string password_, string name_, string surname_, double Euro, double BTC_, double ETH_, double LTC_);

    //getters
        string get_login();
        string get_password();
        string get_name();
        string get_surname();
        double get_EUR();
        double get_BTC();
        double get_ETH();
        double get_LTC();

    //setters
        void set_login(string log);
        void set_password(string pass);
        void set_name(string nm);
        void set_surname(string srnm);
        void set_EUR(double EU);
        void set_BTC(double BT);
        void set_ETH(double ET);
        void set_LTC(double LT);
        void set_acc_index(int index);

    //methods
        void show_balance();
        void deposit_euro();
        void buy_crypto(Cryptocurrency* ptr, Bitcoin BTC, Ethereum ETH, Litecoin LTC);
        void sell_crypto(Cryptocurrency* ptr, Bitcoin BTC_, Ethereum ETH_, Litecoin LTC_);
        void send(vector<Account> &Accounts);
};


#endif // ACCOUNT_H_INCLUDED
