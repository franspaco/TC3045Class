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
CMAKE_COMMAND = /home/franspaco/programs/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/franspaco/programs/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Primos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Primos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Primos.dir/flags.make

CMakeFiles/Primos.dir/main.c.o: CMakeFiles/Primos.dir/flags.make
CMakeFiles/Primos.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Primos.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Primos.dir/main.c.o   -c /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/main.c

CMakeFiles/Primos.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Primos.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/main.c > CMakeFiles/Primos.dir/main.c.i

CMakeFiles/Primos.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Primos.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/main.c -o CMakeFiles/Primos.dir/main.c.s

CMakeFiles/Primos.dir/main.c.o.requires:

.PHONY : CMakeFiles/Primos.dir/main.c.o.requires

CMakeFiles/Primos.dir/main.c.o.provides: CMakeFiles/Primos.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Primos.dir/build.make CMakeFiles/Primos.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Primos.dir/main.c.o.provides

CMakeFiles/Primos.dir/main.c.o.provides.build: CMakeFiles/Primos.dir/main.c.o


# Object files for target Primos
Primos_OBJECTS = \
"CMakeFiles/Primos.dir/main.c.o"

# External object files for target Primos
Primos_EXTERNAL_OBJECTS =

Primos: CMakeFiles/Primos.dir/main.c.o
Primos: CMakeFiles/Primos.dir/build.make
Primos: CMakeFiles/Primos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Primos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Primos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Primos.dir/build: Primos

.PHONY : CMakeFiles/Primos.dir/build

CMakeFiles/Primos.dir/requires: CMakeFiles/Primos.dir/main.c.o.requires

.PHONY : CMakeFiles/Primos.dir/requires

CMakeFiles/Primos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Primos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Primos.dir/clean

CMakeFiles/Primos.dir/depend:
	cd /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug /home/franspaco/Documents/Tec/Sem5/TC3045Class/Clase/Primos/cmake-build-debug/CMakeFiles/Primos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Primos.dir/depend

