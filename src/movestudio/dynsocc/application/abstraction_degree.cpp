#include <stdio.h>
#include <string>

using namespace std;

int abstraction_degree(string szData, string szType) {
    int nDegree = 1;
    if (szType == "NumberVariable") {
        nDegree = 1;
    } else if (szType == "Number") {
        nDegree = 0;
    } else if (szType == "RangeVariable") {
        nDegree = 1;
    } else if (szType == "Range") {
        nDegree = 0;
    } else if (szType == "Person") {
        if (szData == "Specific") {
            nDegree = 0;
        }
        else if (szData == "Nationality") {
            nDegree = 1;
        }
    } 

    return nDegree;
}