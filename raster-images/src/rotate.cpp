#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int pixelCounter = 0;
  if (num_channels == 3){
    for (int col = width-1; col >= 0; col --){
      for (int row = 0; row < height; row++){
        rotated[3*(pixelCounter)] = input[3*((row*width+col))];
        rotated[3*(pixelCounter)+1] = input[3*((row*width+col))+1];
        rotated[3*(pixelCounter)+2] = input[3*((row*width+col))+2];
        pixelCounter++;
      }
    }
  }
  else{
      for (int col = width-1; col >= 0; col --){
          for (int row = 0; row < height; row++){
              rotated[pixelCounter] = input[row*width+col];
              pixelCounter++;
          }
      }
  }
  ////////////////////////////////////////////////////////////////////////////
}
