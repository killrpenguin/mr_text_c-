# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/Programming/cpp_dev/vulkan_triangle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Programming/cpp_dev/vulkan_triangle

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include docs/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include docs/CMakeFiles/docs.dir/progress.make

docs/CMakeFiles/docs: docs/Doxyfile.docs
docs/CMakeFiles/docs: include/my_lib/lib.hpp
docs/CMakeFiles/docs: docs/mainpage.md
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/david/Programming/cpp_dev/vulkan_triangle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generate API documentation for docs"
	cd /home/david/Programming/cpp_dev/vulkan_triangle/include && /usr/bin/cmake -E make_directory /home/david/Programming/cpp_dev/vulkan_triangle/docs
	cd /home/david/Programming/cpp_dev/vulkan_triangle/include && /usr/bin/doxygen /home/david/Programming/cpp_dev/vulkan_triangle/docs/Doxyfile.docs

docs: docs/CMakeFiles/docs
docs: docs/CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
docs/CMakeFiles/docs.dir/build: docs
.PHONY : docs/CMakeFiles/docs.dir/build

docs/CMakeFiles/docs.dir/clean:
	cd /home/david/Programming/cpp_dev/vulkan_triangle/docs && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : docs/CMakeFiles/docs.dir/clean

docs/CMakeFiles/docs.dir/depend:
	cd /home/david/Programming/cpp_dev/vulkan_triangle && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Programming/cpp_dev/vulkan_triangle /home/david/Programming/cpp_dev/vulkan_triangle/docs /home/david/Programming/cpp_dev/vulkan_triangle /home/david/Programming/cpp_dev/vulkan_triangle/docs /home/david/Programming/cpp_dev/vulkan_triangle/docs/CMakeFiles/docs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : docs/CMakeFiles/docs.dir/depend

