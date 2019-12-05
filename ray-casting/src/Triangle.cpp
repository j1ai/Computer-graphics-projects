#include "Triangle.h"
#include "Ray.h"

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d vertex_a = std::get<0>(corners);
  Eigen::Vector3d vertex_b = std::get<1>(corners);
  Eigen::Vector3d vertex_c = std::get<2>(corners);
  Eigen::Vector3d edge_ba = vertex_b - vertex_a;
  Eigen::Vector3d edge_ca = vertex_c - vertex_a;
  double a,b,c,d,e,f,g,h,i,beta,gamma,j,k,l;

  a = vertex_a[0] - vertex_b[0];
  b = vertex_a[1] - vertex_b[1];
  c = vertex_a[2] - vertex_b[2];
  d = vertex_a[0] - vertex_c[0];
  e = vertex_a[1] - vertex_c[1];
  f = vertex_a[2] - vertex_c[2];
  g = ray.direction[0];
  h = ray.direction[1];
  i = ray.direction[2];
  j = vertex_a[0] - ray.origin[0];
  k = vertex_a[1] - ray.origin[1];
  l = vertex_a[2] - ray.origin[2];

  double ei_minus_hf, gf_minus_di, dh_minus_eg, ak_minus_jb, jc_minus_al, bl_minus_kc;
  ei_minus_hf = (e * i) - (h * f);
  gf_minus_di = (g * f) - (d * i);
  dh_minus_eg = (d * h) - (e * g);
  ak_minus_jb = (a * k) - (j * b);
  jc_minus_al = (j * c) - (a * l);
  bl_minus_kc = (b * l) - (k * c);

  double m = (a * ei_minus_hf) + (b * gf_minus_di) + (c * dh_minus_eg);

  t = (-1 * ((f * ak_minus_jb) + (e * jc_minus_al) + (d * bl_minus_kc)) / m);

  if (t < min_t){
      return false;
  }

  gamma = (((i * ak_minus_jb) + (h * jc_minus_al) + (g * bl_minus_kc)) / m);

  if (gamma < 0 || gamma > 1){
      return false;
  }

  beta = (((j * ei_minus_hf) + (k * gf_minus_di) + (l * dh_minus_eg)) / m);

  if (beta < 0 || beta > 1 - gamma){
      return false;
  }

  n = (edge_ba).cross(edge_ca);

  return true;
  ////////////////////////////////////////////////////////////////////////////
}


