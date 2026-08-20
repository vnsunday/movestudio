#ifndef APP_FUNDAMENTAL_IMPL_MATH_CGEOMETRY3D_H_
#define APP_FUNDAMENTAL_IMPL_MATH_CGEOMETRY3D_H_
/*
 * CGeometry3D.h
 *  Created on: July 14, 2020
 */

#include "interface/math/IGeometry3D.h"
#include <opencv2/core.hpp>

class CGeometry3D: public IGeometry3D 
{
private:
    /* data */
public:
    CGeometry3D(/* args */);
    virtual ~CGeometry3D() {}

    /*
     * Find the projection of the point p into plane(O, vector(v1), vector(v2))
     * Input:
     *      Point P
     *      Plane(Point(O), vector(v1), vector(v2))
     * Output:
     *      Point pout
     */
    int projectPointIntoPlane(cv::Vec3d p,
                                        cv::Vec3d O,
                                        cv::Vec3d v1,
                                        cv::Vec3d v2,
                                        cv::Vec3d& pout);

    int projectPointIntoLine(cv::Vec3d p, cv::Vec3d A, cv::Vec3d B, cv::Vec3d& pout);
    
};


#endif