#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images
  assert(
          (num_channels == 3 || num_channels ==1 ) &&
          ".ppm only supports RGB or grayscale images");

  std::ofstream ppmfile (filename, std::ofstream::out);
  if(!ppmfile){
    std::cout << "Failed to open the file" << filename << std::endl;
    return false;
  }
  if (num_channels == 3){
    ppmfile.write("P3\n",2);
    ppmfile << width << " " << height << " \n";
    ppmfile << "255\n";
  }
  else if (num_channels == 1){
    ppmfile.write("P2\n",2);
    ppmfile << width << " " << height << " \n";
    ppmfile << "255\n";
  }

  for (int i=0; i<width*height*num_channels; i++){
    if (i % width == 0 && i != 0){
      ppmfile << "\n";
    }
    ppmfile << (int)data[i]<< " ";
  }
  ppmfile.close();
  if (!ppmfile.is_open()){
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
