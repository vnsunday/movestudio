#ifndef DYNAMICSOCCER_APP_FUNDAMENTAL_INTERFACE_MATH_IGEOMETRY3D_H_
#define DYNAMICSOCCER_APP_FUNDAMENTAL_INTERFACE_MATH_IGEOMETRY3D_H_
/*
 * IGeometry3D.h
 *  Created on: July 14, 2020
 */

#include <opencv2/core.hpp>

class IGeometry3D
{
public:
    virtual ~IGeometry3D() {}

    /*
     * Find the projection of the point p into plane(O, vector(v1), vector(v2))
     * Input:
     *      Point P
     *      Plane(Point(O), vector(v1), vector(v2))
     * Output:
     *      Point pout
     */
    virtual int projectPointIntoPlane(cv::Vec3d p,
                                        cv::Vec3d O,
                                        cv::Vec3d v1,
                                        cv::Vec3d v2,
                                        cv::Vec3d& pout) = 0;

    virtual int projectPointIntoLine(cv::Vec3d p, cv::Vec3d A, cv::Vec3d B, cv::Vec3d& pout) = 0;
};

#endif