#include "triangle_area_normal.h"
#include <Eigen/Geometry>

Eigen::RowVector3d triangle_area_normal(
  const Eigen::RowVector3d & a, 
  const Eigen::RowVector3d & b, 
  const Eigen::RowVector3d & c)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  ////////////////////////////////////////////////////////////////////////////
  Eigen::RowVector3d n = ((b-a).cross(c-a)).normalized();
  double area = ((b-a).cross(c-a)).norm() / 2.0;
  return (n*area);
}
