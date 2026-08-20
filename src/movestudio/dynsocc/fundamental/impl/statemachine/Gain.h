/*
 * Gain.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_GAIN_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_GAIN_H_

#include "sm.h"

template<class T>
class Gain : public MITSM<T,T,T>
{
public:
	Gain(T initValue): MITSM<T,T,T>(initValue)
	{
	}

	T getNextValues(T currentState, T input, T& output)
	{
		output = currentState * input;;

		return currentState;
	}
};


#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_GAIN_H_ */
