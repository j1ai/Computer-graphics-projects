#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i=0; i<width*height;i++){
    double A_r = (double)A[4*i];
    double A_g = (double)A[4*i+1];
    double A_b = (double)A[4*i+2];
    double A_alpha = (double)A[4*i+3] / 255;

    double B_r = (double)B[4*i];
    double B_g = (double)B[4*i+1];
    double B_b = (double)B[4*i+2];
    double B_alpha = (double)B[4*i+3] / 255;

    C[4*i] = (unsigned char)(A_r * A_alpha) + ((1 - A_alpha) * B_alpha * B_r);
    C[4*i+1] = (unsigned  char)(A_g * A_alpha) + ((1 - A_alpha) * B_alpha * B_g);
    C[4*i+2] = (unsigned char)(A_b * A_alpha) + ((1 - A_alpha) * B_alpha * B_b);
    C[4*i+3] = (unsigned char)((A_alpha) + ((1 - A_alpha) * B_alpha))*255;
  }
  ////////////////////////////////////////////////////////////////////////////
}
