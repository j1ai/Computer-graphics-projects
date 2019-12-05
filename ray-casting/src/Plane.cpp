#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;

  double denominator = d.dot(normal);
  if (denominator != 0){
      double parametric_t = ((point - e).dot(normal)) / denominator;
      if(parametric_t >= min_t){
          t = parametric_t;
          n = normal;
          return true;
      }
  }
  return false;

  ////////////////////////////////////////////////////////////////////////////
}

