#ifndef APP_TEST_STATEMACHINE_CCOMPOSITETEST_H_
#define APP_TEST_STATEMACHINE_CCOMPOSITETEST_H_

#include "dynsocc/fundamental/impl/statemachine/sm_composite.h"
#include <string>

/* 
 * 
 * Use-case / A car factory:
 *   + state = process
 *   + Main-StateMachine's state:
 *      + Init
 *      + Produce wheel
 *      + Produce Engine
 *      + Outsource Car's Furniture     (OutSource)
 *      + Finish
 *   + SubMachine:
 *      + CarFurniture's:
 *          + Init
 *          + Produce
 * 
 */

#define CAR_FACTORY_SM_MSG_PRODUCE_WHEEL 1
#define CAR_FACTORY_SM_MSG_PRODUCE_ENGINE 2
#define CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE 3

#define CAR_FACTORY_STATE_INIT 0
#define CAR_FACTORY_STATE_PRODUCE_WHEEL 1
#define CAR_FACTORY_STATE_PRODUCE_ENGINE 2
#define CAR_FACTORY_STATE_OUTSOURCE_FURNITURE 3
#define CAR_FACTORY_STATE_FINISH 4

#define CAR_FURNITURE_STATE_INIT 0
#define CAR_FURNITURE_STATE_PRODUCE 1
#define CAR_FURNITURE_STATE_FINISH 2

struct CarFactoryState
{
    int stateID;
    int wheelProduced;
    int engineProduced;
    int furnitureProduced;

    CarFactoryState()
    {
        stateID = CAR_FURNITURE_STATE_INIT;
        wheelProduced = 0;
        engineProduced = 0;
        furnitureProduced = 0;
    }

    bool completeProduce()
    {
        return wheelProduced && engineProduced && furnitureProduced;
    }
};

struct CarFactoryMsg
{
    int msgID;
    double data;

    CarFactoryMsg()
    {}
    
    CarFactoryMsg(int theID)
    {
        msgID = theID;
    }
};

struct CarFactoryOut
{
    double data;
    std::string strData;
};

struct CarFurnitureState
{
    int stateID;
};

typedef MITSM<CarFactoryState, CarFactoryMsg, CarFactoryOut> CarSystem;
typedef SMComposite<CarFactoryState, CarFactoryMsg, CarFactoryOut> CarSystemContainer;

class CarFurnitureSM: public CarSystem
{
public:
    CarFurnitureSM();
    CarFactoryState getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output);
};

class CarFactorySM: public CarSystemContainer
{
public:
    CarFactorySM(CarFurnitureSM* pOutsource);
    int isThisACompositeState(CarFactoryState state);    // Return -1: if state is in composite machine; 
    CarFactoryState getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output);
};

class CCompositeTest
{
public:
    CCompositeTest(/* args */);
    virtual ~CCompositeTest();

    void run();
};

#endif