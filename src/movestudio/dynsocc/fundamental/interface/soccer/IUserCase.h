/*
 *  Created on: Jan 05, 2019
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IUSERCASE_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IUSERCASE_H_

#include "IPlayer.h"
#include <string>

class IUserCase
{
public:
	virtual ~IUserCase() {}

    virtual int run() = 0;

    virtual int initialize(IPlayer* player1, IPlayer* player2) = 0;
};

#endif 