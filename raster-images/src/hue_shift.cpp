#include <cmath>
#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i=0; i<width*height;i++){
    double r = (double)rgb[3*i];
    double g = (double)rgb[3*i+1];
    double b = (double)rgb[3*i+2];
    double h,s,v = 0;
    rgb_to_hsv(r,g,b,h,s,v);
    h += shift;
    if (h < 0){
        h += 360;
    }
    h = fmod(h,360);
    hsv_to_rgb(h,s,v,r,g,b);
    shifted[3*i] = r;
    shifted[3*i+1] = g;
    shifted[3*i+2] = b;
  }
  ////////////////////////////////////////////////////////////////////////////
}
