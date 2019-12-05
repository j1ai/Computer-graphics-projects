#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int i=0; i<height*width; i++){
    gray[i] = (unsigned char)0.2126*rgb[3*i] + 0.7512*rgb[3*i+1] + 0.0722*rgb[3*i+2];
  }
  ////////////////////////////////////////////////////////////////////////////
}


