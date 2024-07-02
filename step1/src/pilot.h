#ifndef __pilot_h__
#define __pilot_h__

#include "job.h"
#include<iostream>

class Pilot : public Job { // requirement c
public:
    //requirement d
    void Work() const override {
        std::cout << "Pilot is flying." << std::endl;
    }

    void TakeBreak() const override {
        std::cout << "Pilot is taking a rest." << std::endl;
    }

    void Train() const override {
        std::cout << "Pilot is attending a safety briefing." << std::endl;
    }

    void GetSalary() const override {
        std::cout << "Pilot received salary." << std::endl;
    }
};

#endif