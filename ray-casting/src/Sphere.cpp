#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  double critical_min_t;
  double critical_max_t;
  Eigen::Vector3d p;

  double discriminant = pow(d.dot((e - center)),2) - (d.dot(d))*((e - center).dot(e - center) - pow(radius,2));
  // Sphere do not intersect because of imaginary solution
  if (discriminant < 0){
      return false;
  }
  else if (discriminant == 0){
      critical_min_t = (-d.dot(e - center))/ (d.dot(d));
      p = e + (d.operator*(critical_min_t));
      if(critical_min_t >= min_t){
        t = critical_min_t;
        n = (p - center).operator/(radius);
        return true;
      }
  }
  else{
      critical_min_t = ((-d.dot(e - center)) - sqrt(discriminant)) / (d.dot(d));
      critical_max_t = ((-d.dot(e - center)) + sqrt(discriminant)) / (d.dot(d));

      if(critical_min_t >= min_t){
          p = e + (d.operator*(critical_min_t));
          t = critical_min_t;
          n = (p - center).operator/(radius);
          return true;
      }
      else if(critical_max_t >= min_t && critical_min_t < min_t){
          p = e + (d.operator*(critical_max_t));
          t = critical_max_t;
          n = (p - center).operator/(radius);
          return true;
      }
  }
  return false;

  ////////////////////////////////////////////////////////////////////////////
}

