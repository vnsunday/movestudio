
#include "CTestMITStateMachine.h"
#include "dynsocc/util/Console.h"
#include "dynsocc/fundamental/impl/statemachine/MIT_Example.h"

#include <string>
#include <vector>

using namespace std;

void CTestMITStateMachine::runTest()
{
    SimpleParkingGate spg;

    TripleField<std::string, bool, bool> spg_Inp[] = {
        TripleField<std::string, bool, bool>("bottom", false, false),
        TripleField<std::string, bool, bool>("bottom", true, false),
        TripleField<std::string, bool, bool>("bottom", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("top", true, false),
        TripleField<std::string, bool, bool>("top", true, false),
        TripleField<std::string, bool, bool>("top", true, false),
        TripleField<std::string, bool, bool>("top", true, true),
        TripleField<std::string, bool, bool>("top", true, true),
        TripleField<std::string, bool, bool>("top", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("middle", true, false),
        TripleField<std::string, bool, bool>("bottom", true, false),
        TripleField<std::string, bool, bool>("bottom", true, false)
    };
    
    vector<string> voutSpg;
    spg.transduce(spg_Inp, 17, voutSpg);

    printf("Output Of SimpleParkingGate: ");
    Console::log(voutSpg);
}
