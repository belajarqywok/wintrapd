# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\command\cmake\bin\cmake.exe

# The command to remove a file.
RM = F:\command\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\projects\hacking projects\wintrapd"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\projects\hacking projects\wintrapd\build"

# Include any dependencies generated for this target.
include CMakeFiles/b64tool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/b64tool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/b64tool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/b64tool.dir/flags.make

CMakeFiles/b64tool.dir/b64tool.c.obj: CMakeFiles/b64tool.dir/flags.make
CMakeFiles/b64tool.dir/b64tool.c.obj: F:/projects/hacking\ projects/wintrapd/b64tool.c
CMakeFiles/b64tool.dir/b64tool.c.obj: CMakeFiles/b64tool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/b64tool.dir/b64tool.c.obj"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/b64tool.dir/b64tool.c.obj -MF CMakeFiles\b64tool.dir\b64tool.c.obj.d -o CMakeFiles\b64tool.dir\b64tool.c.obj -c "F:\projects\hacking projects\wintrapd\b64tool.c"

CMakeFiles/b64tool.dir/b64tool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/b64tool.dir/b64tool.c.i"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "F:\projects\hacking projects\wintrapd\b64tool.c" > CMakeFiles\b64tool.dir\b64tool.c.i

CMakeFiles/b64tool.dir/b64tool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/b64tool.dir/b64tool.c.s"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "F:\projects\hacking projects\wintrapd\b64tool.c" -o CMakeFiles\b64tool.dir\b64tool.c.s

# Object files for target b64tool
b64tool_OBJECTS = \
"CMakeFiles/b64tool.dir/b64tool.c.obj"

# External object files for target b64tool
b64tool_EXTERNAL_OBJECTS =

b64tool.exe: CMakeFiles/b64tool.dir/b64tool.c.obj
b64tool.exe: CMakeFiles/b64tool.dir/build.make
b64tool.exe: CMakeFiles/b64tool.dir/linkLibs.rsp
b64tool.exe: CMakeFiles/b64tool.dir/objects1
b64tool.exe: CMakeFiles/b64tool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable b64tool.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\b64tool.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/b64tool.dir/build: b64tool.exe
.PHONY : CMakeFiles/b64tool.dir/build

CMakeFiles/b64tool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\b64tool.dir\cmake_clean.cmake
.PHONY : CMakeFiles/b64tool.dir/clean

CMakeFiles/b64tool.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build\CMakeFiles\b64tool.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/b64tool.dir/depend
