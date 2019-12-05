// Compute Blinn-Phong Shading given a material specification, a point on a
// surface and a light direction. Assume the light is white and has a low
// ambient intensity.
//
// Inputs:
//   ka  rgb ambient color
//   kd  rgb diffuse color
//   ks  rgb specular color
//   p  specular exponent (shininess)
//   n  unit surface normal direction
//   v  unit direction from point on object to eye
//   l  unit light direction
// Returns rgb color
vec3 blinn_phong(
  vec3 ka,
  vec3 kd,
  vec3 ks,
  float p,
  vec3 n,
  vec3 v,
  vec3 l)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  vec3 light_intensity = vec3(1,1,1);
  vec3 h = (v + l) / length(v+l);
  vec3 intensity = (ka * light_intensity) + (kd * light_intensity * max(0.0, dot(n,l))) + (ks * light_intensity * pow(max(0.0, dot(n,l)), p));
  return intensity;
  /////////////////////////////////////////////////////////////////////////////
}


