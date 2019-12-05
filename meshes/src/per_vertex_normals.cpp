#include <unordered_map>
#include <list>
#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  std::unordered_map<int, std::list<int>> vertex_adj_faces;

  for (int i = 0; i < F.rows(); i++){
      for (int j = 0; j < F.cols(); j++){
          vertex_adj_faces[F(i,j)].emplace_back(i);
      }
  }

  int counter = 0;
  while (counter < V.rows()){
      double cur_area = 0;
      Eigen::RowVector3d cur_normal(0,0,0);

      for (int f : vertex_adj_faces[counter]){
          Eigen::RowVector3d v1 = V.row(F(f,0));
          Eigen::RowVector3d v2 = V.row(F(f,1));
          Eigen::RowVector3d v3 = V.row(F(f,2));

          cur_normal += triangle_area_normal(v1, v2, v3);
          cur_area += (((v2-v1).cross(v3-v1)).norm()) / 2.0;;
      }

      N.row(counter) = (cur_normal / cur_area).normalized();
      counter ++;
  }

}
