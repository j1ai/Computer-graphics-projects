#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    ray.origin = camera.e;
    double l = (-camera.width/2);
    double b = (camera.height/2);

    double u = l + (camera.width)*(j+0.5)/width;
    double v = b - (camera.height)*(i+0.5)/height;

    ray.direction = (camera.w.operator*(-camera.d)) + camera.u.operator*(u) + camera.v.operator*(v);

  ////////////////////////////////////////////////////////////////////////////
}

