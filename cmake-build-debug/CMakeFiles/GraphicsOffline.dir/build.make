# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/nisa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nisa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nisa/CLionProjects/GraphicsOffline

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GraphicsOffline.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphicsOffline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphicsOffline.dir/flags.make

CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o: CMakeFiles/GraphicsOffline.dir/flags.make
CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o: ../1605102_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o -c /home/nisa/CLionProjects/GraphicsOffline/1605102_2.cpp

CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisa/CLionProjects/GraphicsOffline/1605102_2.cpp > CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.i

CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisa/CLionProjects/GraphicsOffline/1605102_2.cpp -o CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.s

# Object files for target GraphicsOffline
GraphicsOffline_OBJECTS = \
"CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o"

# External object files for target GraphicsOffline
GraphicsOffline_EXTERNAL_OBJECTS =

GraphicsOffline: CMakeFiles/GraphicsOffline.dir/1605102_2.cpp.o
GraphicsOffline: CMakeFiles/GraphicsOffline.dir/build.make
GraphicsOffline: CMakeFiles/GraphicsOffline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GraphicsOffline"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphicsOffline.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphicsOffline.dir/build: GraphicsOffline

.PHONY : CMakeFiles/GraphicsOffline.dir/build

CMakeFiles/GraphicsOffline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphicsOffline.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphicsOffline.dir/clean

CMakeFiles/GraphicsOffline.dir/depend:
	cd /home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nisa/CLionProjects/GraphicsOffline /home/nisa/CLionProjects/GraphicsOffline /home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug /home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug /home/nisa/CLionProjects/GraphicsOffline/cmake-build-debug/CMakeFiles/GraphicsOffline.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GraphicsOffline.dir/depend

