#include <cmath>
#include <numeric>
#include <stdlib.h>
#include "probability.hpp"
#include <vector>

using namespace std;

double dynsocc::mean(double* pD, int nD) {

    double dSum = std::accumulate(pD, pD+nD, 0);
    return dSum / nD;
}

double dynsocc::variance(double* pD, int nD) {
    
    double dSum = std::accumulate(pD, pD+nD, 0);
    double dVariance = 0.0;
    double dMean = dSum / nD;

    for (int i = 0; i < nD; ++i) {
        double dVal = (pD[i] - dMean);
        dVariance += dVal * dVal;
    }

    dVariance = dVariance / nD;
    return dVariance;
}

int dynsocc::outlier_detection_zscore(double* pA, int nA, int& nNormal, int& nOutlier, vector<int>& voutlier) {
    // Made a distribution
    // z-score 
    // Three sigma
    double dSum = 0;
    double dMean;
    double dVariance = 0.0;
    double dSigma;
    double dThreeSigmaL;
    double dThreeSigmaH;

    dSum = std::accumulate(pA, pA + nA, 0);
    dMean = dSum / nA;

    for (int i = 0; i < nA; ++i) {
        double dVal = (pA[i] - dMean);
        dVariance += dVal * dVal;
    }

    dVariance = dVariance / nA;
    dSigma = sqrt(dVariance);

    dThreeSigmaL = dMean - 3 * dSigma;
    dThreeSigmaH = dMean + 3 * dSigma;

    nNormal = 0;
    nOutlier = 0;
    voutlier.clear();

    for (int i = 0; i < nA; ++i) {
        if (pA[i] >= dThreeSigmaL && pA[i] <= dThreeSigmaH) {
            nNormal++;
        }
        else {
            nOutlier++;
            voutlier.push_back(i);
        }
    }

    return 0;
}