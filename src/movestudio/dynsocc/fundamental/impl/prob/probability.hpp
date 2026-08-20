#ifndef APP_FUNDAMENTAL_IMPL_PROB_PROBABILITY_H_
#define APP_FUNDAMENTAL_IMPL_PROB_PROBABILITY_H_

#include <vector>

namespace dynsocc {

double mean(double* pD, int nD);
double variance(double* pD, int nD);

int binomal_distribution_table(
                std::vector<double>& vX,
                std::vector<double>& vY,
                int n=10,
                double p=0.5);

int standard_normal_distribution_table(
                    std::vector<double>& vX,
                    std::vector<double>& vY,
                    double xL=-3, 
                    double xR=3, 
                    int nNumBin=1000);

int outlier_detection_zscore(double* pA, int nA, int& nNormal, int& nOutlier, std::vector<int>& voutlier);

}

#endif