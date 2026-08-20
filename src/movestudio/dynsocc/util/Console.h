/*
 * Console.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_UTIL_CONSOLE_H_
#define APP_UTIL_CONSOLE_H_

#include <iostream>
#include <vector>

class Console
{
public:
	template<class T>
	static void log(T t)
	{
		std::cout << t << std::endl;
	}

	template<class T>
	static void log(std::vector<T> v)
	{
		for (int i=0;i<v.size();i++)
		{
			if (i>0)
			{
				std::cout << " ";
			}
			std::cout << v[i];
		}

		std::cout << std::endl;
	}

	static void format_number_with_quotes(char szbuff)
	{
		return;
	}
};



#endif /* APP_UTIL_CONSOLE_H_ */
