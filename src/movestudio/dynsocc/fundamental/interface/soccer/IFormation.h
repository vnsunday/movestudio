/*
 * IFormation.h
 *  Created on: Nov 11, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IFORMATION_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IFORMATION_H_

#include <string>

class IFormation
{
public:
	virtual ~IFormation() {}

    virtual std::string formationName() = 0;
};

#endif /* APP_FUNDAMENTAL_INTERFACE_SOCCER_IFORMATION_H_ */