/*
 * MIT_Example.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_CORE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_CORE_H_

#include "sm.h"

// class SMAdder : public MITSM<int,  DoubleField<double, double>, double>
// {
// public:
//     SMAdder() : MITSM<int,  DoubleField<double, double>, double>(0)
//     {
//     }
// };

#define DATA void*

class SMCore 
{
public:
    virtual ~SMCore() {}

    virtual DATA next(DATA input) = 0;
    virtual DATA convertStateToData() = 0;

    virtual int typeOfState() = 0;
    virtual int typeOfInput() = 0;
    virtual int typeOf_Output() = 0;
};


class SMEx : public SMCore
{
public:
    // virtual DATA next(DATA input)   = 0;

    void Test() 
    {
        printf("Test\r\n");
    }
};

class SMEx2 : public SMEx
{
public:
    void Test2()
    {
        printf("Test2\r\n");
    }

    DATA next(DATA input)
    {
        printf("Next function of SMEx2\r\n");
        return NULL;
    }

    template<typename T> 
    T next_T(T t)
    {

        return ;
    }
};

#endif