# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/jtass/source/repos/PongPlusPlus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/jtass/source/repos/PongPlusPlus/build

# Include any dependencies generated for this target.
include CMakeFiles/PongPlusPlus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PongPlusPlus.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PongPlusPlus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PongPlusPlus.dir/flags.make

CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/main.cpp
CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/main.cpp

CMakeFiles/PongPlusPlus.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/main.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/main.cpp > CMakeFiles/PongPlusPlus.dir/src/main.cpp.i

CMakeFiles/PongPlusPlus.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/main.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/main.cpp -o CMakeFiles/PongPlusPlus.dir/src/main.cpp.s

CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/game.cpp
CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/game.cpp

CMakeFiles/PongPlusPlus.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/game.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/game.cpp > CMakeFiles/PongPlusPlus.dir/src/game.cpp.i

CMakeFiles/PongPlusPlus.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/game.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/game.cpp -o CMakeFiles/PongPlusPlus.dir/src/game.cpp.s

CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/control.cpp
CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/control.cpp

CMakeFiles/PongPlusPlus.dir/src/control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/control.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/control.cpp > CMakeFiles/PongPlusPlus.dir/src/control.cpp.i

CMakeFiles/PongPlusPlus.dir/src/control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/control.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/control.cpp -o CMakeFiles/PongPlusPlus.dir/src/control.cpp.s

CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/render.cpp
CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/render.cpp

CMakeFiles/PongPlusPlus.dir/src/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/render.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/render.cpp > CMakeFiles/PongPlusPlus.dir/src/render.cpp.i

CMakeFiles/PongPlusPlus.dir/src/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/render.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/render.cpp -o CMakeFiles/PongPlusPlus.dir/src/render.cpp.s

CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/ball.cpp
CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/ball.cpp

CMakeFiles/PongPlusPlus.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/ball.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/ball.cpp > CMakeFiles/PongPlusPlus.dir/src/ball.cpp.i

CMakeFiles/PongPlusPlus.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/ball.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/ball.cpp -o CMakeFiles/PongPlusPlus.dir/src/ball.cpp.s

CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/paddle.cpp
CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/paddle.cpp

CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/paddle.cpp > CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.i

CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/paddle.cpp -o CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.s

CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj: CMakeFiles/PongPlusPlus.dir/flags.make
CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj: CMakeFiles/PongPlusPlus.dir/includes_CXX.rsp
CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj: C:/Users/jtass/source/repos/PongPlusPlus/src/player.cpp
CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj: CMakeFiles/PongPlusPlus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj -MF CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj.d -o CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj -c C:/Users/jtass/source/repos/PongPlusPlus/src/player.cpp

CMakeFiles/PongPlusPlus.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongPlusPlus.dir/src/player.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/jtass/source/repos/PongPlusPlus/src/player.cpp > CMakeFiles/PongPlusPlus.dir/src/player.cpp.i

CMakeFiles/PongPlusPlus.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongPlusPlus.dir/src/player.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/jtass/source/repos/PongPlusPlus/src/player.cpp -o CMakeFiles/PongPlusPlus.dir/src/player.cpp.s

# Object files for target PongPlusPlus
PongPlusPlus_OBJECTS = \
"CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj" \
"CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj"

# External object files for target PongPlusPlus
PongPlusPlus_EXTERNAL_OBJECTS =

PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/main.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/game.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/control.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/render.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/ball.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/paddle.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/src/player.cpp.obj
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/build.make
PongPlusPlus.exe: C:/Users/jtass/vcpkg/packages/SDL2-2.26.4/cmake/../lib/x64/SDL2main.lib
PongPlusPlus.exe: C:/Users/jtass/vcpkg/packages/SDL2-2.26.4/cmake/../lib/x64/SDL2.lib
PongPlusPlus.exe: C:/Users/jtass/vcpkg/packages/SDL2_ttf-2.20.2/cmake/../lib/x64/SDL2_ttf.lib
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/linkLibs.rsp
PongPlusPlus.exe: CMakeFiles/PongPlusPlus.dir/objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable PongPlusPlus.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/PongPlusPlus.dir/objects.a
	C:/msys64/mingw64/bin/ar.exe qc CMakeFiles/PongPlusPlus.dir/objects.a @CMakeFiles/PongPlusPlus.dir/objects1
	C:/msys64/mingw64/bin/c++.exe -Wl,--whole-archive CMakeFiles/PongPlusPlus.dir/objects.a -Wl,--no-whole-archive -o PongPlusPlus.exe -Wl,--out-implib,libPongPlusPlus.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/PongPlusPlus.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/PongPlusPlus.dir/build: PongPlusPlus.exe
.PHONY : CMakeFiles/PongPlusPlus.dir/build

CMakeFiles/PongPlusPlus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PongPlusPlus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PongPlusPlus.dir/clean

CMakeFiles/PongPlusPlus.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/jtass/source/repos/PongPlusPlus C:/Users/jtass/source/repos/PongPlusPlus C:/Users/jtass/source/repos/PongPlusPlus/build C:/Users/jtass/source/repos/PongPlusPlus/build C:/Users/jtass/source/repos/PongPlusPlus/build/CMakeFiles/PongPlusPlus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PongPlusPlus.dir/depend

