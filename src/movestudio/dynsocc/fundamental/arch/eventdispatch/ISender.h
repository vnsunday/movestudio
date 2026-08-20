/*
 * ISender.h
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_ISENDER_H_
#define APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_ISENDER_H_

#include <stdlib.h>

class ISender
{
public:
	virtual void sendEvent(int eventCode, void* data = NULL) = 0;
};


#endif /* APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_ISENDER_H_ */
