# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker"

# Include any dependencies generated for this target.
include CMakeFiles/KaraokeMaker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/KaraokeMaker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/KaraokeMaker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KaraokeMaker.dir/flags.make

KaraokeMaker_autogen/timestamp: /Users/dk/Qt/6.7.2/macos/./libexec/moc
KaraokeMaker_autogen/timestamp: /Users/dk/Qt/6.7.2/macos/./libexec/uic
KaraokeMaker_autogen/timestamp: CMakeFiles/KaraokeMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target KaraokeMaker"
	/usr/local/Cellar/cmake/3.29.0/bin/cmake -E cmake_autogen "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles/KaraokeMaker_autogen.dir/AutogenInfo.json" ""
	/usr/local/Cellar/cmake/3.29.0/bin/cmake -E touch "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/KaraokeMaker_autogen/timestamp"

CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o: CMakeFiles/KaraokeMaker.dir/flags.make
CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o: KaraokeMaker_autogen/mocs_compilation.cpp
CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o: CMakeFiles/KaraokeMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o -MF CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o -c "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/KaraokeMaker_autogen/mocs_compilation.cpp"

CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/KaraokeMaker_autogen/mocs_compilation.cpp" > CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.i

CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/KaraokeMaker_autogen/mocs_compilation.cpp" -o CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.s

CMakeFiles/KaraokeMaker.dir/main.cpp.o: CMakeFiles/KaraokeMaker.dir/flags.make
CMakeFiles/KaraokeMaker.dir/main.cpp.o: main.cpp
CMakeFiles/KaraokeMaker.dir/main.cpp.o: CMakeFiles/KaraokeMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/KaraokeMaker.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KaraokeMaker.dir/main.cpp.o -MF CMakeFiles/KaraokeMaker.dir/main.cpp.o.d -o CMakeFiles/KaraokeMaker.dir/main.cpp.o -c "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/main.cpp"

CMakeFiles/KaraokeMaker.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/KaraokeMaker.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/main.cpp" > CMakeFiles/KaraokeMaker.dir/main.cpp.i

CMakeFiles/KaraokeMaker.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/KaraokeMaker.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/main.cpp" -o CMakeFiles/KaraokeMaker.dir/main.cpp.s

CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o: CMakeFiles/KaraokeMaker.dir/flags.make
CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o: mainwindow.cpp
CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o: CMakeFiles/KaraokeMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o -MF CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o.d -o CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o -c "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/mainwindow.cpp"

CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/mainwindow.cpp" > CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.i

CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/mainwindow.cpp" -o CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.s

CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o: CMakeFiles/KaraokeMaker.dir/flags.make
CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o: arggenerator.cpp
CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o: CMakeFiles/KaraokeMaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o -MF CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o.d -o CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o -c "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/arggenerator.cpp"

CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/arggenerator.cpp" > CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.i

CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/arggenerator.cpp" -o CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.s

# Object files for target KaraokeMaker
KaraokeMaker_OBJECTS = \
"CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/KaraokeMaker.dir/main.cpp.o" \
"CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o" \
"CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o"

# External object files for target KaraokeMaker
KaraokeMaker_EXTERNAL_OBJECTS =

KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/KaraokeMaker_autogen/mocs_compilation.cpp.o
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/main.cpp.o
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/mainwindow.cpp.o
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/arggenerator.cpp.o
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/build.make
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtMultimediaWidgets.framework/Versions/A/QtMultimediaWidgets
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtMultimedia.framework/Versions/A/QtMultimedia
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtNetwork.framework/Versions/A/QtNetwork
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtGui.framework/Versions/A/QtGui
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: /Users/dk/Qt/6.7.2/macos/lib/QtCore.framework/Versions/A/QtCore
KaraokeMaker.app/Contents/MacOS/KaraokeMaker: CMakeFiles/KaraokeMaker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable KaraokeMaker.app/Contents/MacOS/KaraokeMaker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KaraokeMaker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KaraokeMaker.dir/build: KaraokeMaker.app/Contents/MacOS/KaraokeMaker
.PHONY : CMakeFiles/KaraokeMaker.dir/build

CMakeFiles/KaraokeMaker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KaraokeMaker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KaraokeMaker.dir/clean

CMakeFiles/KaraokeMaker.dir/depend: KaraokeMaker_autogen/timestamp
	cd "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker" "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker" "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker" "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker" "/Users/dk/Library/Mobile Documents/com~apple~CloudDocs/Documents/Dev/Learning/Qt/KaraokeMaker/CMakeFiles/KaraokeMaker.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/KaraokeMaker.dir/depend

