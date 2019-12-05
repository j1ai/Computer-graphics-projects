// Input:
//   N  3D unit normal vector
// Outputs:
//   T  3D unit tangent vector
//   B  3D unit bitangent vector
void tangent(in vec3 N, out vec3 T, out vec3 B)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  vec3 cross1 = cross(N,vec3(0,0,1));
  vec3 cross2 = cross(N,vec3(0,1,0));
  if (length(cross2) > length(cross1)){
    T = normalize(cross1);
  }
  else{
    T = normalize(cross2);
  }
  B = normalize(cross(T,N));
  /////////////////////////////////////////////////////////////////////////////
}
