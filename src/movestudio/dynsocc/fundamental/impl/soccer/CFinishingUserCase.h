/*
 * CFinishingUserCase.h
 *
 *  Created on: Jan, 05 2019
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_SOCCER_CFINISHINGUSERCASE_H_
#define APP_FUNDAMENTAL_IMPL_SOCCER_CFINISHINGUSERCASE_H_

#include "dynsocc/fundamental/interface/soccer/IPlayer.h"
#include "dynsocc/fundamental/interface/soccer/IUserCase.h"

class CFinishingUserCase : public IUserCase
{
public:
	CFinishingUserCase();
	virtual ~CFinishingUserCase();

    int run();
    int initialize(IPlayer* player1, IPlayer* player2);
};

#endif
