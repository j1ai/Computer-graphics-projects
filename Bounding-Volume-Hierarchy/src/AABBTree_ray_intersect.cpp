#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //Based On PseudoCode from the Textbook bvh-node::hit function
  if(ray_intersect_box(ray,this->box,min_t,max_t)) {
    std::shared_ptr<Object> left_descendant, right_descendant;
    bool left_hit, right_hit;
    double left_t, right_t;

    left_hit = ((this->left != NULL) && (this->left->ray_intersect(ray, min_t, max_t, left_t, left_descendant)));
    right_hit = ((this->right != NULL) && (this->right->ray_intersect(ray, min_t, max_t, right_t, right_descendant)));

    if(left_descendant == NULL && left_hit){
        left_descendant = this->left;
    }

    if(right_descendant == NULL && right_hit){
        right_descendant = this->right;
    }

    if (right_hit && left_hit) {

      if (left_t < right_t) {
        descendant = left_descendant;
        t = left_t;
      } else {
        descendant = right_descendant;
        t = right_t;
      }
      return true;

    }

    else if (left_hit) {
      descendant = left_descendant;
      t = left_t;
      return true;
    }

    else if (right_hit) {
      descendant = right_descendant;
      t = right_t;
      return true;
    }
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

