#include "Cryptocurrency.h"
#include <iostream>



void Bitcoin::assign_current_value(double x)
{
    current_value = x;
}

void Ethereum::assign_current_value(double x)
{
    current_value = x;
}

void Litecoin::assign_current_value(double x)
{
    current_value = x;
}

double Bitcoin::get_current_value()
{
    return current_value;
}

double Ethereum::get_current_value()
{
    return current_value;
}

double Litecoin::get_current_value()
{
    return current_value;
}


Bitcoin::Bitcoin()
    :current_value{0}
{
        cout << "Initialising Bitcoin" << endl;
}

Ethereum::Ethereum()
    :current_value{0}
{
        cout << "Initialising Ethereum" << endl;
}

Litecoin::Litecoin()
    :current_value{0}
{
        cout << "Initialising Litecoin" << endl;
}
