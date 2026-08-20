#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "dynsocc/fundamental/impl/statemachine/sm.h"
#include "dynsocc/fundamental/impl/statemachine/base_machine.h"
#include "dynsocc/fundamental/impl/statemachine/MIT_Basic.h"
#include "dynsocc/util/Console.h"
#include "dynsocc/test/state_machine/switcher/CSwitcherTest.h"
#include "dynsocc/test/state_machine/CCompositeTest.h"
#include "dynsocc/fundamental/stdex/struct.hpp"
#include "dynsocc/fundamental/stdex/tree.h"
#include "dynsocc/fundamental/stdex/textview.h"
#include "dynsocc/fundamental/stdex/calendar.h"

using namespace std;
using namespace dynsocc;

int test_machine()
{
	SMDelay2<double> dl(2);
	SMDelay2<double> dl2(3);
	
	SMCascade<double, double> sm_01(&dl, &dl2);
	SMDATA pData01 = NULL;

	SMFeedback<double> sm_02(3, &sm_01);

	//sm_01.step(5);
	//sm_01.step(6);
	//sm_01.step(7);
	double inputs[] = { 5, 10, 15, 20, 25 , 26, 27, 28, 29};
	int inputs_int_[] = { 5, 10, 15, 20, 25 , 26, 27, 28, 29};
	vector<double> v_out;

	sm_01.transduce(inputs, 9, v_out);	
	Console::log(v_out);

	sm_02.transduce(inputs_int_, 9 , v_out);	
	Console::log(v_out);


	SMDelay2<double> delay2(1);
	SMAcummulator<double> sm_accu(1);
	MITSMFeedback<double> sm_fibo((double)1, &sm_accu);	

	sm_fibo.start();
	sm_fibo.transduce(inputs_int_, 9, v_out);

	// sm_accu.start();
	// sm_accu.transduce(inputs, 9, v_out);
	Console::log(v_out);
	return 0;
}

int main(int argc, char const *argv[])
{
	CSwitcherTest switcherTest;
	switcherTest.runTest();

	CCompositeTest compositeTest;
	compositeTest.run();

	dynsocc::test_dvqueue::test();

	int k = 2009;
	printf("TTT %03d\r\n", k);

	// test_adjtree::test();

	vector<int> vcolsize({ 14, 20, 18});
	vector<int> vformat({ DYNSOCC_TEXT_ALIGN_CENTER, DYNSOCC_TEXT_ALIGN_RIGHT, DYNSOCC_TEXT_ALIGN_LEFT});
	vector<string> vcontent({ "Content", "12'880", "Is In At" });

	std::cout << TextView::column_print(vcolsize, vformat, vcontent, '|') << endl;
	std::cout << TextView::table_print(vcolsize, vformat,
		vector<vector<string>>({
			{ "a", "b", "c"},
			{ "a", "b", "c" },
			{ "a", "b", "c" } }), '|') << endl;
	
	Calendar c1;
	c1.build_solar_years(2026, 01, 26, "Monday");
	return 0;
}