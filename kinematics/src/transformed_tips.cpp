#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton, 
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > T;
  forward_kinematics(skeleton,T);
  Eigen::VectorXd bone_tips = Eigen::VectorXd::Zero(3*b.size());
  for(int i = 0; i < b.size(); i++){
    int bone_index = b[i];
    Bone cur_bone = skeleton[bone_index];
    Eigen::Vector4d tip_length = Eigen::Vector4d(cur_bone.length, 0, 0, 1);
    Eigen::Vector4d tip = T[bone_index] * cur_bone.rest_T * tip_length;
    bone_tips[3*i] = tip[0];
    bone_tips[3*i + 1] = tip[1];
    bone_tips[3*i + 2] = tip[2];
  }
  return bone_tips;
  /////////////////////////////////////////////////////////////////////////////
}
