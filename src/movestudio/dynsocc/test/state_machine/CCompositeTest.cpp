#include "CCompositeTest.h"
#include "dynsocc/util/Console.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std; 

CarFurnitureSM::CarFurnitureSM()
{}

CarFactoryState CarFurnitureSM::getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output)
{
    char szBuff[30];
    sprintf(szBuff, "%d", rand());

    output.strData = "New-Furniture=";
    output.strData += szBuff;
    return currentState;
}

CarFactorySM::CarFactorySM(CarFurnitureSM* pOutsource)
                            :CarSystemContainer(std::vector<CarSystem*>{pOutsource})
{}

int CarFactorySM::isThisACompositeState(CarFactoryState state)
{
    if (state.stateID == CAR_FACTORY_STATE_OUTSOURCE_FURNITURE)
    {
        return 0;       // Return the index of Furniture machine
    }
    else
    {
        return -1;
    }
}

CarFactoryState CarFactorySM::getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output)
{
    char szBuff[30];
    CarFactoryState newState = currentState;
    
    if (currentState.stateID == CAR_FACTORY_STATE_INIT)
    {
        if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_ENGINE)
        {
            sprintf(szBuff, "%d", rand());
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_ENGINE;
            newState.engineProduced = 1;
            output.strData = "Produce-EngineID=";
            output.strData += szBuff;
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_WHEEL)
        {
            sprintf(szBuff, "%d", rand());

            newState.stateID = CAR_FACTORY_STATE_PRODUCE_WHEEL;
            newState.wheelProduced = 1;
            output.strData = "New-WheelID=";
            output.strData += szBuff;
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE)
        {
            newState.stateID = CAR_FACTORY_STATE_OUTSOURCE_FURNITURE;
            // Entering sub-machine
            newState.furnitureProduced = 1;
            output.strData = "";    // Nil - Only change to Submachine
        }
    }
    else if (currentState.stateID == CAR_FACTORY_STATE_FINISH)
    {
        // Do Nothing
    }
    else
    {
        if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_ENGINE)
        {
            if (state.completeProduce())
            {
                newState.stateID = CAR_FACTORY_STATE_FINISH;    
            }
            else
            {
                sprintf(szBuff, "%d", rand());

                newState.stateID = CAR_FACTORY_STATE_PRODUCE_ENGINE;
                newState.engineProduced = 1;
                output.strData = "Produce-EngineID=";
                output.strData += szBuff;
            }
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_WHEEL)
        {
            if (state.completeProduce())
            {
                newState.stateID = CAR_FACTORY_STATE_FINISH;    
            }
            else
            {
                sprintf(szBuff, "%d", rand());

                newState.stateID = CAR_FACTORY_STATE_PRODUCE_WHEEL;
                newState.wheelProduced = 1;
                output.strData = "New-WheelID=";
                output.strData += szBuff;
            }
            
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE)
        {
            if (state.completeProduce())
            {
                newState.stateID = CAR_FACTORY_STATE_FINISH;    
            }
            else
            {
                newState.stateID = CAR_FACTORY_STATE_OUTSOURCE_FURNITURE;
                // Entering sub-machine
                newState.furnitureProduced = 1;
                output.strData = "";    // Nil - Only change to Submachine
            }
        }
    }

    return newState;
}

CCompositeTest::CCompositeTest(/* args */)
{}

CCompositeTest::~CCompositeTest()
{}

void CCompositeTest::run()
{
    CarFurnitureSM carFurniture;
    CarFactorySM carFactory(&carFurniture);

    CarFactoryMsg msgs[] = {
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_ENGINE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_ENGINE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_ENGINE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_ENGINE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_ENGINE),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_WHEEL),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_WHEEL),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_WHEEL),
        CarFactoryMsg(CAR_FACTORY_SM_MSG_PRODUCE_WHEEL),
    };

    vector<CarFactoryOut> vOut;

    carFactory.start();
    carFactory.transduce(msgs, sizeof(msgs)/sizeof(CarFactoryMsg), vOut);

    for(int i = 0; i<vOut.size();i++)
    {
        printf("%s\r\n", vOut[i].strData.c_str());
    }
    
    return ;
}