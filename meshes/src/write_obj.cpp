#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

    std::ofstream objfile(filename);
    if (!objfile){
        std::cout << "Failed to open the file" << filename << std::endl;
        return false;
    }

    for (int i = 0; i < V.rows(); ++i) {
        objfile << "v " << V(i,0) << " " << V(i,1) << " " << V(i,2) << "\n";
    }

    for (int i = 0; i < UV.rows(); ++i) {
        objfile << "vt " << UV(i,0) << " " << UV(i,1)  << "\n";
    }

    for (int i = 0; i < NV.rows(); ++i) {
        objfile << "vn " << NV(i,0) << " " << NV(i,1) << " " << NV(i,2) << "\n";
    }

    for (int x = 0; x < F.rows(); ++x) {
        objfile << "f ";
        for (int y = 0; y < F.cols(); ++y) {
            objfile << F(x,y) + 1 << "/" << UF(x,y) + 1 << "/" << NF(x,y) + 1 << " ";
        }
        objfile << "\n";
    }

    objfile.close();
    if (!objfile.is_open()){
        return true;
    }
  return false;
}
