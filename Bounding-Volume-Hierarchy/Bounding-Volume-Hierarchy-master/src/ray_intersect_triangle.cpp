#include "ray_intersect_triangle.h"

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
    Eigen::RowVector3d edge_ba = B - A;
    Eigen::RowVector3d edge_ca = C - A;
    double a,b,c,d,e,f,g,h,i,beta,gamma,j,k,l;

    a = A[0] - B[0];
    b = A[1] - B[1];
    c = A[2] - B[2];
    d = A[0] - C[0];
    e = A[1] - C[1];
    f = A[2] - C[2];
    g = ray.direction[0];
    h = ray.direction[1];
    i = ray.direction[2];
    j = A[0] - ray.origin[0];
    k = A[1] - ray.origin[1];
    l = A[2] - ray.origin[2];

    double ei_minus_hf, gf_minus_di, dh_minus_eg, ak_minus_jb, jc_minus_al, bl_minus_kc;
    ei_minus_hf = (e * i) - (h * f);
    gf_minus_di = (g * f) - (d * i);
    dh_minus_eg = (d * h) - (e * g);
    ak_minus_jb = (a * k) - (j * b);
    jc_minus_al = (j * c) - (a * l);
    bl_minus_kc = (b * l) - (k * c);

    double m = (a * ei_minus_hf) + (b * gf_minus_di) + (c * dh_minus_eg);

    t = (-1 * ((f * ak_minus_jb) + (e * jc_minus_al) + (d * bl_minus_kc)) / m);

    if (t < min_t || t >= max_t){
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

    return true;
  ////////////////////////////////////////////////////////////////////////////
}

