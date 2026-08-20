#include "CSwitcherTest.h"
#include "dynsocc/util/Console.h"
#include <string>
#include <vector>

void CSwitcherTest::runTest()
{
    SMSubSquare smSquare;
    SMSubMul2 smMul2;
    SwicherDiscrete sm(&smSquare, &smMul2);

    double arrInput[] = {
        0,
        -3, 
        2,
        4,
        5,
        -19
    };

    std::vector<double> vOut;
    sm.transduce(arrInput, 6, vOut);

    printf("Output Of Switcher: ");
    Console::log(vOut);
}