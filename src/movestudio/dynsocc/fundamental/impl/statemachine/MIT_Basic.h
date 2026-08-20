#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_BASIC_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_BASIC_H_

#include "sm.h"

template <typename T>
class SMAcummulator: public MITSM<T,T,T>
{
public:
    SMAcummulator(T init_StateVal) : MITSM<T,T,T>(init_StateVal)
    {}

    T getNextValues(T currentState, T input, T& output)
    {
        T new_Stt = input;
        output = input + currentState;
        return new_Stt;
    }
};

#endif