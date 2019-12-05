#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  int total_num_faces = num_faces_u * num_faces_v;
  int total_num_vertices = (num_faces_u + 1) * (num_faces_v + 1);
  V.resize(total_num_vertices,3);
  F.resize(total_num_faces,4);
  UV.resize(total_num_vertices,2);
  UF.resize(total_num_faces,4);
  NV.resize(total_num_vertices,3);
  NF.resize(total_num_faces,4);

  int face_counter = 0;
  int vertex_counter = 0;
  double pi = 3.1415927;
  for (int i = 0; i < num_faces_u + 1; i++){
      for (int j = 0; j < num_faces_v + 1; j++){
          //Setup Face info
          if (i < num_faces_u && j < num_faces_v){
              int v1 = (i) * (num_faces_v + 1) + j;
              int v2 = (i + 1) * (num_faces_v + 1) + j;
              int v3 = (i + 1) * (num_faces_v + 1) + j + 1;
              int v4 = (i) * (num_faces_v + 1) + j + 1;

              F.row(face_counter) = Eigen::RowVector4i(v1,v2,v3,v4);
              UF.row(face_counter) = Eigen::RowVector4i(v1,v2,v3,v4);
              NF.row(face_counter) = Eigen::RowVector4i(v1,v2,v3,v4);
              face_counter++;
          }

          double theta = static_cast<double>(i) / num_faces_u * pi * 2;
          double phi = static_cast<double>(j) / num_faces_v * pi;

          double x = (-sin(phi)) * cos(theta);
          double y = (-sin(phi)) * sin(theta);
          double z = (-cos(phi));

          double u_unit = static_cast<double>(i) / num_faces_u;
          double v_unit = static_cast<double>(j) / num_faces_v;

          V.row(vertex_counter) = Eigen::RowVector3d(x,y,z);
          UV.row(vertex_counter) = Eigen::RowVector2d(u_unit,v_unit);
          NV.row(vertex_counter) = Eigen::RowVector3d(x,y,z);
          vertex_counter ++;

      }
  }



}
