/*
 * ITeam.h
 *  Created on: Nov 11, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_ITEAM_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_ITEAM_H_

#include <string>

class ITeam
{
public:
	virtual ~ITeam() {}

    virtual int register_Player_Numbers() = 0;
};

#endif /* APP_FUNDAMENTAL_INTERFACE_SOCCER_ITEAM_H_ */