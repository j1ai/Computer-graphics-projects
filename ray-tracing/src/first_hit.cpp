#include <limits>
#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  t = std::numeric_limits<int>::max();
  hit_id = std::numeric_limits<int>::min();
  int count_id = 0;

  while (count_id < objects.size()){
      double cur_parametric_t_distance;
      Eigen::Vector3d cur_surface_normal;

      if(objects[count_id]->intersect(ray, min_t, cur_parametric_t_distance, cur_surface_normal)){
          if (cur_parametric_t_distance < t){
              hit_id = count_id;
              t = cur_parametric_t_distance;
              n = cur_surface_normal;
          }
      }
      count_id ++;
  }

  if (hit_id >= 0){
      return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

