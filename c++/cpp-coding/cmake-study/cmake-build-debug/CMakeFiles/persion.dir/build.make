# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/persion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/persion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/persion.dir/flags.make

CMakeFiles/persion.dir/src/persion/persion.cpp.o: CMakeFiles/persion.dir/flags.make
CMakeFiles/persion.dir/src/persion/persion.cpp.o: ../src/persion/persion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/persion.dir/src/persion/persion.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/persion.dir/src/persion/persion.cpp.o -c /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/src/persion/persion.cpp

CMakeFiles/persion.dir/src/persion/persion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persion.dir/src/persion/persion.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/src/persion/persion.cpp > CMakeFiles/persion.dir/src/persion/persion.cpp.i

CMakeFiles/persion.dir/src/persion/persion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persion.dir/src/persion/persion.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/src/persion/persion.cpp -o CMakeFiles/persion.dir/src/persion/persion.cpp.s

# Object files for target persion
persion_OBJECTS = \
"CMakeFiles/persion.dir/src/persion/persion.cpp.o"

# External object files for target persion
persion_EXTERNAL_OBJECTS =

libpersion.a: CMakeFiles/persion.dir/src/persion/persion.cpp.o
libpersion.a: CMakeFiles/persion.dir/build.make
libpersion.a: CMakeFiles/persion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpersion.a"
	$(CMAKE_COMMAND) -P CMakeFiles/persion.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/persion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/persion.dir/build: libpersion.a

.PHONY : CMakeFiles/persion.dir/build

CMakeFiles/persion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/persion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/persion.dir/clean

CMakeFiles/persion.dir/depend:
	cd /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug /Users/saligia/github/coding_study/c++/cpp-coding/cmake-study/cmake-build-debug/CMakeFiles/persion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/persion.dir/depend

