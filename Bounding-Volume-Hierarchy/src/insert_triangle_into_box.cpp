#include "insert_triangle_into_box.h"

void insert_triangle_into_box(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  int i = 0;
  double bc_min,bc_max,aB_min,aB_max;
  while (i < 3){
     bc_min = fmin(b[i], c[i]);
     bc_max = fmax(b[i], c[i]);
     aB_min = fmin(B.min_corner[i], a[i]);
     aB_max = fmax(B.max_corner[i], a[i]);
     B.min_corner[i] = fmin(bc_min,aB_min);
     B.max_corner[i] = fmax(bc_max,aB_max);
     i++;
  }
}


