# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/j1ai/Downloads/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/j1ai/Downloads/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j1ai/Desktop/CSC418/meshes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j1ai/Desktop/CSC418/meshes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/obj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/obj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/obj.dir/flags.make

CMakeFiles/obj.dir/obj.cpp.o: CMakeFiles/obj.dir/flags.make
CMakeFiles/obj.dir/obj.cpp.o: ../obj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j1ai/Desktop/CSC418/meshes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/obj.dir/obj.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/obj.dir/obj.cpp.o -c /home/j1ai/Desktop/CSC418/meshes/obj.cpp

CMakeFiles/obj.dir/obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/obj.dir/obj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j1ai/Desktop/CSC418/meshes/obj.cpp > CMakeFiles/obj.dir/obj.cpp.i

CMakeFiles/obj.dir/obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/obj.dir/obj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j1ai/Desktop/CSC418/meshes/obj.cpp -o CMakeFiles/obj.dir/obj.cpp.s

CMakeFiles/obj.dir/obj.cpp.o.requires:

.PHONY : CMakeFiles/obj.dir/obj.cpp.o.requires

CMakeFiles/obj.dir/obj.cpp.o.provides: CMakeFiles/obj.dir/obj.cpp.o.requires
	$(MAKE) -f CMakeFiles/obj.dir/build.make CMakeFiles/obj.dir/obj.cpp.o.provides.build
.PHONY : CMakeFiles/obj.dir/obj.cpp.o.provides

CMakeFiles/obj.dir/obj.cpp.o.provides.build: CMakeFiles/obj.dir/obj.cpp.o


# Object files for target obj
obj_OBJECTS = \
"CMakeFiles/obj.dir/obj.cpp.o"

# External object files for target obj
obj_EXTERNAL_OBJECTS =

obj: CMakeFiles/obj.dir/obj.cpp.o
obj: CMakeFiles/obj.dir/build.make
obj: libcore.a
obj: glfw/src/libglfw3.a
obj: /usr/lib/x86_64-linux-gnu/librt.so
obj: /usr/lib/x86_64-linux-gnu/libm.so
obj: /usr/lib/x86_64-linux-gnu/libX11.so
obj: stb_image/libigl_stb_image.a
obj: /usr/lib/x86_64-linux-gnu/libGL.so
obj: glad/libglad.a
obj: CMakeFiles/obj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j1ai/Desktop/CSC418/meshes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable obj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/obj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/obj.dir/build: obj

.PHONY : CMakeFiles/obj.dir/build

CMakeFiles/obj.dir/requires: CMakeFiles/obj.dir/obj.cpp.o.requires

.PHONY : CMakeFiles/obj.dir/requires

CMakeFiles/obj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/obj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/obj.dir/clean

CMakeFiles/obj.dir/depend:
	cd /home/j1ai/Desktop/CSC418/meshes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j1ai/Desktop/CSC418/meshes /home/j1ai/Desktop/CSC418/meshes /home/j1ai/Desktop/CSC418/meshes/cmake-build-debug /home/j1ai/Desktop/CSC418/meshes/cmake-build-debug /home/j1ai/Desktop/CSC418/meshes/cmake-build-debug/CMakeFiles/obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/obj.dir/depend
