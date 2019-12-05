#include <cmath>
#include "hsv_to_rgb.h"

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double chroma = v*s;
  double hprime = h/60;
  double x = chroma* (1 - std::fabs(std::fmod(hprime,2) - 1));
  if (hprime >= 0 && hprime <= 1){
    r = chroma;
    g = x;
    b = 0;
  }
  else if (hprime >= 1 && hprime <= 2){
    r = x;
    g = chroma;
    b = 0;
  }
  else if (hprime >= 2 && hprime <= 3){
    r = 0;
    g = chroma;
    b = x;
  }
  else if (hprime >= 3 && hprime <= 4){
    r = 0;
    g = x;
    b = chroma;
  }
  else if (hprime >= 4 && hprime <= 5){
    r = x;
    g = 0;
    b = chroma;
  }
  else if (hprime >= 5 && hprime <= 6){
    r = chroma;
    g = 0;
    b = x;
  }
  else{
    r = 0;
    g = 0;
    b = 0;
  }

  double m = v - chroma;
  r+= m;
  g+= m;
  b+= m;
  ////////////////////////////////////////////////////////////////////////////
}
