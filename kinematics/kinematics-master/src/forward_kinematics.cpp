#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function


Eigen::Affine3d recursive_transformation(Bone cur_bone,const Skeleton & skeleton){
  if (cur_bone.parent_index == -1){
    return Eigen::Affine3d::Identity() * cur_bone.rest_T * euler_angles_to_transform(cur_bone.xzx) * cur_bone.rest_T.inverse();
  }
  else{
    int parent_index = cur_bone.parent_index;
    Bone parent_bone = skeleton[parent_index];
    Eigen::Affine3d parent = recursive_transformation(parent_bone, skeleton);
    return parent * cur_bone.rest_T * euler_angles_to_transform(cur_bone.xzx) * cur_bone.rest_T.inverse();
  }
}

void forward_kinematics(
  const Skeleton & skeleton,
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  T.resize(skeleton.size(),Eigen::Affine3d::Identity());

  for (int i = 0; i < skeleton.size(); i++){
    Bone cur_bone = skeleton[i];
    //No Parent
    if (cur_bone.parent_index == -1){
      T[i] = Eigen::Affine3d::Identity() * cur_bone.rest_T * euler_angles_to_transform(cur_bone.xzx) * cur_bone.rest_T.inverse();
    }
    else{
      T[i] = recursive_transformation(cur_bone, skeleton);
    }

  }
  /////////////////////////////////////////////////////////////////////////////
}

