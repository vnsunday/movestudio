/*
 * CAccumulator.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

// #include <dynsocc/fundamental/impl/statemachine/CAccumulator.h>
#include "CAccumulator.h"

CAccumulator::CAccumulator(double initVal) : MITSM(initVal) {
}

CAccumulator::~CAccumulator() {
}

double CAccumulator::getNextValues(double currentState, double input, double& output)
{
	double new_stt;
	output = currentState + input;
	new_stt = output;

	return new_stt;
}
