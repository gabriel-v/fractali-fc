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
CMAKE_SOURCE_DIR = /home/penultimo/Projects/Facultate/FC/fractali-opencl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/penultimo/Projects/Facultate/FC/fractali-opencl

# Include any dependencies generated for this target.
include CMakeFiles/PFract.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PFract.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PFract.dir/flags.make

CMakeFiles/PFract.dir/View.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/View.cpp.o: View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PFract.dir/View.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/View.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/View.cpp

CMakeFiles/PFract.dir/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/View.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/View.cpp > CMakeFiles/PFract.dir/View.cpp.i

CMakeFiles/PFract.dir/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/View.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/View.cpp -o CMakeFiles/PFract.dir/View.cpp.s

CMakeFiles/PFract.dir/View.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/View.cpp.o.requires

CMakeFiles/PFract.dir/View.cpp.o.provides: CMakeFiles/PFract.dir/View.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/View.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/View.cpp.o.provides

CMakeFiles/PFract.dir/View.cpp.o.provides.build: CMakeFiles/PFract.dir/View.cpp.o


CMakeFiles/PFract.dir/Compositor.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/Compositor.cpp.o: Compositor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PFract.dir/Compositor.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/Compositor.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/Compositor.cpp

CMakeFiles/PFract.dir/Compositor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/Compositor.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/Compositor.cpp > CMakeFiles/PFract.dir/Compositor.cpp.i

CMakeFiles/PFract.dir/Compositor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/Compositor.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/Compositor.cpp -o CMakeFiles/PFract.dir/Compositor.cpp.s

CMakeFiles/PFract.dir/Compositor.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/Compositor.cpp.o.requires

CMakeFiles/PFract.dir/Compositor.cpp.o.provides: CMakeFiles/PFract.dir/Compositor.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/Compositor.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/Compositor.cpp.o.provides

CMakeFiles/PFract.dir/Compositor.cpp.o.provides.build: CMakeFiles/PFract.dir/Compositor.cpp.o


CMakeFiles/PFract.dir/CLCompositor.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/CLCompositor.cpp.o: CLCompositor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PFract.dir/CLCompositor.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/CLCompositor.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/CLCompositor.cpp

CMakeFiles/PFract.dir/CLCompositor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/CLCompositor.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/CLCompositor.cpp > CMakeFiles/PFract.dir/CLCompositor.cpp.i

CMakeFiles/PFract.dir/CLCompositor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/CLCompositor.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/CLCompositor.cpp -o CMakeFiles/PFract.dir/CLCompositor.cpp.s

CMakeFiles/PFract.dir/CLCompositor.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/CLCompositor.cpp.o.requires

CMakeFiles/PFract.dir/CLCompositor.cpp.o.provides: CMakeFiles/PFract.dir/CLCompositor.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/CLCompositor.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/CLCompositor.cpp.o.provides

CMakeFiles/PFract.dir/CLCompositor.cpp.o.provides.build: CMakeFiles/PFract.dir/CLCompositor.cpp.o


CMakeFiles/PFract.dir/Window.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/Window.cpp.o: Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PFract.dir/Window.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/Window.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/Window.cpp

CMakeFiles/PFract.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/Window.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/Window.cpp > CMakeFiles/PFract.dir/Window.cpp.i

CMakeFiles/PFract.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/Window.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/Window.cpp -o CMakeFiles/PFract.dir/Window.cpp.s

CMakeFiles/PFract.dir/Window.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/Window.cpp.o.requires

CMakeFiles/PFract.dir/Window.cpp.o.provides: CMakeFiles/PFract.dir/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/Window.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/Window.cpp.o.provides

CMakeFiles/PFract.dir/Window.cpp.o.provides.build: CMakeFiles/PFract.dir/Window.cpp.o


CMakeFiles/PFract.dir/CPPCompositor.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/CPPCompositor.cpp.o: CPPCompositor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PFract.dir/CPPCompositor.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/CPPCompositor.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/CPPCompositor.cpp

CMakeFiles/PFract.dir/CPPCompositor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/CPPCompositor.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/CPPCompositor.cpp > CMakeFiles/PFract.dir/CPPCompositor.cpp.i

CMakeFiles/PFract.dir/CPPCompositor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/CPPCompositor.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/CPPCompositor.cpp -o CMakeFiles/PFract.dir/CPPCompositor.cpp.s

CMakeFiles/PFract.dir/CPPCompositor.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/CPPCompositor.cpp.o.requires

CMakeFiles/PFract.dir/CPPCompositor.cpp.o.provides: CMakeFiles/PFract.dir/CPPCompositor.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/CPPCompositor.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/CPPCompositor.cpp.o.provides

CMakeFiles/PFract.dir/CPPCompositor.cpp.o.provides.build: CMakeFiles/PFract.dir/CPPCompositor.cpp.o


CMakeFiles/PFract.dir/main.cpp.o: CMakeFiles/PFract.dir/flags.make
CMakeFiles/PFract.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PFract.dir/main.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PFract.dir/main.cpp.o -c /home/penultimo/Projects/Facultate/FC/fractali-opencl/main.cpp

CMakeFiles/PFract.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PFract.dir/main.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/penultimo/Projects/Facultate/FC/fractali-opencl/main.cpp > CMakeFiles/PFract.dir/main.cpp.i

CMakeFiles/PFract.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PFract.dir/main.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/penultimo/Projects/Facultate/FC/fractali-opencl/main.cpp -o CMakeFiles/PFract.dir/main.cpp.s

CMakeFiles/PFract.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PFract.dir/main.cpp.o.requires

CMakeFiles/PFract.dir/main.cpp.o.provides: CMakeFiles/PFract.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PFract.dir/build.make CMakeFiles/PFract.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PFract.dir/main.cpp.o.provides

CMakeFiles/PFract.dir/main.cpp.o.provides.build: CMakeFiles/PFract.dir/main.cpp.o


# Object files for target PFract
PFract_OBJECTS = \
"CMakeFiles/PFract.dir/View.cpp.o" \
"CMakeFiles/PFract.dir/Compositor.cpp.o" \
"CMakeFiles/PFract.dir/CLCompositor.cpp.o" \
"CMakeFiles/PFract.dir/Window.cpp.o" \
"CMakeFiles/PFract.dir/CPPCompositor.cpp.o" \
"CMakeFiles/PFract.dir/main.cpp.o"

# External object files for target PFract
PFract_EXTERNAL_OBJECTS =

PFract: CMakeFiles/PFract.dir/View.cpp.o
PFract: CMakeFiles/PFract.dir/Compositor.cpp.o
PFract: CMakeFiles/PFract.dir/CLCompositor.cpp.o
PFract: CMakeFiles/PFract.dir/Window.cpp.o
PFract: CMakeFiles/PFract.dir/CPPCompositor.cpp.o
PFract: CMakeFiles/PFract.dir/main.cpp.o
PFract: CMakeFiles/PFract.dir/build.make
PFract: /usr/lib64/libtiff.so
PFract: /usr/lib64/libjpeg.so
PFract: /usr/lib64/libz.so
PFract: /usr/lib64/libpng.so
PFract: /usr/lib64/libz.so
PFract: /usr/lib64/libSM.so
PFract: /usr/lib64/libICE.so
PFract: /usr/lib64/libX11.so
PFract: /usr/lib64/libXext.so
PFract: /usr/lib64/liblapack.so
PFract: /usr/lib64/libblas.so
PFract: /usr/lib64/libblas.so
PFract: /usr/lib64/libGLU.so
PFract: /usr/lib64/libGL.so
PFract: /usr/lib64/libpng.so
PFract: /usr/lib64/libSM.so
PFract: /usr/lib64/libICE.so
PFract: /usr/lib64/libX11.so
PFract: /usr/lib64/libXext.so
PFract: /usr/lib64/liblapack.so
PFract: /usr/lib64/libblas.so
PFract: /usr/lib64/libGLU.so
PFract: /usr/lib64/libGL.so
PFract: /usr/lib64/libSM.so
PFract: /usr/lib64/libICE.so
PFract: /usr/lib64/libX11.so
PFract: /usr/lib64/libXext.so
PFract: /usr/lib64/liblapack.so
PFract: /usr/lib64/libblas.so
PFract: /usr/lib64/libGLU.so
PFract: /usr/lib64/libGL.so
PFract: CMakeFiles/PFract.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable PFract"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PFract.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PFract.dir/build: PFract

.PHONY : CMakeFiles/PFract.dir/build

CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/View.cpp.o.requires
CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/Compositor.cpp.o.requires
CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/CLCompositor.cpp.o.requires
CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/Window.cpp.o.requires
CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/CPPCompositor.cpp.o.requires
CMakeFiles/PFract.dir/requires: CMakeFiles/PFract.dir/main.cpp.o.requires

.PHONY : CMakeFiles/PFract.dir/requires

CMakeFiles/PFract.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PFract.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PFract.dir/clean

CMakeFiles/PFract.dir/depend:
	cd /home/penultimo/Projects/Facultate/FC/fractali-opencl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/penultimo/Projects/Facultate/FC/fractali-opencl /home/penultimo/Projects/Facultate/FC/fractali-opencl /home/penultimo/Projects/Facultate/FC/fractali-opencl /home/penultimo/Projects/Facultate/FC/fractali-opencl /home/penultimo/Projects/Facultate/FC/fractali-opencl/CMakeFiles/PFract.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PFract.dir/depend

