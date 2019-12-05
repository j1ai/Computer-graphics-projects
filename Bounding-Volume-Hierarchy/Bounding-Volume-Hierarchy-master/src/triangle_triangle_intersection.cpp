#include <ray_intersect_triangle.h>
#include "triangle_triangle_intersection.h"

bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double t;
  double min_t = 0;
  double max_t = 1;
  Ray ray_a0 = Ray(A0, A1-A0);
  Ray ray_a1 = Ray(A1, A2-A1);
  Ray ray_a2 = Ray(A2, A0-A2);
  Ray ray_b0 = Ray(B0, B1-B0);
  Ray ray_b1 = Ray(B1, B2-B1);
  Ray ray_b2 = Ray(B2, B0-B2);

  if (    ray_intersect_triangle(ray_a0,B0,B1,B2,min_t,max_t,t) ||
          ray_intersect_triangle(ray_a1,B0,B1,B2,min_t,max_t,t) ||
          ray_intersect_triangle(ray_a2,B0,B1,B2,min_t,max_t,t) ||
          ray_intersect_triangle(ray_b0,A0,A1,A2,min_t,max_t,t) ||
          ray_intersect_triangle(ray_b1,A0,A1,A2,min_t,max_t,t) ||
          ray_intersect_triangle(ray_b2,A0,A1,A2,min_t,max_t,t)){
    return true;
  }
  return false; 
  ////////////////////////////////////////////////////////////////////////////
}
