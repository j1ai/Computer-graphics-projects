#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int row = 0; row <height; row++){
    for (int col = 0; col<width; col++){
      if (row %2 == 0){ //GB
        if (col %2 == 0){
          rgb[3*(row*width+col)+1] = bayer[row*width+col];//G
            // Getting B value
          if (col == 0){
              rgb[3*(row*width+col)+2] = bayer[row*width+col+1]; // Only 1 Blue Neighbour
          }
          else{
              rgb[3*(row*width+col)+2] = (bayer[row*width+col+1] + bayer[row*width+col-1]) / 2;
          }
            //Getting R value
          if (row == 0){
              rgb[3*(row*width+col)] = bayer[(row+1)*width+col];
          }
            else if (row == height - 1){
              rgb[3*(row*width+col)] = bayer[(row-1)*width+col];
          }
            else{
              rgb[3*(row*width+col)] = (bayer[(row+1)*width+col] + bayer[(row-1)*width+col]) / 2;
          }
        }

        else{
          rgb[3*(row*width+col)+2] = bayer[row*width+col];//B
            // Getting G value
            if (row == 0){
                rgb[3*(row*width+col)+1] = (bayer[row*width+col-1] + bayer[row*width+col+1] + bayer[(row+1)*width+col]) / 3; //G
            }
            else if (row == height - 1){
                rgb[3*(row*width+col)+1] = (bayer[row*width+col-1] + bayer[row*width+col+1] + bayer[(row-1)*width+col]) / 3; //G
            }
            else{
                rgb[3*(row*width+col)+1] = (bayer[row*width+col-1] + bayer[row*width+col+1] + bayer[(row-1)*width+col] + bayer[(row+1)*width+col]) / 4;
            }

            //Getting R value
            if (row == 0){
                rgb[3*(row*width+col)] = (bayer[(row+1)*width+col-1] + bayer[(row+1)*width+col+1]) / 2; //R
            }
            else if (row == height - 1){
                rgb[3*(row*width+col)] = (bayer[(row-1)*width+col-1] + bayer[(row-1)*width+col+1]) / 2;//R
            }
            else{
                rgb[3*(row*width+col)] = (bayer[(row+1)*width+col-1] + bayer[(row+1)*width+col+1] + bayer[(row-1)*width+col-1] + bayer[(row-1)*width+col+1]) / 4;
            }
        }
      }
      else{ //RG
        if (col %2 == 0){
          rgb[3*(row*width+col)] = bayer[row*width+col];//R

            // Getting G value
            if (col == 0){
                rgb[3*(row*width+col)+1] = (bayer[row*width+col+1] + bayer[(row-1)*width+col] + bayer[(row+1)*width+col]) / 3; //G
            }
            else if (col == width - 1){
                rgb[3*(row*width+col)+1] = (bayer[row*width+col-1] + bayer[(row-1)*width+col] + bayer[(row+1)*width+col]) / 3; //G
            }
            else{
                rgb[3*(row*width+col)+1] = (bayer[row*width+col-1] + bayer[row*width+col+1] + bayer[(row-1)*width+col] + bayer[(row+1)*width+col]) / 4;
            }

            //Getting B value
            if (col == width - 1){
                rgb[3*(row*width+col)+2] = bayer[(row-1)*width+col-1]; //B
            }
            else{
                rgb[3*(row*width+col)+2] = (bayer[(row-1)*width+col-1] + bayer[(row+1)*width+col+1]) / 2;
            }

        }

        else{
            rgb[3*(row*width+col)+1] = bayer[row*width+col];//G
            // Getting R value
            if (col == width - 1){
                rgb[3*(row*width+col)] = bayer[row*width+col-1];
            }
            else{
                rgb[3*(row*width+col)] = (bayer[row*width+col+1] + bayer[row*width+col-1]) / 2;
            }

            //Getting B value
            if (row == height - 1){
                rgb[3*(row*width+col)+2] = bayer[(row-1)*width+col];
            }
            else{
                rgb[3*(row*width+col)+2] = (bayer[(row+1)*width+col] + bayer[(row-1)*width+col]) / 2;
            }
        }
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
