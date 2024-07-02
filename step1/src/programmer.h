#ifndef __programmer_h__
#define __programmer_h__


#include "job.h"
#include<iostream>

//TODO: split the impl/header

class Programmer : public Job { //requirement b
public: 
    void Work() const override {
        std::cout << "Programmer is coding." << std::endl;
    }

    void TakeBreak() const override {
        std::cout << "Programmer is taking a coffee break." << std::endl;
    }

    void Train() const override {
        std::cout << "Programmer is attending a coding seminar." << std::endl;
    }

    void GetSalary() const override {
        std::cout << "Programmer received salary." << std::endl;
    }
};

#endif