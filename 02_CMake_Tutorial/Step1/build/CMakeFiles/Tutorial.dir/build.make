# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build

# Include any dependencies generated for this target.
include CMakeFiles/Tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tutorial.dir/flags.make

CMakeFiles/Tutorial.dir/codegen:
.PHONY : CMakeFiles/Tutorial.dir/codegen

CMakeFiles/Tutorial.dir/tutorial.cxx.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/tutorial.cxx.o: /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/tutorial.cxx
CMakeFiles/Tutorial.dir/tutorial.cxx.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tutorial.dir/tutorial.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/tutorial.cxx.o -MF CMakeFiles/Tutorial.dir/tutorial.cxx.o.d -o CMakeFiles/Tutorial.dir/tutorial.cxx.o -c /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/tutorial.cxx

CMakeFiles/Tutorial.dir/tutorial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/tutorial.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/tutorial.cxx > CMakeFiles/Tutorial.dir/tutorial.cxx.i

CMakeFiles/Tutorial.dir/tutorial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/tutorial.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/tutorial.cxx -o CMakeFiles/Tutorial.dir/tutorial.cxx.s

# Object files for target Tutorial
Tutorial_OBJECTS = \
"CMakeFiles/Tutorial.dir/tutorial.cxx.o"

# External object files for target Tutorial
Tutorial_EXTERNAL_OBJECTS =

Tutorial: CMakeFiles/Tutorial.dir/tutorial.cxx.o
Tutorial: CMakeFiles/Tutorial.dir/build.make
Tutorial: /Library/Frameworks/SDL2.framework/Versions/A/SDL2
Tutorial: libglad.a
Tutorial: CMakeFiles/Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tutorial.dir/build: Tutorial
.PHONY : CMakeFiles/Tutorial.dir/build

CMakeFiles/Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tutorial.dir/clean

CMakeFiles/Tutorial.dir/depend:
	cd /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1 /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1 /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build /Users/davidisinta/Documents/OpenGL/02_CMake_Tutorial/Step1/build/CMakeFiles/Tutorial.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tutorial.dir/depend

