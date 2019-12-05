#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double x_e, x_d,y_e,y_d,z_e,z_d,a_xd,a_yd,a_zd;
  double t_xmin, t_xmax, t_ymin, t_ymax, t_zmin, t_zmax;
  double t_min, t_max;

  x_e = ray.origin[0];
  y_e = ray.origin[1];
  z_e = ray.origin[2];
  x_d = ray.direction[0];
  y_d = ray.direction[1];
  z_d = ray.direction[2];
  a_xd = 1/x_d;
  a_yd = 1/y_d;
  a_zd = 1/z_d;

  double x_min = box.min_corner[0];
  double y_min = box.min_corner[1];
  double z_min = box.min_corner[2];
  double x_max = box.max_corner[0];
  double y_max = box.max_corner[1];
  double z_max = box.max_corner[2];

  if(a_xd >= 0){
    t_xmin = a_xd*(x_min - x_e);
    t_xmax = a_xd*(x_max - x_e);
  }
  else{
    t_xmin = a_xd*(x_max - x_e);
    t_xmax = a_xd*(x_min - x_e);
  }
  t_min = t_xmin;
  t_max = t_xmax;

  if(a_yd >= 0){
    t_ymin = a_yd*(y_min - y_e);
    t_ymax = a_yd*(y_max - y_e);
  }
  else{
    t_ymin = a_yd*(y_max - y_e);
    t_ymax = a_yd*(y_min - y_e);
  }

  if(t_xmin > t_ymax || t_ymin > t_xmax){
    return false;
  }

  if (t_ymin > t_min){
      t_min = t_ymin;
  }

  if (t_ymax < t_max){
    t_max = t_ymax;
  }

  if(a_zd >= 0){
    t_zmin = a_zd*(z_min - z_e);
    t_zmax = a_zd*(z_max - z_e);
  }
  else{
    t_zmin = a_zd*(z_max - z_e);
    t_zmax = a_zd*(z_min - z_e);
  }

  if(t_min > t_zmax || t_zmin > t_max){
    return false;
  }

  if (t_zmin > t_min){
        t_min = t_zmin;
  }

  if (t_zmax < t_max){
        t_max = t_zmax;
  }

  if (max_t < t_max){
      t_max = max_t;
  }

  if (min_t > t_min){
      t_min = min_t;
  }

  if (t_max < t_min){
      return false;
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
