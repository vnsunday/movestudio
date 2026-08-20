/*
 * CNumberTest.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: spider
 */

#include <dynsocc/fundamental/impl/test/CNumberTest.h>
#include <dynsocc/fundamental/impl/number/SNumber.h>
#include <sstream>
#include <string>
#include <fstream>
#include <string.h>
#include "dynsocc/util/TestUtil.h"

using namespace std;

CNumberTest::CNumberTest() {
}

CNumberTest::~CNumberTest() {
}

void CNumberTest::runTest(const char* szFile_Test)
{
	std::ifstream io_Test(szFile_Test);
	std::string sLine;
	std::string sNumber;
	std::string sExpectType;
	string sExpectSign;
	string sExpectNumber;
	string sExpect_Dot;
	string sExpectPower_Sign;
	string sExpectPower_Number;

	bool hasData = false;
	bool checkDataType = false;
	bool check_Sign_ = false;
	bool checkNumber = false;
	bool checkTheDot = false;
	bool checkPowSign_ = false;
	bool checkPowerNumber_ = false;

	int count_Test_ = 0;
	int countFailed = 0;
	int countPassed = 0;

	int injuredTime = 1;			// A trick for testing the last after End-Of-Line
	bool onRunA_Test = false;

	printf("Start testing SNumber from %s\r\n", szFile_Test);
	while (std::getline(io_Test, sLine) || injuredTime > 0)
	{
		sLine.erase(0, sLine.find_first_not_of(' '));       // Left trim
		sLine.erase(0, sLine.find_first_not_of('\t'));       // Left trim

		if (io_Test.eof())	// End of file
		{
			onRunA_Test = true;
			injuredTime--;			// Finish
		}
		else if (sLine == "Test")
		{
			// Finish one 
			onRunA_Test = true;
		}	
		else if (sLine.rfind("Number=", 0) == 0)
		{
			sNumber = sLine.substr(strlen("Number="));
			hasData = true;
		}
		else if (sLine.rfind("ExpectedType=", 0) == 0)
		{
			sExpectType = sLine.substr(strlen("ExpectedType="));
			checkDataType = true;
		}
		else if (sLine.rfind("ExpectedSign=", 0) == 0)
		{
			sExpectSign = sLine.substr(strlen("ExpectedSign="));
			check_Sign_ = true;
		}
		else if (sLine.rfind("ExpectedNum=", 0) == 0)
		{
			sExpectNumber = sLine.substr(strlen("ExpectedNum="));
			checkNumber = true;
		}
		else if (sLine.rfind("ExpectedDot=", 0) == 0)
		{
			sExpect_Dot = sLine.substr(strlen("ExpectedDot="));
			checkTheDot = true;
		}
		else if (sLine.rfind("ExpectedPowerSign=", 0) == 0)
		{
			sExpectPower_Sign = sLine.substr(strlen("ExpectedPowerSign="));
			checkPowSign_ = true;
		}
		else if (sLine.rfind("ExpectedNumPower=", 0) == 0)
		{
			sExpectPower_Number = sLine.substr(strlen("ExpectedNumPower="));
			checkPowerNumber_ = true;
		}

		if (onRunA_Test)
		{
			bool bPass = true;

			if (hasData)
			{
				printf("\tRun testing database %02d: %s \r\n", ++count_Test_, sNumber.c_str());
				SNumber num1(sNumber.c_str());

				if (checkDataType)
				{
					bPass = (TestUtil::assert(num1.rawData().type() == sExpectType, (string("\t\tFailed! Expected Datatype =") + sExpectType + "; Actual=" + num1.rawData().type()).c_str()) == 0) && bPass;
				}

				if (check_Sign_)
				{
					bPass = (TestUtil::assert(num1.rawData().sign() == sExpectSign, (string("\t\tFailed! Expected sign =") + sExpectSign + "; Actual=" + num1.rawData().sign()).c_str()) == 0)  && bPass;
				}

				if (checkNumber)
				{
					bPass = (TestUtil::assert(num1.rawData().number_ == sExpectNumber, (string("\t\tFailed! Expected Number part =") + sExpectNumber + "; Actual=" + num1.rawData().number_).c_str()) == 0) && bPass;
				}

				if (checkTheDot)
				{
					bPass = (TestUtil::assert(num1.rawData().dot_number_ == sExpect_Dot, (string("\t\tFailed! Expected RealPart=") + sExpect_Dot + "; Actual=" + num1.rawData().dot_number_).c_str()) == 0) && bPass;
				}

				if (checkPowSign_)
				{
					bPass = (TestUtil::assert(num1.rawData().sign_power() == sExpectPower_Sign, (string("\t\tFailed! Expected PowerSign=") + sExpectPower_Sign + "; Actual=" + num1.rawData().sign_power()).c_str()) == 0) && bPass;
				}

				if (checkPowerNumber_)
				{
					bPass = (TestUtil::assert(num1.rawData().power_number_ == sExpectPower_Number, (string("\t\tFailed! Expected PowerNumber=") + sExpectPower_Number + "; Actual=" + num1.rawData().power_number_).c_str()) == 0) && bPass;
				}

				countPassed += bPass;
				countFailed += (!bPass);

				hasData = false;
				checkDataType = false;
				check_Sign_ = false;
				checkNumber = false;
				checkTheDot = false;
				checkPowSign_ = false;
				checkPowerNumber_ = false;				
			}
			onRunA_Test = false;
		}
	}

	double dPass_Percent = 100 * (double) countPassed/ (double) count_Test_;
	printf("Finish test. Summary: Total/Passed=%d/%d. Success percent=%f%\r\n", count_Test_, countPassed, dPass_Percent);

	/*
	SNumber num1("+10.23");
	SNumber num2("10.234");
	SNumber num3("1E+23");
	SNumber num4("1E23");

 	numberFailed += TestUtil::assert(num1.rawData().sign_ == 1, "Sign of number1 must +");
 	numberTest++;

 	numberFailed += TestUtil::assert(num1.rawData().number_ == "10", "Sign of number must +");
 	numberTest++;

 	numberFailed += TestUtil::assert(num1.rawData().dot_number_ == "23", "Sign of number1 must +");
 	numberTest++;
 	*/
}
