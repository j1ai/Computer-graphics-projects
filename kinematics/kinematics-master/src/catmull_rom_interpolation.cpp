#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  // https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline
  Eigen::Vector3d p0, p1, p2, p3, a1, a2, a3, b1, b2, c;
  double t0, t1, t2, t3;

  if(keyframes.empty()){
    return Eigen::Vector3d(0,0,0);
  }

  t = std::fmod(t, keyframes.back().first);

  //Closet points to t
  int frame_index = 0;
  while (frame_index < keyframes.size()){
    double temp_t = keyframes[frame_index].first;
    if (temp_t > t){
      if (temp_t == keyframes.size() - 1 || temp_t < 2){
          t0 = keyframes[frame_index - 1].first;
          p0 = keyframes[frame_index - 1].second;

          t1 = keyframes[frame_index].first;
          p1 = keyframes[frame_index].second;
          t = (t - t0) / (t1 - t0);
          return t*p0 + (1-t)*p1;
      }
      break;
    }
    frame_index++;
  }

  t0 = keyframes[frame_index - 2].first;
  p0 = keyframes[frame_index - 2].second;

  t1 = keyframes[frame_index - 1].first;
  p1 = keyframes[frame_index - 1].second;

  t2 = keyframes[frame_index].first;
  p2 = keyframes[frame_index].second;

  t3 = keyframes[frame_index + 1].first;
  p3 = keyframes[frame_index + 1].second;

  a1 = p0.operator*=((t1-t)/(t1-t0)) + p1.operator*=((t-t0)/(t1-t0));
  a2 = p1.operator*=((t2-t)/(t2-t1)) + p2.operator*=((t-t1)/(t2-t1));
  a3 = p2.operator*=((t3-t)/(t3-t2)) + p3.operator*=((t-t2)/(t3-t2));

  b1 = a1.operator*=((t2-t)/(t2-t0)) + a2.operator*=((t-t0)/(t2-t0));
  b2 = a2.operator*=((t3-t)/(t3-t1)) + a3.operator*=((t-t1)/(t3-t1));
  c =  b1.operator*=((t2-t)/(t2-t1)) + b2.operator*=((t-t1)/(t2-t1));

  return c;
  /////////////////////////////////////////////////////////////////////////////
}
