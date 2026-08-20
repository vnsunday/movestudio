#ifndef DYNSOCC_FUNDAMENTAL_STDEX_RECT_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_RECT_H_

#include <string>

namespace dynsocc
{
    struct Rectangle
    {
        int x;
        int y;
        int w;
        int h;

        Rectangle();
        Rectangle(int x1,int y1, int w1, int h1);

        bool isEmpty(); // Zero area or none existed

        bool isNULL(); // Not existed (width or height < 0)

        bool hasShape();

        bool operator==(const Rectangle& rc);

        bool operator!=(const Rectangle& rc);

        std::string toString();
    };
}

#endif // !