# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/dora/Softwares/CLion-2021.2.4/clion-2021.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dora/Softwares/CLion-2021.2.4/clion-2021.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dora/Codes/Accelerated-Cpp/ch07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/cpp_template.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/cpp_template.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/cpp_template.dir/flags.make

src/CMakeFiles/cpp_template.dir/main.cpp.o: src/CMakeFiles/cpp_template.dir/flags.make
src/CMakeFiles/cpp_template.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/cpp_template.dir/main.cpp.o"
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_template.dir/main.cpp.o -c /home/dora/Codes/Accelerated-Cpp/ch07/src/main.cpp

src/CMakeFiles/cpp_template.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_template.dir/main.cpp.i"
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dora/Codes/Accelerated-Cpp/ch07/src/main.cpp > CMakeFiles/cpp_template.dir/main.cpp.i

src/CMakeFiles/cpp_template.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_template.dir/main.cpp.s"
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dora/Codes/Accelerated-Cpp/ch07/src/main.cpp -o CMakeFiles/cpp_template.dir/main.cpp.s

# Object files for target cpp_template
cpp_template_OBJECTS = \
"CMakeFiles/cpp_template.dir/main.cpp.o"

# External object files for target cpp_template
cpp_template_EXTERNAL_OBJECTS =

../bin/cpp_template: src/CMakeFiles/cpp_template.dir/main.cpp.o
../bin/cpp_template: src/CMakeFiles/cpp_template.dir/build.make
../bin/cpp_template: src/CMakeFiles/cpp_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/cpp_template"
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/cpp_template.dir/build: ../bin/cpp_template
.PHONY : src/CMakeFiles/cpp_template.dir/build

src/CMakeFiles/cpp_template.dir/clean:
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/cpp_template.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/cpp_template.dir/clean

src/CMakeFiles/cpp_template.dir/depend:
	cd /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dora/Codes/Accelerated-Cpp/ch07 /home/dora/Codes/Accelerated-Cpp/ch07/src /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src /home/dora/Codes/Accelerated-Cpp/ch07/cmake-build-debug/src/CMakeFiles/cpp_template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/cpp_template.dir/depend

