/*
 * TestUtil.h
 *
 *  Created on: Mar 7, 2018
 *      Author: spider
 */

#ifndef APP_UTIL_TESTUTIL_H_
#define APP_UTIL_TESTUTIL_H_

class TestUtil {
public:
	TestUtil();
	virtual ~TestUtil();

	static int assert(bool b, const char* szMsg);
	
};

#endif /* APP_UTIL_TESTUTIL_H_ */
