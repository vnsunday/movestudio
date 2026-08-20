#include <stdio.h>
#include <stdlib.h>
#include "algorithm.hpp"

using namespace dynsocc;

template<typename T>
int dynsocc::algorithm::equality_score(T* parr1, int n1, T* parr2, int n2) {

    int i, j;
    return 0;
}

template<typename T>
int dynsocc::algorithm::remove_element(T* parr, int nBegin, int &nEnd, int removeIndex) {
    if (removeIndex >= nBegin && removeIndex < nEnd)
    {
        for (int i=removeIndex;i<nEnd-1;++i)
        {
            parr[i]=parr[i+1];
        }
        nEnd--;
        return 0;
    }
    return 1;
}

/*
template<typename T>
int dynsocc::algorithm::remove_element(T* parr, T* parr2, int nBegin, int& nEnd, int removeIndex) {
    if (removeIndex >= nBegin && removeIndex < nEnd) {
        for (int i = removeIndex; i < nEnd - 1; ++i) {
            parr[i] = parr[i + 1];
            parr2[i] = parr2[i + 1];
        }
        nEnd--;
        return EXOK;
    }
    return 1;
}
*/
