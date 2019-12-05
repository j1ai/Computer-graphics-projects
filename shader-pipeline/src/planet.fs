// Generate a procedural planet and orbiting moon. Use layers of (improved)
// Perlin noise to generate planetary features such as vegetation, gaseous
// clouds, mountains, valleys, ice caps, rivers, oceans. Don't forget about the
// moon. Use `animation_seconds` in your noise input to create (periodic)
// temporal effects.
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
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
      float PI = 3.1415927;
      mat4 moon_model = model(is_moon, animation_seconds);
      float theta = (PI / 2) * animation_seconds;
      vec4 light_pos = vec4(8 * cos(theta), 6, 8 * sin(theta), 1);
      vec4 p_light = view * vec4(8 * cos(theta), 6, 8 * sin(theta), 1);

      vec3 p_light_3d = vec3(p_light.x, p_light.y, p_light.z);
      vec3 view_point_3d = vec3(view_pos_fs_in.x, view_pos_fs_in.y, view_pos_fs_in.z);
      //float noise = abs(sin(20*perlin_noise(sphere_fs_in)+2*sphere_fs_in.y));

      vec3 moon_ka = vec3(0.01,0.01,0.01);
      vec3 moon_kd = vec3(0.5,0.5,0.5);
      vec3 moon_ks = vec3(1,1,1);
      vec3 not_moon_ka = vec3(0.05,0.05,0.05);
      vec3 not_moon_kd = vec3(0.2,0.1,0.8);
      vec3 not_moon_ks = vec3(1,1,1);

      vec3 T,B;
      tangent(sphere_fs_in, T, B);
      vec3 bump_up = bump_position(is_moon, sphere_fs_in);
      //From ReadME
      //∂ 𝐩∂ 𝐓×∂ 𝐩∂ 𝐁≈(𝐩̃ (𝐩+𝛆𝐓)−𝐩̃ (𝐩)ε)×(𝐩̃ (𝐩+𝛆𝐁)−𝐩̃ (𝐩)ε)
      vec3 bump_up_normal = normalize(cross((bump_position(is_moon, sphere_fs_in + T*0.0001) - bump_up)/0.0001, (bump_position(is_moon, sphere_fs_in + B*0.0001) - bump_up)/0.0001));

      if (dot(sphere_fs_in, bump_up_normal) < 0){
         bump_up_normal = -bump_up_normal;
      }

      vec3 surface_normal = (inverse(transpose(view * moon_model)) * vec4(bump_up_normal, 1.0)).xyz;


      if (is_moon){
        float cur_height = bump_height(is_moon, sphere_fs_in);
        if (cur_height < 0.5){
           not_moon_ka = vec3(0.1*sphere_fs_in.x + sin(animation_seconds*PI/4),1*sphere_fs_in.y ,0.1*sphere_fs_in.z);
           not_moon_kd = vec3(0.2,0.1,0.8*sphere_fs_in.x);
           not_moon_ks = vec3(0.1*sphere_fs_in.x + sin(animation_seconds*PI/4),1,1);
        }
        color = blinn_phong(moon_ka,moon_kd,moon_ks,500,normalize(surface_normal),normalize(-view_point_3d),normalize(p_light_3d-view_point_3d));
      }
      else{
        float cur_height = bump_height(is_moon, sphere_fs_in);
        if (cur_height > 0.1 && cur_height < 0.5 ){
           not_moon_ka = vec3(1*sphere_fs_in.x + sin(animation_seconds*PI/4),0,0);
           not_moon_kd = vec3(0,1,1);
           not_moon_ks = vec3(1,1,0);
        }
        if (cur_height > 0.5){
           not_moon_ka = vec3(0.1*sphere_fs_in.x + sin(animation_seconds*PI/4),1*sphere_fs_in.y + cos(animation_seconds*PI/4),0.1*sphere_fs_in.z);
           not_moon_kd = vec3(0.2,0.1,0.8);
           not_moon_ks = vec3(0.1*sphere_fs_in.x + sin(animation_seconds*PI/4),1,1);
        }

        color = blinn_phong(not_moon_ka,not_moon_kd,not_moon_ks,500,normalize(surface_normal),normalize(-view_point_3d),normalize(p_light_3d-view_point_3d));
      }
  /////////////////////////////////////////////////////////////////////////////
}
