#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
    //Based on pseudocode from ReadMe
    std::list<std::pair<std::shared_ptr<AABBTree>,std::shared_ptr<AABBTree>>> queue;
    if(box_box_intersect(rootA->box,rootB->box)){
        queue.emplace_back(std::make_pair(rootA,rootB));
    }
    std::shared_ptr<AABBTree> node_A;
    std::shared_ptr<AABBTree> node_B;

    while(!queue.empty()){
        node_A = queue.front().first;
        node_B = queue.front().second;
        queue.pop_front();

        //When both nodes are leaves
        if(node_A->num_leaves <= 2 && node_B->num_leaves <= 2){
            if(node_A->left && node_B->left){
                if (box_box_intersect(node_A->left->box,node_B->left->box)){
                    leaf_pairs.emplace_back(node_A->left, node_B->left);
                }
            }

            else if(node_A->left && node_B->right){
                if (box_box_intersect(node_A->left->box,node_B->right->box)){
                    leaf_pairs.emplace_back(node_A->left, node_B->right);
                }
            }

            else if(node_A->right && node_B->right){
                if (box_box_intersect(node_A->right->box,node_B->right->box)){
                    leaf_pairs.emplace_back(node_A->right, node_B->right);
                }
            }

            else if(node_A->right && node_B->left){
                if (box_box_intersect(node_A->right->box,node_B->left->box)){
                    leaf_pairs.emplace_back(node_A->right, node_B->left);
                }
            }
        }

            //if node_A is a leaf
        else if (node_A->num_leaves <= 2){
            if(box_box_intersect(node_A->box,node_B->left->box)){
                queue.emplace_back(std::make_pair(node_A, std::static_pointer_cast<AABBTree>(node_B->left)));
            }
            if(box_box_intersect(node_A->box,node_B->right->box)){
                queue.emplace_back(std::make_pair(node_A, std::static_pointer_cast<AABBTree>(node_B->right)));
            }
        }

            //if node_B is a leaf
        else if (node_B->num_leaves <= 2){
            if(box_box_intersect(node_B->box,node_A->left->box)){
                queue.emplace_back(std::make_pair(node_B, std::static_pointer_cast<AABBTree>(node_A->left)));
            }
            if(box_box_intersect(node_B->box,node_A->right->box)){
                queue.emplace_back(std::make_pair(node_B, std::static_pointer_cast<AABBTree>(node_A->right)));
            }
        }

        else{
            if(box_box_intersect(node_A->left->box,node_B->left->box)){
                queue.emplace_back(std::make_pair(std::static_pointer_cast<AABBTree>(node_A->left), std::static_pointer_cast<AABBTree>(node_B->left)));
            }
            if(box_box_intersect(node_A->right->box,node_B->right->box)){
                queue.emplace_back(std::make_pair(std::static_pointer_cast<AABBTree>(node_A->right), std::static_pointer_cast<AABBTree>(node_B->right)));
            }
            if(box_box_intersect(node_A->left->box,node_B->right->box)){
                queue.emplace_back(std::make_pair(std::static_pointer_cast<AABBTree>(node_A->left), std::static_pointer_cast<AABBTree>(node_B->right)));
            }
            if(box_box_intersect(node_A->right->box,node_B->left->box)){
                queue.emplace_back(std::make_pair(std::static_pointer_cast<AABBTree>(node_A->right), std::static_pointer_cast<AABBTree>(node_B->left)));
            }
        }

    }
}
