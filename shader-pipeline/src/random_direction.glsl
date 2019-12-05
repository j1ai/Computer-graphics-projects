// Generate a pseudorandom unit 3D vector
// 
// Inputs:
//   seed  3D seed
// Returns psuedorandom, unit 3D vector drawn from uniform distribution over
// the unit sphere (assuming random2 is uniform over [0,1]²).
//
// expects: random2.glsl, PI.glsl
vec3 random_direction( vec3 seed)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  //https://www.scratchapixel.com/lessons/procedural-generation-virtual-worlds/perlin-noise-part-2/perlin-noise
  float PI = 3.1415927;
  vec2 random_2d_seed = random2(seed);
  float theta = PI * random_2d_seed.x;
  float phi = 2 * PI * random_2d_seed.y;

  float x = cos(phi) * sin(theta);
  float y = sin(phi) * sin(theta);
  float z = cos(theta);

  return normalize(vec3(x,y,z));
  /////////////////////////////////////////////////////////////////////////////
}
