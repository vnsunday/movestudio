/*
 * IPlayer.h
 *  Created on: Nov 11, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IPLAYER_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IPLAYER_H_

#include <string>
#include <vector>

class IPlayer
{
public:
	virtual ~IPlayer() {}

    virtual std::string displayName() = 0;
    virtual int positions(std::vector<int>&) = 0;
    virtual int technique_ability() = 0;

    virtual int kick() = 0;
};

#endif /* APP_FUNDAMENTAL_INTERFACE_SOCCER_IPLAYER_H_ */