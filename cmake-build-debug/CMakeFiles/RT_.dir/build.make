# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/CLionProjects/RT_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/CLionProjects/RT_/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RT_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RT_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RT_.dir/flags.make

CMakeFiles/RT_.dir/main.c.o: CMakeFiles/RT_.dir/flags.make
CMakeFiles/RT_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/CLionProjects/RT_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RT_.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_.dir/main.c.o   -c /Users/mac/CLionProjects/RT_/main.c

CMakeFiles/RT_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mac/CLionProjects/RT_/main.c > CMakeFiles/RT_.dir/main.c.i

CMakeFiles/RT_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mac/CLionProjects/RT_/main.c -o CMakeFiles/RT_.dir/main.c.s

CMakeFiles/RT_.dir/main.c.o.requires:

.PHONY : CMakeFiles/RT_.dir/main.c.o.requires

CMakeFiles/RT_.dir/main.c.o.provides: CMakeFiles/RT_.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/RT_.dir/build.make CMakeFiles/RT_.dir/main.c.o.provides.build
.PHONY : CMakeFiles/RT_.dir/main.c.o.provides

CMakeFiles/RT_.dir/main.c.o.provides.build: CMakeFiles/RT_.dir/main.c.o


# Object files for target RT_
RT__OBJECTS = \
"CMakeFiles/RT_.dir/main.c.o"

# External object files for target RT_
RT__EXTERNAL_OBJECTS =

RT_: CMakeFiles/RT_.dir/main.c.o
RT_: CMakeFiles/RT_.dir/build.make
RT_: CMakeFiles/RT_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/CLionProjects/RT_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RT_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RT_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RT_.dir/build: RT_

.PHONY : CMakeFiles/RT_.dir/build

CMakeFiles/RT_.dir/requires: CMakeFiles/RT_.dir/main.c.o.requires

.PHONY : CMakeFiles/RT_.dir/requires

CMakeFiles/RT_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RT_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RT_.dir/clean

CMakeFiles/RT_.dir/depend:
	cd /Users/mac/CLionProjects/RT_/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/CLionProjects/RT_ /Users/mac/CLionProjects/RT_ /Users/mac/CLionProjects/RT_/cmake-build-debug /Users/mac/CLionProjects/RT_/cmake-build-debug /Users/mac/CLionProjects/RT_/cmake-build-debug/CMakeFiles/RT_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RT_.dir/depend

