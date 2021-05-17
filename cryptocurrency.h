#ifndef cryptocurrency_h
#define cryptocurrency_h


#include <iostream>
using namespace std;

class Cryptocurrency
{
public:
    virtual void assign_current_value(double) = 0;
    virtual double get_current_value() = 0;
};

class Bitcoin : public Cryptocurrency
{
    double current_value;
public:
    Bitcoin();
    virtual void assign_current_value(double);
    virtual double get_current_value();

};

class Ethereum : public Cryptocurrency
{
    double current_value;
public:
    Ethereum();
    virtual void assign_current_value(double);
    virtual double get_current_value();


};

class Litecoin : public Cryptocurrency
{
    double current_value;
public:
    Litecoin();
    virtual void assign_current_value(double);
    virtual double get_current_value();
};


#endif
