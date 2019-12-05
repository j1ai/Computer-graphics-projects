#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  ////Hint:
   V.resize(8,3);
   F.resize(6,4);
   UV.resize(14,2);
   UF.resize(6,4);
   NV.resize(6,3);
   NF.resize(6,4);


   V << 0,0,0,
        1,0,0,
        1,0,1,
        0,0,1,
        0,1,0,
        0,1,1,
        1,1,0,
        1,1,1;

   // Red, Green, Blue, Orange, Yellow, White
   F << 0,1,2,3,
        1,6,7,2,
        6,4,5,7,
        4,0,3,5,
        2,7,5,3,
        0,4,6,1;

   UV << 0,0.25,
         0.25,0.25,
         0.25,0,
         0.5,0,
         0.5,0.25,
         0.75,0.25,
         1,0.25,
         1,0.5,
         0.75,0.5,
         0.5,0.5,
         0.5,0.75,
         0.25,0.75,
         0.25,0.5,
         0,0.5;

   UF << 1,12,13,0,
         1,4,9,12,
         4,5,8,9,
         5,6,7,8,
         12,9,10,11,
         2,3,4,1;


   NV << 0,0,1,
         0,0,-1,
         0,1,0,
         0,-1,0,
         1,0,0,
        -1,0,0;

   NF << 3,3,3,3,
         4,4,4,4,
         2,2,2,2,
         5,5,5,5,
         0,0,0,0,
         1,1,1,1;






}
