# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j1ai/Desktop/CSC418/ray-tracing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j1ai/Desktop/CSC418/ray-tracing/build-release

# Include any dependencies generated for this target.
include CMakeFiles/hw2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw2.dir/flags.make

CMakeFiles/hw2.dir/src/Plane.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/Plane.cpp.o: ../src/Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw2.dir/src/Plane.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/Plane.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/Plane.cpp

CMakeFiles/hw2.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/Plane.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/Plane.cpp > CMakeFiles/hw2.dir/src/Plane.cpp.i

CMakeFiles/hw2.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/Plane.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/Plane.cpp -o CMakeFiles/hw2.dir/src/Plane.cpp.s

CMakeFiles/hw2.dir/src/Plane.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/Plane.cpp.o.requires

CMakeFiles/hw2.dir/src/Plane.cpp.o.provides: CMakeFiles/hw2.dir/src/Plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/Plane.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/Plane.cpp.o.provides

CMakeFiles/hw2.dir/src/Plane.cpp.o.provides.build: CMakeFiles/hw2.dir/src/Plane.cpp.o


CMakeFiles/hw2.dir/src/Sphere.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/Sphere.cpp.o: ../src/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw2.dir/src/Sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/Sphere.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/Sphere.cpp

CMakeFiles/hw2.dir/src/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/Sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/Sphere.cpp > CMakeFiles/hw2.dir/src/Sphere.cpp.i

CMakeFiles/hw2.dir/src/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/Sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/Sphere.cpp -o CMakeFiles/hw2.dir/src/Sphere.cpp.s

CMakeFiles/hw2.dir/src/Sphere.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/Sphere.cpp.o.requires

CMakeFiles/hw2.dir/src/Sphere.cpp.o.provides: CMakeFiles/hw2.dir/src/Sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/Sphere.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/Sphere.cpp.o.provides

CMakeFiles/hw2.dir/src/Sphere.cpp.o.provides.build: CMakeFiles/hw2.dir/src/Sphere.cpp.o


CMakeFiles/hw2.dir/src/Triangle.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/Triangle.cpp.o: ../src/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw2.dir/src/Triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/Triangle.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/Triangle.cpp

CMakeFiles/hw2.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/Triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/Triangle.cpp > CMakeFiles/hw2.dir/src/Triangle.cpp.i

CMakeFiles/hw2.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/Triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/Triangle.cpp -o CMakeFiles/hw2.dir/src/Triangle.cpp.s

CMakeFiles/hw2.dir/src/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/Triangle.cpp.o.requires

CMakeFiles/hw2.dir/src/Triangle.cpp.o.provides: CMakeFiles/hw2.dir/src/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/Triangle.cpp.o.provides

CMakeFiles/hw2.dir/src/Triangle.cpp.o.provides.build: CMakeFiles/hw2.dir/src/Triangle.cpp.o


CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o: ../src/TriangleSoup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/TriangleSoup.cpp

CMakeFiles/hw2.dir/src/TriangleSoup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/TriangleSoup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/TriangleSoup.cpp > CMakeFiles/hw2.dir/src/TriangleSoup.cpp.i

CMakeFiles/hw2.dir/src/TriangleSoup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/TriangleSoup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/TriangleSoup.cpp -o CMakeFiles/hw2.dir/src/TriangleSoup.cpp.s

CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.requires

CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.provides: CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.provides

CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.provides.build: CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o


CMakeFiles/hw2.dir/src/first_hit.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/first_hit.cpp.o: ../src/first_hit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hw2.dir/src/first_hit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/first_hit.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/first_hit.cpp

CMakeFiles/hw2.dir/src/first_hit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/first_hit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/first_hit.cpp > CMakeFiles/hw2.dir/src/first_hit.cpp.i

CMakeFiles/hw2.dir/src/first_hit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/first_hit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/first_hit.cpp -o CMakeFiles/hw2.dir/src/first_hit.cpp.s

CMakeFiles/hw2.dir/src/first_hit.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/first_hit.cpp.o.requires

CMakeFiles/hw2.dir/src/first_hit.cpp.o.provides: CMakeFiles/hw2.dir/src/first_hit.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/first_hit.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/first_hit.cpp.o.provides

CMakeFiles/hw2.dir/src/first_hit.cpp.o.provides.build: CMakeFiles/hw2.dir/src/first_hit.cpp.o


CMakeFiles/hw2.dir/src/viewing_ray.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/viewing_ray.cpp.o: ../src/viewing_ray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hw2.dir/src/viewing_ray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/viewing_ray.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/viewing_ray.cpp

CMakeFiles/hw2.dir/src/viewing_ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/viewing_ray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/viewing_ray.cpp > CMakeFiles/hw2.dir/src/viewing_ray.cpp.i

CMakeFiles/hw2.dir/src/viewing_ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/viewing_ray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/viewing_ray.cpp -o CMakeFiles/hw2.dir/src/viewing_ray.cpp.s

CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.requires

CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.provides: CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.provides

CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.provides.build: CMakeFiles/hw2.dir/src/viewing_ray.cpp.o


CMakeFiles/hw2.dir/src/write_ppm.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/write_ppm.cpp.o: ../src/write_ppm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hw2.dir/src/write_ppm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/write_ppm.cpp.o -c /home/j1ai/Desktop/CSC418/ray-tracing/src/write_ppm.cpp

CMakeFiles/hw2.dir/src/write_ppm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/write_ppm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/ray-tracing/src/write_ppm.cpp > CMakeFiles/hw2.dir/src/write_ppm.cpp.i

CMakeFiles/hw2.dir/src/write_ppm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/write_ppm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/ray-tracing/src/write_ppm.cpp -o CMakeFiles/hw2.dir/src/write_ppm.cpp.s

CMakeFiles/hw2.dir/src/write_ppm.cpp.o.requires:

.PHONY : CMakeFiles/hw2.dir/src/write_ppm.cpp.o.requires

CMakeFiles/hw2.dir/src/write_ppm.cpp.o.provides: CMakeFiles/hw2.dir/src/write_ppm.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/write_ppm.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/write_ppm.cpp.o.provides

CMakeFiles/hw2.dir/src/write_ppm.cpp.o.provides.build: CMakeFiles/hw2.dir/src/write_ppm.cpp.o


# Object files for target hw2
hw2_OBJECTS = \
"CMakeFiles/hw2.dir/src/Plane.cpp.o" \
"CMakeFiles/hw2.dir/src/Sphere.cpp.o" \
"CMakeFiles/hw2.dir/src/Triangle.cpp.o" \
"CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o" \
"CMakeFiles/hw2.dir/src/first_hit.cpp.o" \
"CMakeFiles/hw2.dir/src/viewing_ray.cpp.o" \
"CMakeFiles/hw2.dir/src/write_ppm.cpp.o"

# External object files for target hw2
hw2_EXTERNAL_OBJECTS =

libhw2.a: CMakeFiles/hw2.dir/src/Plane.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/Sphere.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/Triangle.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/first_hit.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/viewing_ray.cpp.o
libhw2.a: CMakeFiles/hw2.dir/src/write_ppm.cpp.o
libhw2.a: CMakeFiles/hw2.dir/build.make
libhw2.a: CMakeFiles/hw2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libhw2.a"
	$(CMAKE_COMMAND) -P CMakeFiles/hw2.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw2.dir/build: libhw2.a

.PHONY : CMakeFiles/hw2.dir/build

CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/Plane.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/Sphere.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/Triangle.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/TriangleSoup.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/first_hit.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/viewing_ray.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/write_ppm.cpp.o.requires

.PHONY : CMakeFiles/hw2.dir/requires

CMakeFiles/hw2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw2.dir/clean

CMakeFiles/hw2.dir/depend:
	cd /home/j1ai/Desktop/CSC418/ray-tracing/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j1ai/Desktop/CSC418/ray-tracing /home/j1ai/Desktop/CSC418/ray-tracing /home/j1ai/Desktop/CSC418/ray-tracing/build-release /home/j1ai/Desktop/CSC418/ray-tracing/build-release /home/j1ai/Desktop/CSC418/ray-tracing/build-release/CMakeFiles/hw2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw2.dir/depend

