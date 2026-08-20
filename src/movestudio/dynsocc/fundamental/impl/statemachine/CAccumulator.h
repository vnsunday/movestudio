/*
 * CAccumulator.h
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_

#include "sm.h"

class CAccumulator : public MITSM<double, double, double> {
public:
	CAccumulator(double initVal);
	virtual ~CAccumulator();

	double getNextValues(double currentState, double input, double& output);	// return next state
};

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_ */
