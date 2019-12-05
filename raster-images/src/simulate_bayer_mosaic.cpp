#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
    //GBRG
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

    for (int row = 0; row <height; row++){
        for (int col = 0; col<width; col++){
            if (row %2 == 0){ //GB
                if (col %2 == 0){
                    bayer[row*width+col] = rgb[3*(row*width+col)+1];//G
                } else{
                    bayer[row*width+col] = rgb[3*(row*width+col)+2];//B
                }
            }
            else{ //RG
                if (col %2 == 0){
                    bayer[row*width+col] = rgb[3*(row*width+col)];//R
                } else{
                    bayer[row*width+col] = rgb[3*(row*width+col)+1];//G
                }
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
