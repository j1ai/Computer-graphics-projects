#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
  //Using lambda to compare the elements
    //From cppreference docummentation
    //Algorithm from ReadMe file
  auto cmp = [](std::pair<double, std::shared_ptr<AABBTree>> pair1, std::pair<double, std::shared_ptr<AABBTree>> pair2)
  {return pair1.first > pair2.first;};
  std::priority_queue<std::pair<double, std::shared_ptr<AABBTree>>, std::vector<std::pair<double, std::shared_ptr<AABBTree>>>, decltype(cmp) > pq(cmp);
  sqrd = std::numeric_limits<double>::infinity();
  double distance = point_box_squared_distance(query,root->box);
  pq.emplace(distance,root);
  //std::shared_ptr<AABBTree> cur_node = std::make_shared<AABBTree>();
  double cur_distance, left_distance, right_distance;
  std::shared_ptr<AABBTree> cur_node;

    while(!pq.empty()){
    cur_node = pq.top().second;
    cur_distance = pq.top().first;
    pq.pop();

    if (cur_distance < sqrd){
      //If number of leaves greater than 2, then its subtree must not be a leaf
      if (cur_node->num_leaves <= 2){
        sqrd = cur_distance;
        if(cur_node->left != NULL){
          double left_sqrd;
          std::shared_ptr<Object> left_descendant;
          left_distance = cur_node->left->point_squared_distance(query,min_sqrd,max_sqrd,left_sqrd,left_descendant);
          if(left_distance < sqrd){
            sqrd = left_distance;
            descendant = left_descendant;
          }
        }

        if(cur_node->right != NULL){
          double right_sqrd;
          std::shared_ptr<Object> right_descendant;
          right_distance = cur_node->right->point_squared_distance(query,min_sqrd,max_sqrd,right_sqrd,right_descendant);
          if(right_distance < sqrd){
            sqrd = right_distance;
            descendant = right_descendant;
          }
        }

      }

      else{
        left_distance = point_box_squared_distance(query,cur_node->left->box);
        right_distance = point_box_squared_distance(query,cur_node->right->box);
        pq.emplace(left_distance, std::static_pointer_cast<AABBTree>(cur_node->left));
        pq.emplace(right_distance, std::static_pointer_cast<AABBTree>(cur_node->right));
      }
    }

  }


  if (descendant == NULL){
    return false;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
