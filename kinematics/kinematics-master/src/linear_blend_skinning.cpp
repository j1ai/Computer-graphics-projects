#include "linear_blend_skinning.h"

void linear_blend_skinning(
  const Eigen::MatrixXd & V,
  const Skeleton & skeleton,
  const std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T,
  const Eigen::MatrixXd & W,
  Eigen::MatrixXd & U)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  U = Eigen::MatrixXd::Zero(V.size(), 3);

  for (int i = 0; i < V.rows(); i++){
    Eigen::Vector4d rest_vertex = Eigen::Vector4d(V(i,0),V(i,1),V(i,2), 1);
    Eigen::Vector4d pose_mesh = Eigen::Vector4d::Zero();

      for (int j = 0; j < skeleton.size(); j++){
      int skeleton_weight_index = skeleton[j].weight_index;
      if(skeleton_weight_index != -1){
          pose_mesh += T[j] * rest_vertex * W(i,skeleton_weight_index);
      }
    }

    U(i,0) = pose_mesh[0];
    U(i,1) = pose_mesh[1];
    U(i,2) = pose_mesh[2];
  }
  /////////////////////////////////////////////////////////////////////////////
}
