#ifndef DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_
#define DYNSOCC_FUNDAMENTAL_STDEX_GEOMETRY_H_

#include "stdex.h"
#include "rect.h"
#include <vector>

namespace dynsocc
{

    class GeometryUtil
    {
        public:
            static bool intersect(Rectangle rc1, Rectangle rc2, Rectangle& rc);

            static bool intersect(Rectangle rc1, Rectangle rc2);

            static Rectangle move(Rectangle r, int offsetX, int offsetY);

            /* 
            * View through a stack of lens
            *  vlens[0] is the top <=> the lens that nearest the eye
            *  
            *  Eye ==See=>  vlens[0], vlens[1],...,vlens[n] ===> object
            * 
            */            
            static int view_through_lens(
                Rectangle lens,
                Rectangle object,
                Rectangle &view
            );

            static int view_through_lens(
                std::vector<Rectangle> vlens,
                Rectangle object,
                Rectangle &view
            );

    };

}

#endif