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
include CMakeFiles/chrome_update.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chrome_update.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chrome_update.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chrome_update.dir/flags.make

CMakeFiles/chrome_update.dir/trojan.c.obj: CMakeFiles/chrome_update.dir/flags.make
CMakeFiles/chrome_update.dir/trojan.c.obj: F:/projects/hacking\ projects/wintrapd/trojan.c
CMakeFiles/chrome_update.dir/trojan.c.obj: CMakeFiles/chrome_update.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chrome_update.dir/trojan.c.obj"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chrome_update.dir/trojan.c.obj -MF CMakeFiles\chrome_update.dir\trojan.c.obj.d -o CMakeFiles\chrome_update.dir\trojan.c.obj -c "F:\projects\hacking projects\wintrapd\trojan.c"

CMakeFiles/chrome_update.dir/trojan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chrome_update.dir/trojan.c.i"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "F:\projects\hacking projects\wintrapd\trojan.c" > CMakeFiles\chrome_update.dir\trojan.c.i

CMakeFiles/chrome_update.dir/trojan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chrome_update.dir/trojan.c.s"
	F:\msys64\mingw64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "F:\projects\hacking projects\wintrapd\trojan.c" -o CMakeFiles\chrome_update.dir\trojan.c.s

CMakeFiles/chrome_update.dir/chrome.rc.obj: CMakeFiles/chrome_update.dir/flags.make
CMakeFiles/chrome_update.dir/chrome.rc.obj: F:/projects/hacking\ projects/wintrapd/chrome.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building RC object CMakeFiles/chrome_update.dir/chrome.rc.obj"
	F:\msys64\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) "F:\projects\hacking projects\wintrapd\chrome.rc" CMakeFiles\chrome_update.dir\chrome.rc.obj

# Object files for target chrome_update
chrome_update_OBJECTS = \
"CMakeFiles/chrome_update.dir/trojan.c.obj" \
"CMakeFiles/chrome_update.dir/chrome.rc.obj"

# External object files for target chrome_update
chrome_update_EXTERNAL_OBJECTS =

chrome_update.exe: CMakeFiles/chrome_update.dir/trojan.c.obj
chrome_update.exe: CMakeFiles/chrome_update.dir/chrome.rc.obj
chrome_update.exe: CMakeFiles/chrome_update.dir/build.make
chrome_update.exe: CMakeFiles/chrome_update.dir/linkLibs.rsp
chrome_update.exe: CMakeFiles/chrome_update.dir/objects1
chrome_update.exe: CMakeFiles/chrome_update.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\projects\hacking projects\wintrapd\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable chrome_update.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chrome_update.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chrome_update.dir/build: chrome_update.exe
.PHONY : CMakeFiles/chrome_update.dir/build

CMakeFiles/chrome_update.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chrome_update.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chrome_update.dir/clean

CMakeFiles/chrome_update.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build" "F:\projects\hacking projects\wintrapd\build\CMakeFiles\chrome_update.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/chrome_update.dir/depend

