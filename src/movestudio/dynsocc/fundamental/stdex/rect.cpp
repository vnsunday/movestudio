
#include "rect.h"
#include <string>
using namespace dynsocc;

Rectangle::Rectangle()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rectangle::Rectangle(int x1,int y1, int w1, int h1)
{
    x = x1;
    y = y1;
    w = w1;
    h = h1;
}

bool Rectangle::isEmpty() // Zero area or none existed
{
    return (w==0 || h == 0);
}

bool Rectangle::isNULL() // No existed (width or height < 0)
{
    return (w < 0 || h < 0);
}

bool Rectangle::operator==(const Rectangle& rc)
{
    return this->x == rc.x &&
            this->y == rc.y && 
            this->w == rc.w && 
            this->h == rc.h;
}

bool Rectangle::operator!=(const Rectangle& rc)
{
    return !(this->x == rc.x &&
            this->y == rc.y && 
            this->w == rc.w && 
            this->h == rc.h);
}

bool Rectangle::hasShape()
{
    return !isEmpty() && !isNULL();
}

std::string Rectangle::toString()
{
    char szBuff[200];
    sprintf(szBuff,"[x,y,w,h=(%d,%d,%d,%d)]", x, y, w,h);
    return std::string(szBuff);
}