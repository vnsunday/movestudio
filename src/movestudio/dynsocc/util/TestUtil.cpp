/*
 * TestUtil.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: spider
 */

#include <dynsocc/util/TestUtil.h>
#include <stdlib.h>
#include <stdio.h>

TestUtil::TestUtil() {
}

TestUtil::~TestUtil() {
}

int TestUtil::assert(bool b, const char* szMsg)
{
	if (!b)
	{
		printf("%s\r\n", szMsg);
		return 1;
	}
	return 0;
}
