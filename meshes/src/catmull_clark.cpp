#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>

std::unordered_map<int, Eigen::RowVector3d> get_face_points(const Eigen::MatrixXd & V,
                                                            const Eigen::MatrixXi & F){
  std::unordered_map<int, Eigen::RowVector3d> face_points;
  for (int i = 0; i < F.rows(); i ++){
    Eigen::RowVector3d face_point(0,0,0);
    for (int j = 0; j < V.rows(); j++){
      face_point += V.row(F(i,j));
    }
    face_points[i] = (face_point.operator/=(4.0));
  }
};


void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  SV = V;
  SF = F;
  if (num_iters == 0){
    return;
  }

  // Step 1: For each face, a face point is created which is the average of all the points of the face
  std::unordered_map<int, Eigen::RowVector3d> face_points = get_face_points(V,F);





  ////////////////////////////////////////////////////////////////////////////
}






