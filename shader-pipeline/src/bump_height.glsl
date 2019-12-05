// Create a bumpy surface by using procedural noise to generate a height (
// displacement in normal direction).
//
// Inputs:
//   is_moon  whether we're looking at the moon or centre planet
//   s  3D position of seed for noise generation
// Returns elevation adjust along normal (values between -0.1 and 0.1 are
//   reasonable.
float bump_height( bool is_moon, vec3 s)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  if(is_moon){
    return smooth_heaviside(improved_perlin_noise(2*s), 10);
  }
  else{
    return smooth_heaviside(improved_perlin_noise(4*s), 100);
  }
  /////////////////////////////////////////////////////////////////////////////
}
