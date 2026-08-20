/*
 * IEventDispatcher.h
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_IEVENTDISPATCHER_H_
#define APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_IEVENTDISPATCHER_H_

class IEventDispatcher {
public:
	virtual void dispatchEvent(int EVT_CODE, void* data) = 0;
	virtual ~IEventDispatcher() {}
};

#endif /* APP_FUNDAMENTAL_ARCH_EVENTDISPATCH_IEVENTDISPATCHER_H_ */
