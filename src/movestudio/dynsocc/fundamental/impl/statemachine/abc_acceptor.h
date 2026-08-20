/*
 * abc_acceptor.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_ABC_ACCEPTOR_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_ABC_ACCEPTOR_H_

#include "sm.h"

class ABC : public MITSM<int, char, bool>
{
public:
	ABC():MITSM<int,char,bool>(0) {}

	int getNextValues(int currentState, char input, bool& output)
	{
		int nextStt = 0;
		if (currentState ==0 && input=='a')
		{
			nextStt = 1;
			output = true;
		}
		else if (currentState==1 && input=='b')
		{
			nextStt = 2;
			output = true;
		}
		else if (currentState==2 && input=='c')
		{
			nextStt = 0;
			output = true;
		}
		else
		{
			nextStt = 3;
			output = false;
		}

		return nextStt;
	}
};

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_ABC_ACCEPTOR_H_ */
