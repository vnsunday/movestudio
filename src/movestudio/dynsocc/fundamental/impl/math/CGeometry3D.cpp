#include "CGeometry3D.h"
#include <opencv2/core.hpp>

using namespace cv;

CGeometry3D::CGeometry3D(/* args */)
{
}

CGeometry3D::~CGeometry3D()
{
}

int CGeometry3D::projectPointIntoPlane(cv::Vec3d p,
                                    cv::Vec3d O,
                                    cv::Vec3d v1,
                                    cv::Vec3d v2,
                                    cv::Vec3d& pout)
{
    /*--------------------------------------------------------------------------------
     *   Key idea:
     *      - N = normal vector of (v1,v2) <=> N = v1 cross v2
     *      - Let P1 be the projection of point p in Plane(O, v1,v2)
     *      => 
     *          vector(PP1)*v1 = 0 (Perpendicular)
     *          vector(PP1)*v2 = 0 (Perpendicular)
     *          vector(OP1)*N = 0   (Perpendicular)
     *      => 
     *          Solve the 03 variable-equation.
     *--------------------------------------------------------------------------------*/

    // Normal vector
    Vec3d vN =  v1.cross(v2);

    Mat mA = (Mat_<double>(3,3) << 
                v1[0], v1[1], v1[2],
                v2[0], v2[1], v2[2],
                vN[0], vN[1], vN[2]);
    Mat mB = (Mat_<double>(3,1) <<
                p[0]*v1[0] + p[1]*v1[1] + p[2]*v1[2],
                p[0]*v2[0] + p[1]*v2[1] + p[2]*v2[2],
                O[0]*vN[0] + O[1]*vN[1] + O[2]*vN[2]);

    // mA*X = mB 
    // => X = invert(mA)*B
    Mat mA_inv = mA.inv();
    Mat X = mA_inv * mB;

    pout = Vec3d(X.reshape(3).at<cv::Vec3d>());
    return 0;
}

int CGeometry3D::projectPointIntoLine(cv::Vec3d p, cv::Vec3d A, cv::Vec3d B, cv::Vec3d& pout)
{
    // --------------- projectPointIntoLine?
    /* 
        N = PA cross PB.

        =>
        PP1 * AB = 0
        P1A * N = 0
        P1B * N = 0
        -----------
        <=>
            (x-px)*(ax-bx) + (y-py)*(ay-by) + (z-pz)*(az-bz) = 0.
            (x-ax)*(nx) + (y-ay)*ny + (z-az)*nz = 0
            (x-bx)*nx + (y-by)*ny + (z-bz)*nz = 0

        <=> 
            x * (ax-bx) + y*(ay-by) + z*(az-bz) = px(ax-bx) + py(ay-by)+z(az-bz)
            x*nx + y*ny + z*nz = ax*nx + ay*nz + az*nz
            x*nx + y*ny + z*nz = bx*nx + by*ny + bz*nz
     */    
    
    // Normal vector 
    Vec3d N = B.cross(A);
    Mat mA = (Mat_<double>(3,3) << 
        A[0]-B[0],  A[1]-B[1],  A[2]-B[2],
        N[0],       N[1],       N[2],
        N[0],       N[1],       N[2]);

    Mat mB = (Mat_<double>(3,1) << 
        p[0]*(A[0]-B[0]) + p[1]*(A[1]-B[1]) + p[2]*(A[2]-B[2]),
        A[0]*N[0] + A[1]*N[1] + A[2]*N[2],
        B[0]*N[0] + B[1]*N[1] + B[2]*N[2]
    );

    Mat mA_inv = mA.inv();
    Mat X = mA_inv * mB;

    // 3x1 to 1x3 (flatten)
    pout = Vec3d(X.reshape(3).at<Vec3d>());
    return 0;
}