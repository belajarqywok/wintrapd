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
include CMakeFiles/msvcmon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/msvcmon.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/msvcmon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/msvcmon.dir/flags.make

CMakeFiles/msvcmon.dir/kylg_winapi.c.obj: CMakeFiles/msvcmon.dir/flags.make
CMakeFiles/msvcmon.dir/kylg_winapi.c.obj: F:/projects/hacking\ projects/wintrapd/kylg_winapi.c
CMakeFiles/msvcmon.dir/kylg_winapi.c.obj: CMakeFiles/msvcmon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/msvcmon.dir/kylg_winapi.c.obj"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/msvcmon.dir/kylg_winapi.c.obj -MF CMakeFiles\msvcmon.dir\kylg_winapi.c.obj.d -o CMakeFiles\msvcmon.dir\kylg_winapi.c.obj -c "F:\projects\hacking projects\wintrapd\kylg_winapi.c"

CMakeFiles/msvcmon.dir/kylg_winapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msvcmon.dir/kylg_winapi.c.i"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "F:\projects\hacking projects\wintrapd\kylg_winapi.c" > CMakeFiles\msvcmon.dir\kylg_winapi.c.i

CMakeFiles/msvcmon.dir/kylg_winapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msvcmon.dir/kylg_winapi.c.s"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "F:\projects\hacking projects\wintrapd\kylg_winapi.c" -o CMakeFiles\msvcmon.dir\kylg_winapi.c.s

# Object files for target msvcmon
msvcmon_OBJECTS = \
"CMakeFiles/msvcmon.dir/kylg_winapi.c.obj"

# External object files for target msvcmon
msvcmon_EXTERNAL_OBJECTS =

msvcmon.exe: CMakeFiles/msvcmon.dir/kylg_winapi.c.obj
msvcmon.exe: CMakeFiles/msvcmon.dir/build.make
msvcmon.exe: CMakeFiles/msvcmon.dir/linkLibs.rsp
msvcmon.exe: CMakeFiles/msvcmon.dir/objects1
msvcmon.exe: CMakeFiles/msvcmon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable msvcmon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\msvcmon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/msvcmon.dir/build: msvcmon.exe
.PHONY : CMakeFiles/msvcmon.dir/build

CMakeFiles/msvcmon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\msvcmon.dir\cmake_clean.cmake
.PHONY : CMakeFiles/msvcmon.dir/clean

CMakeFiles/msvcmon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build\CMakeFiles\msvcmon.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/msvcmon.dir/depend

