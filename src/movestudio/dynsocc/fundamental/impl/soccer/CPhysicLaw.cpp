#include "CPhysicLaw.h"

CPhysicLaw::CPhysicLaw(/* args */)
{
}

CPhysicLaw::~CPhysicLaw()
{
}

int CPhysicLaw::next_state(void* object)                           // General law
{
    return 0;
}

double CPhysicLaw::straight_move(double v, double x0, double t)
{
    double d = x0 + v*t;
    return d;
}