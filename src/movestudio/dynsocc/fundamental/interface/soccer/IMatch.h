/*
 * IMatch.h
 *  Created on: Nov 11, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IMATCH_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IMATCH_H_

#include <string>

class IMatch
{
public:
	virtual ~IMatch() {}

    virtual std::string score() = 0;
};

#endif /* APP_FUNDAMENTAL_INTERFACE_SOCCER_IMATCH_H_ */