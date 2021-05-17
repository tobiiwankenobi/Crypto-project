#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

double check_BTC()
{
    double btc_val;
    srand(time(NULL));
    btc_val = rand()%3500+7700;
    return btc_val;
}

double check_ETH()
{
    double eth_val;
    srand(time(NULL));
    eth_val = rand()%50+205;
    return eth_val;
}

double check_LTC()
{
    double ltc_val;
    srand(time(NULL));
    ltc_val = rand()%60+110;
    return ltc_val;
}

void print_current_value(Cryptocurrency *x)
{
    cout << x->get_current_value() << endl;
}
