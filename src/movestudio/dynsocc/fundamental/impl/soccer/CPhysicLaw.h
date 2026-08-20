#ifndef APP_FUNDAMENTAL_IMPL_SOCCER_CPHYSICLAW_H_
#define APP_FUNDAMENTAL_IMPL_SOCCER_CPHYSICLAW_H_

#include "dynsocc/fundamental/interface/soccer/IPhysicLaw.h"

class CPhysicLaw : public IPhysicLaw
{
private:
    /* data */
public:
    CPhysicLaw(/* args */);
    ~CPhysicLaw();

    int next_state(void* object);                           // General law
    double straight_move(double v, double x0, double t);
};


#endif