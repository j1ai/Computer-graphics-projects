#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int hit_id;
  double t;
  Eigen::Vector3d normal;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d d = ray.direction;
  rgb = Eigen::Vector3d(0,0,0);

  if (num_recursive_calls < 5){

    if(first_hit(ray,min_t,objects,hit_id,t,normal)){

      Ray reflected_ray;
      Eigen::Vector3d p = e + (d.operator*(t));
      rgb.operator+=(blinn_phong_shading(ray, hit_id, t, normal,objects,lights));

      Eigen::Vector3d reflected_direction = reflect(ray.direction.normalized(),normal);
      reflected_ray.origin = p;
      reflected_ray.direction = reflected_direction;

      double epsilon = 0.0000001;
      Eigen::Vector3d reflected_rgb;

      if (raycolor(reflected_ray, epsilon,objects,lights,num_recursive_calls + 1, reflected_rgb)){
        Eigen::Vector3d k_mirror_color = objects[hit_id]->material->km;
        rgb.operator+=((k_mirror_color.array().operator*=(reflected_rgb.array())).matrix());
      }

      return true;
    }
  }


  return false;
  ////////////////////////////////////////////////////////////////////////////
}
