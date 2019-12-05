// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
out vec3 color;
// expects: PI, blinn_phong
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  float PI = 3.1415927;
  float theta = (PI / 2) * animation_seconds;
  vec4 light_pos = vec4(8 * cos(theta), 6, 8 * sin(theta), 1);
  vec4 p_light = view * vec4(8 * cos(theta), 6, 8 * sin(theta), 1);

  vec3 p_light_3d = vec3(p_light.x, p_light.y, p_light.z);
  vec3 view_point_3d = vec3(view_pos_fs_in.x, view_pos_fs_in.y, view_pos_fs_in.z);

  vec3 moon_ka = vec3(0.01,0.01,0.01);
  vec3 moon_kd = vec3(0.5,0.5,0.5);
  vec3 moon_ks = vec3(1,1,1);
  vec3 not_moon_ka = vec3(0.01,0.01,0.01);
  vec3 not_moon_kd = vec3(0.2,0.1,0.8);
  vec3 not_moon_ks = vec3(1,1,1);

  if (is_moon){
    color = blinn_phong(moon_ka,moon_kd,moon_ks,500,normalize(normal_fs_in),normalize(-view_point_3d),normalize(p_light_3d-view_point_3d));
  }
  else{
    color = blinn_phong(not_moon_ka,not_moon_kd,not_moon_ks,500,normalize(normal_fs_in),normalize(-view_point_3d),normalize(p_light_3d-view_point_3d));
  }
  /////////////////////////////////////////////////////////////////////////////
}
