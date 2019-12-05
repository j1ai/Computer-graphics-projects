#include <algorithm>
#include "rgb_to_hsv.h"

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  double max = std::max(std::max(r,g),b);
  double min = std::min(std::min(r,g),b);
  double delta = max - min;

  if (delta > 0){
    if (max == g){
      h = 60.0 * (((b - r) / delta) + 2);
    }
    else if (max == b){
      h = 60.0 * (((r - g) / delta) + 4);
    }
    else if (max == r){
      h = 60.0*((g - b) / delta);
    }

    if (max > 0){
      s = delta / max;
    }
    else{
      s = 0;
    }

    v = max;
  }
  else{
    h = 0;
    s = 0;
    v = max;
  }

  if (h < 0){
    h += 360;
  }
  ////////////////////////////////////////////////////////////////////////////
}
