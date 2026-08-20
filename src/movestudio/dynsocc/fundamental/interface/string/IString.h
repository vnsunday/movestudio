/*
 * IBall.h
 *  Created on: Jan 05, 2019
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_STRING_ISTRING_H_
#define APP_FUNDAMENTAL_INTERFACE_STRING_ISTRING_H_

#include <string>

class IString
{
private:
    /* data */
public:
    virtual ~IString() {}
    
    virtual std::string shorten_string(std::string, unsigned int maxlen) = 0;
};


#endif