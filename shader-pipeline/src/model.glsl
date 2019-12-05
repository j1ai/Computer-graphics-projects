// Construct the model transformation matrix. The moon should orbit around the
// origin. The other object should stay still.
//
// Inputs:
//   is_moon  whether we're considering the moon
//   time  seconds on animation clock
// Returns affine model transformation as 4x4 matrix
//
// expects: identity, rotate_about_y, translate, PI
mat4 model(bool is_moon, float time)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  float PI = 3.1415927;
  if (is_moon){
    return rotate_about_y((PI / 2.0) * time);
  }
  else{
    return identity();
  }
  /////////////////////////////////////////////////////////////////////////////
}
