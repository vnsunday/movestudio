/*
 * bino.h
 *
 *  Created on: Dec 25, 2017
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_BINO_BINO_H_
#define APP_FUNDAMENTAL_INTERFACE_BINO_BINO_H_

#include <string>
#define TYPE_INTEGER 1
#define TYPE_REAL 2
#define TYPE_COMPLEX 3


class IType;
class IVal
{
public:
	virtual ~IVal() {}
	virtual int define(std::string, IType* type) = 0;	// Define a variables
};

class IType
{
public:
	virtual ~IType() {}
};

class IExpression
{
public:
	virtual ~IExpression() {}
	virtual int define(std::string, IVal* vals_[]) = 0;
};

class IExpressionEval
{
public:
	virtual ~IExpressionEval() {}
	virtual bool isEqual(IExpression* p1, IExpression* p2) = 0;
	virtual IExpression* parse(std::string)	= 0;
};

class ISummation
{
public:
	virtual ~ISummation() {}
	virtual int define(std::string main_expression) = 0;
};

class IProduction
{
public:
	virtual ~IProduction() {}
};

class IBinomial
{
public:
	virtual ~IBinomial() {}

	virtual void theorem_001() = 0;
	virtual void theorem_002() = 0;
	virtual void theorem_003() = 0;
};

class IBinomialSolver
{
public:
	virtual ~IBinomialSolver() {}
	virtual bool isValidTransform_(IBinomial* b1, IBinomial* b2) = 0;
};

#endif /* APP_FUNDAMENTAL_INTERFACE_BINO_BINO_H_ */