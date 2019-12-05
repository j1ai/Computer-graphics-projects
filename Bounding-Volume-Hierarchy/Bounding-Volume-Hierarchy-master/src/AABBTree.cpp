#include "AABBTree.h"
#include "insert_box_into_box.h"

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
    //Based on pseudocode from Textbook

    if(objects.empty()){
        this->right = NULL;
        this->left = NULL;
    }
    else if (objects.size() == 1){
        this->left = objects[0];
        this->right = NULL;
        insert_box_into_box(this->left->box,this->box);
    }
    else if (objects.size() == 2){
        this->left = objects[0];
        this->right = objects[1];
        insert_box_into_box(this->left->box,this->box);
        insert_box_into_box(this->right->box,this->box);
    }
    else{
        for(std::shared_ptr<Object> obj : objects){
            insert_box_into_box(obj->box, this->box);
        }

        int longest_axis;
        double max_distance = -std::numeric_limits<int>::infinity();
        int axis = 0;

        while (axis < 3){
            double temp_distance = this->box.max_corner[axis] - this->box.min_corner[axis];
            if (temp_distance > max_distance){
                max_distance = temp_distance;
                longest_axis = axis;
            }
            axis++;
        }

        Eigen::RowVector3d objects_center = this->box.center();
        double m_split = objects_center[longest_axis];

        std::vector<std::shared_ptr<Object> > left_subtree, right_subtree;
        for(std::shared_ptr<Object> obj : objects){
            if(obj->box.center()[longest_axis] >= m_split){
                right_subtree.emplace_back(obj);
            }
            else{
                left_subtree.emplace_back(obj);
            }
        }

        if (left_subtree.empty()){
            std::shared_ptr<Object> last_child = right_subtree.back();
            right_subtree.pop_back();
            left_subtree.emplace_back(last_child);
        }
        else if (right_subtree.empty()){
            std::shared_ptr<Object> last_child = left_subtree.back();
            left_subtree.pop_back();
            right_subtree.emplace_back(last_child);
        }

        this->left = std::make_shared<AABBTree>(left_subtree, a_depth+1);
        this->right = std::make_shared<AABBTree>(right_subtree, a_depth+1);

    }
}
