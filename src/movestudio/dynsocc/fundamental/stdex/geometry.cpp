#include "stdex.h"
#include "geometry.h"
#include <vector>

using namespace dynsocc;
using namespace std;

bool GeometryUtil::intersect(Rectangle rc1, Rectangle rc2, Rectangle& rc)
{
    if (intersect(rc1,rc2))
    {
        // rc.x = std::max()

        return true;
    }
    return false;
}

bool GeometryUtil::intersect(Rectangle rc1, Rectangle rc2)
{
    return  (rc1.x + rc1.w >= rc2.x && 
                    rc2.x + rc2.w >= rc1.x &&
                    rc2.y + rc2.h >= rc1.y && 
                    rc1.y + rc1.h >= rc2.y);
}

Rectangle GeometryUtil::move(Rectangle r, int offsetX, int offsetY)
{
    Rectangle r1 = r;
    r1.x += offsetX;
    r1.y += offsetY;

    return r1;
}

int GeometryUtil::view_through_lens(
        Rectangle lens,
        Rectangle object,
        Rectangle &view)
{
    if (GeometryUtil::intersect(lens, object, view))
    {
        return 0;
    }
    view = Rectangle(0,0,0,0);
    return 1;
}

int GeometryUtil::view_through_lens(
        std::vector<Rectangle> vlens,
        Rectangle object,
        Rectangle &view)
{
    Rectangle acc_obj = object;
    for (int i=vlens.size()-1; i>=0;i--)
    {
        int r = view_through_lens(vlens[i],acc_obj,acc_obj);

        if (!STDEX_SUCCESS(r))
        {
            view=Rectangle(0,0,0,0);
            return 1;
        }
    }

    view = acc_obj;
    return 0;
}
