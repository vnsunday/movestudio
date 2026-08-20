
#ifndef APP_TEST_STATEMACHINE_SWITCHER_CSWITCHERTEST_H_
#define APP_TEST_STATEMACHINE_SWITCHER_CSWITCHERTEST_H_

#include  "dynsocc/fundamental/impl/statemachine/sm_switcher.h"

/* 
 * StateMachine do the discrete function:
 *  input d (double)
 *      if d < 0 return d * d
 *      if d >= 0 return d + d
 */

class  SMSubSquare : public MITSM<double, double, double>
{
public:
    virtual double getNextValues(double currentState, double input, double& output)
    {
        output = input * input;
		return currentState;
    }
};

class  SMSubMul2 : public MITSM<double, double, double>
{
public:
    virtual double getNextValues(double currentState, double input, double& output)
    {
        output = 2 * input;
		return currentState;
    }
};

class SwicherDiscrete : public SMSwitcher<double, double, double>
{
public: 
    SwicherDiscrete(SMSubSquare* p1, SMSubMul2* p2)
    {
        addSwitcher(p1);
        addSwitcher(p2);
    }

    virtual int navigation(double incomingMsg, int& processedIndex)
    {
        processedIndex = incomingMsg < 0 ? 0 : 1;
        return 0;
    }
};

class CSwitcherTest
{
public:
    void runTest();
};

#endif // !1
