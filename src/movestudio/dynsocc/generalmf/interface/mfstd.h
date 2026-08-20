#ifndef APP_GENERALMF_INTERFACE_MFSTD_H_
#define APP_GENERALMF_INTERFACE_MFSTD_H_

/* 
 *  March 30th 2021
 */

/*======================================================================
    Interface abstraction of         
 *======================================================================*/

class IUniversal 
{
    public:
        virtual ~IUniversal() {}
};  // A state of Universal

class IUniversalSet
{
    public:
        

};  // Every member of 

class ITime
{
    public:
        ITime(IUniversal) {}
};

class ITimeInterval
{
private:
    /* data */
public:
    ITimeInterval(IUniversal, IUniversal) {}
    virtual ~ITimeInterval() {}
};



#endif