#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  hit_t = std::numeric_limits<double>::infinity();
  hit_f = -1;
  Eigen::RowVector3d rowVector1;
  Eigen::RowVector3d rowVector2;
  Eigen::RowVector3d rowVector3;
  bool is_hit;

  for(int i=0; i < F.rows(); i++){
    double temp_t;
    rowVector1 = V.row(F(i,0));
    rowVector2 = V.row(F(i,1));
    rowVector3 = V.row(F(i,2));
    is_hit = ray_intersect_triangle(ray, rowVector1,rowVector2,rowVector3,min_t,max_t,temp_t);
    if (is_hit && temp_t < hit_t){
      hit_t = temp_t;
      hit_f = i;
    }
  }

  if (hit_f >= 0){
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
