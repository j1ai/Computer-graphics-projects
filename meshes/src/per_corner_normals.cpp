#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////
  std::vector<std::vector<int> >VF;
  vertex_triangle_adjacency(F, V.rows(), VF);
  double pi = 3.1415927;

  for (int i = 0; i < F.rows(); i++){

    Eigen::RowVector3d v1 = V.row(F(i,0));
    Eigen::RowVector3d v2 = V.row(F(i,1));
    Eigen::RowVector3d v3 = V.row(F(i,2));
    Eigen::RowVector3d cur_face_normal = triangle_area_normal(v1,v2,v3);

    for (int j = 0; j < F.cols(); j++){
      double cur_area = 0;
      Eigen::RowVector3d cur_normal(0,0,0);

      for (int f : VF[F(i,j)]){
          Eigen::RowVector3d v4 = V.row(F(f,0));
          Eigen::RowVector3d v5 = V.row(F(f,1));
          Eigen::RowVector3d v6 = V.row(F(f,2));
          Eigen::RowVector3d cur_adjface_normal = triangle_area_normal(v4,v5,v6);

          double face_normals_dp = cur_face_normal.normalized().dot(cur_adjface_normal.normalized());

          if (face_normals_dp > cos(corner_threshold * pi / 180.0)){
              cur_normal += cur_adjface_normal;
              cur_area += (((v5-v4).cross(v6-v4)).norm()) / 2.0;
          }
      }
      N.row(i * 3 + j) = (cur_normal / cur_area).normalized();
    }
  }
}
