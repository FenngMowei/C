# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/fmw/C/DataStruct_Alg/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/fmw/C/DataStruct_Alg/test/build

# Include any dependencies generated for this target.
include CMakeFiles/CList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CList.dir/flags.make

CMakeFiles/CList.dir/DataStruct/list_test.c.o: CMakeFiles/CList.dir/flags.make
CMakeFiles/CList.dir/DataStruct/list_test.c.o: ../DataStruct/list_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/fmw/C/DataStruct_Alg/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CList.dir/DataStruct/list_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CList.dir/DataStruct/list_test.c.o   -c /usr/fmw/C/DataStruct_Alg/test/DataStruct/list_test.c

CMakeFiles/CList.dir/DataStruct/list_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CList.dir/DataStruct/list_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/fmw/C/DataStruct_Alg/test/DataStruct/list_test.c > CMakeFiles/CList.dir/DataStruct/list_test.c.i

CMakeFiles/CList.dir/DataStruct/list_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CList.dir/DataStruct/list_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/fmw/C/DataStruct_Alg/test/DataStruct/list_test.c -o CMakeFiles/CList.dir/DataStruct/list_test.c.s

# Object files for target CList
CList_OBJECTS = \
"CMakeFiles/CList.dir/DataStruct/list_test.c.o"

# External object files for target CList
CList_EXTERNAL_OBJECTS =

bin/CList: CMakeFiles/CList.dir/DataStruct/list_test.c.o
bin/CList: CMakeFiles/CList.dir/build.make
bin/CList: CMakeFiles/CList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/fmw/C/DataStruct_Alg/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/CList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CList.dir/build: bin/CList

.PHONY : CMakeFiles/CList.dir/build

CMakeFiles/CList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CList.dir/clean

CMakeFiles/CList.dir/depend:
	cd /usr/fmw/C/DataStruct_Alg/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/fmw/C/DataStruct_Alg/test /usr/fmw/C/DataStruct_Alg/test /usr/fmw/C/DataStruct_Alg/test/build /usr/fmw/C/DataStruct_Alg/test/build /usr/fmw/C/DataStruct_Alg/test/build/CMakeFiles/CList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CList.dir/depend

