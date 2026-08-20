/*
 * sm.h
 *
 *  Created on: Feb 01, 2019
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMSWITCHER_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMSWITCHER_H_

#include "sm.h"
#include <vector>

template<typename  T_S, typename T_I, typename T_O>
class  SMSwitcher : public MITSM<T_S, T_I, T_O>
{
private:
    std::vector<MITSM<T_S, T_I, T_O>* >  _vSwitcher;
    int _index_Active;

protected:    
    MITSM<T_S, T_I, T_O>* _activeMachine()
    {
        if (_index_Active >= 0 && _index_Active < _vSwitcher.size())
        {
            return _vSwitcher[_index_Active];
        }
        else
        {
            return NULL;
        }
    }

    void _setActiveMachine(int newIndex)
    {
        if (newIndex >= 0 && newIndex < _vSwitcher.size())
        {
            _index_Active = newIndex;
        }
        else 
        {
            _index_Active = -1;
        }
    }
public:
    SMSwitcher()    
    {
        _index_Active = -1;
        _vSwitcher.clear();
    }

    int addSwitcher(MITSM<T_S, T_I, T_O>* pSM, bool isActive = true )
    {
        _vSwitcher.push_back(pSM);

        if (isActive)
        {
            _index_Active = _vSwitcher.size() - 1;
        }

		return 0;
    }

    virtual int navigation(T_I incomingMsg, int& processedIndex) = 0;

    virtual T_O step(T_I msg)
    {
        int index_Switcher = 0;
        if (navigation(msg, index_Switcher) == 0) // Success
        {
            return  _vSwitcher[index_Switcher]->step(msg);
        }
        else 
        {
            throw  "Invalid";
        }
    }

    virtual T_S getNextValues(T_S currentState, T_I input, T_O& output)
    {
        int index_Switcher;
        if (navigation(input, index_Switcher) == 0) // Success
        {
            return  _vSwitcher[index_Switcher]->getNextValues(currentState, input, output);
        }
        else 
        {
            throw  "Invalid";
        }
    }
};

#endif