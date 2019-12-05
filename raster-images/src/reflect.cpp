#include <algorithm>
#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    if (num_channels == 3){
        for (int row = 0; row < height; row++){
            for (int col = 0; col < width; col++){
                reflected[3*(width*row+col)] = input[3*(width*(row+1)-col)-3];
                reflected[3*(width*row+col)+1] = input[3*(width*(row+1)-col)-2];
                reflected[3*(width*row+col)+2] = input[3*(width*(row+1)-col)-1];
            }
        }
    }
    else{
        for (int row = 0; row < height; row++){
            for (int col = 0; col < width; col++){
                reflected[row*width+col] = input[(row+1)*width-col-1];
            }
        }
    }


  ////////////////////////////////////////////////////////////////////////////
}
