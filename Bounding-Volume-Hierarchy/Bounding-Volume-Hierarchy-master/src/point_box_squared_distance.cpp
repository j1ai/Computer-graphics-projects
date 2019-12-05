#include "point_box_squared_distance.h"

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  double dx,dy,dz;
  dx = fmax((box.min_corner[0] - query[0]), (query[0] - box.max_corner[0]));
  dy = fmax((box.min_corner[1] - query[1]), (query[1] - box.max_corner[1]));
  dz = fmax((box.min_corner[2] - query[2]), (query[2] - box.max_corner[2]));
  return ((dx*dx) + (dy*dy) + (dz*dz));
  ////////////////////////////////////////////////////////////////////////////
}
