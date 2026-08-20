#ifndef _DYNSCOCCER_DESIGN_QUIZ_IRESOURCE_H_
#define _DYNSCOCCER_DESIGN_QUIZ_IRESOURCE_H_

class IResource
{
public:
    virtual int ID() = 0;        
    virtual char* Name() = 0;
};

#endif