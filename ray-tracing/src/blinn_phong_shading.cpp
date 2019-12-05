#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  Eigen::Vector3d rgb = Eigen::Vector3d(0,0,0);
  Eigen::Vector3d k_diffuse = objects[hit_id]->material->kd;
  Eigen::Vector3d k_specular = objects[hit_id]->material->ks;
  Eigen::Vector3d k_ambient = objects[hit_id]->material->ka;
  Eigen::Vector3d v = (-ray.direction).normalized();
  Eigen::Vector3d q = ray.origin + ray.direction * t;
  Eigen::Vector3d ambient_intensity = Eigen::Vector3d(0.1,0.1,0.1);
  double phong_exponent = objects[hit_id]->material->phong_exponent;
  double epsilon = 0.0000001;

  for (int i = 0; i<lights.size(); i++){
    Eigen::Vector3d intensity = lights[i]->I;
    double light_max_t;
    Eigen::Vector3d light_ray_direction;
    Ray cur_light_ray;
    lights[i]->direction(q,light_ray_direction,light_max_t);

    cur_light_ray.origin = q;
    cur_light_ray.direction = light_ray_direction;
    Eigen::Vector3d h = (v + light_ray_direction.normalized()).normalized();

    Eigen::Vector3d cur_light_hit_normal;
    int cur_light_hit_id;
    double cur_light_t;
    //Check wether the point is in the shadow

    if (!first_hit(cur_light_ray,epsilon,objects,cur_light_hit_id,cur_light_t,cur_light_hit_normal) || cur_light_t >= light_max_t){
        rgb.operator+=((k_diffuse.array().operator*=(intensity.array()).matrix()) * fmax(0, n.dot(light_ray_direction)));
        rgb.operator+=((k_specular.array().operator*=(intensity.array()).matrix()) * pow(fmax(0, n.dot(h)), phong_exponent));
    }
  }
  rgb.operator+=(k_ambient.array().operator*=(ambient_intensity.array()).matrix());
  return rgb;
  ////////////////////////////////////////////////////////////////////////////
}
