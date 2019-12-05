#include "insert_box_into_box.h"

void insert_box_into_box(
  const BoundingBox & A,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  while (counter < 3){
      B.min_corner[counter] = fmin(A.min_corner[counter],B.min_corner[counter]);
      B.max_corner[counter] = fmax(A.max_corner[counter],B.max_corner[counter]);
      counter++;
  }
}

