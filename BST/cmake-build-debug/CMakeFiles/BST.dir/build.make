# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\development_enviroment\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\development_enviroment\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Algorithm\code\AlgorithmByCpp\BST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST.dir/flags.make

CMakeFiles/BST.dir/main.cpp.obj: CMakeFiles/BST.dir/flags.make
CMakeFiles/BST.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BST.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BST.dir\main.cpp.obj -c F:\Algorithm\code\AlgorithmByCpp\BST\main.cpp

CMakeFiles/BST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BST.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Algorithm\code\AlgorithmByCpp\BST\main.cpp > CMakeFiles\BST.dir\main.cpp.i

CMakeFiles/BST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BST.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Algorithm\code\AlgorithmByCpp\BST\main.cpp -o CMakeFiles\BST.dir\main.cpp.s

CMakeFiles/BST.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/BST.dir/main.cpp.obj.requires

CMakeFiles/BST.dir/main.cpp.obj.provides: CMakeFiles/BST.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\BST.dir\build.make CMakeFiles/BST.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/BST.dir/main.cpp.obj.provides

CMakeFiles/BST.dir/main.cpp.obj.provides.build: CMakeFiles/BST.dir/main.cpp.obj


# Object files for target BST
BST_OBJECTS = \
"CMakeFiles/BST.dir/main.cpp.obj"

# External object files for target BST
BST_EXTERNAL_OBJECTS =

BST.exe: CMakeFiles/BST.dir/main.cpp.obj
BST.exe: CMakeFiles/BST.dir/build.make
BST.exe: CMakeFiles/BST.dir/linklibs.rsp
BST.exe: CMakeFiles/BST.dir/objects1.rsp
BST.exe: CMakeFiles/BST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST.dir/build: BST.exe

.PHONY : CMakeFiles/BST.dir/build

CMakeFiles/BST.dir/requires: CMakeFiles/BST.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/BST.dir/requires

CMakeFiles/BST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BST.dir/clean

CMakeFiles/BST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Algorithm\code\AlgorithmByCpp\BST F:\Algorithm\code\AlgorithmByCpp\BST F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug F:\Algorithm\code\AlgorithmByCpp\BST\cmake-build-debug\CMakeFiles\BST.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BST.dir/depend

