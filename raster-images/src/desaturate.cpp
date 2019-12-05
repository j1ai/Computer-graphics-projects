#include <cmath>
#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i=0; i<width*height;i++){
    double r = (double)rgb[3*i];
    double g = (double)rgb[3*i+1];
    double b = (double)rgb[3*i+2];
    double h,s,v = 0;
    rgb_to_hsv(r,g,b,h,s,v);
    s *= (1.0- factor);
    hsv_to_rgb(h,s,v,r,g,b);
    desaturated[3*i] = r;
    desaturated[3*i+1] = g;
    desaturated[3*i+2] = b;
  }
  ////////////////////////////////////////////////////////////////////////////
}
