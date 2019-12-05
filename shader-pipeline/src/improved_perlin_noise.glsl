// Given a 3d position as a seed, compute an even smoother procedural noise
// value. "Improving Noise" [Perlin 2002].
//
// Inputs:
//   st  3D seed
// Values between  -½ and ½ ?
//
// expects: random_direction, improved_smooth_step
float improved_perlin_noise( vec3 st) 
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
  float floorx = floor(st.x);
  float floory = floor(st.y);
  float floorz = floor(st.z);

  // All 8 corners
  vec3 a = vec3(floorx,floory,floorz);
  vec3 b = vec3(floorx+1,floory,floorz);
  vec3 c = vec3(floorx,floory+1,floorz);
  vec3 d = vec3(floorx+1,floory+1,floorz);
  vec3 e = vec3(floorx,floory,floorz+1);
  vec3 f = vec3(floorx+1,floory,floorz+1);
  vec3 g = vec3(floorx,floory+1,floorz+1);
  vec3 h = vec3(floorx+1,floory+1,floorz+1);

  //random direction for all corners
  vec3 ra = random_direction(a);
  vec3 rb = random_direction(b);
  vec3 rc = random_direction(c);
  vec3 rd = random_direction(d);
  vec3 re = random_direction(e);
  vec3 rf = random_direction(f);
  vec3 rg = random_direction(g);
  vec3 rh = random_direction(h);

  //Calculate all the projections
  float dp1 = dot(vec3(st.x-a.x, st.y-a.y, st.z-a.z), ra);
  float dp2 = dot(vec3(st.x-b.x, st.y-b.y, st.z-b.z), rb);
  float dp3 = dot(vec3(st.x-c.x, st.y-c.y, st.z-c.z), rc);
  float dp4 = dot(vec3(st.x-d.x, st.y-d.y, st.z-d.z), rd);
  float dp5 = dot(vec3(st.x-e.x, st.y-e.y, st.z-e.z), re);
  float dp6 = dot(vec3(st.x-f.x, st.y-f.y, st.z-f.z), rf);
  float dp7 = dot(vec3(st.x-g.x, st.y-g.y, st.z-g.z), rg);
  float dp8 = dot(vec3(st.x-h.x, st.y-h.y, st.z-h.z), rh);
  vec3 smooth_f = improved_smooth_step(fract(st));

  return mix( mix(mix(dp1,dp2,smooth_f.x), mix(dp3,dp4,smooth_f.x), smooth_f.y),mix(mix(dp5,dp6,smooth_f.x), mix(dp7,dp8,smooth_f.x), smooth_f.y), smooth_f.z);
  /////////////////////////////////////////////////////////////////////////////
}

