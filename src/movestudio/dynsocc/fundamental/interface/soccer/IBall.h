/*
 * IBall.h
 *  Created on: Jan 05, 2019
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IBALL_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IBALL_H_

#include <string>

class IBall
{
public:
	virtual ~IBall() {}
    virtual int construct(double radius) = 0;   // In meter
};

#endif /* APP_FUNDAMENTAL_INTERFACE_SOCCER_IFORMATION_H_ */