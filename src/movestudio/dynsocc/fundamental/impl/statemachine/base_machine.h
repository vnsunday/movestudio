#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_BASE_MACHINE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_BASE_MACHINE_H_

#include "sm.h"
#include <cassert>

template <typename T>
class SMFeedback : public SMBase<T, int, T>
{
public:
	SMFeedback(T initState_Val, SMCore* pEngine)
	{
        T input;
        assert(pEngine->TypeOfInput() == pEngine->TypeOf_Output());
        assert(pEngine->TypeOf_Output() == SMCoreCouncil::TypeID(input));
		
        _pEng = pEngine;

        this->setStateVal(initState_Val);
	}

    T getNextValues(T current_State, int input, T& out) 
    {
        SMDATA p_Val = (SMDATA)&current_State;
        SMDATA pOutput = (SMDATA)&out;

        _pEng->unsafe_step(p_Val, pOutput);
                
        return out;
    }

	T step(int input)
	{
        T output;
        T current_State = this->myState();
        
        SMDATA p_Val = (SMDATA)&current_State;
        SMDATA pOutput = (SMDATA)&output;

        _pEng->unsafe_step(p_Val, pOutput);

        this->setStateVal(output);
		return output;        
	}
	
private:
	SMCore* _pEng;
};

template<typename T_I, typename T_O>
class SMCascade: public SMBase<int, T_I, T_O>
{
public:
    SMCascade(SMCore*p1, SMCore* p2)
    {
        // assert(p1->TypeOfInput() == T_I)
        // assert(p1->TypeOfOutput()) == p2->TypeOfInPut())
        // assert(p2->TypeOfOutput()) == T_O
        _p1 = p1;
        _p2 = p2;

        T_I input;
        T_O out;
        assert((_p1->TypeOfInput() == SMCoreCouncil::TypeID(input)));
        assert((_p1->TypeOf_Output() == _p2->TypeOfInput()));
        assert((_p2->TypeOf_Output() == SMCoreCouncil::TypeID(out)));
    }
    
    int getNextValues(int current_State, T_I input, T_O& out) 
    {
        /*
        out = current_State;
        
        SMDATA p_Input = (SMDATA)&input;
        SMDATA p_Out = (SMDATA)& out;

        SMDATA pOut1 = _p1->newOutputData();
        _p1->getNextValues(_p1->pointerToState_Data(), p_Input, pOut1);
        _p2->getNextValues(_p2->pointerToState_Data(), pOut1, p_Out);

        _p1->delOutputData(pOut1);
        return input;
        */

       return 0;
    }

    T_O step(T_I input)
	{
		T_O o;

        SMDATA p_Input = (SMDATA)&input;
        SMDATA p_Out1 = _p1->unsafeNewOutputData();
        SMDATA p_Out2_Cast = (SMDATA) &o;

        _p1->unsafe_step(p_Input, p_Out1);
        _p2->unsafe_step(p_Out1, p_Out2_Cast);

        _p1->unsafeDelOutputData(p_Out1);
        
		return o;
	}

protected:
    SMCore* _p1;
    SMCore* _p2;    
};

template<typename T>
class SMDelay2 : public SMBase<T,T,T>
{
public:
    SMDelay2(T initState_Val)
    {
        this->setStateVal(initState_Val);        
    }

    T getNextValues(T current_State, T input, T& out) 
    {
        out = current_State;
        return input;
    }
};

#endif