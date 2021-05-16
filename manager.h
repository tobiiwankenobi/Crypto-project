#include <iostream>
#include <string>
#include "account.h"
#ifndef MANAGER_H
#define MANAGER_H

using namespace std;

class Manager
{
    public:
    Manager();
    int sign_in(vector<Account> &Accounts);
    void create_account(vector<Account> &Accounts);
    void run();
    vector<Account> initialise_all_accounts();
    void delete_account(vector<Account> &Accounts);
    void print_all_accounts(vector<Account> &Accounts);


};

#endif // MANAGER_H
