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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/user/Загрузки/Telegram Desktop/project/project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/user/Загрузки/Telegram Desktop/project/project/build"

# Include any dependencies generated for this target.
include CMakeFiles/TESTS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TESTS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TESTS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TESTS.dir/flags.make

CMakeFiles/TESTS.dir/src/TESTS.cc.o: CMakeFiles/TESTS.dir/flags.make
CMakeFiles/TESTS.dir/src/TESTS.cc.o: /home/user/Загрузки/Telegram\ Desktop/project/project/src/TESTS.cc
CMakeFiles/TESTS.dir/src/TESTS.cc.o: CMakeFiles/TESTS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Загрузки/Telegram Desktop/project/project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TESTS.dir/src/TESTS.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TESTS.dir/src/TESTS.cc.o -MF CMakeFiles/TESTS.dir/src/TESTS.cc.o.d -o CMakeFiles/TESTS.dir/src/TESTS.cc.o -c "/home/user/Загрузки/Telegram Desktop/project/project/src/TESTS.cc"

CMakeFiles/TESTS.dir/src/TESTS.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TESTS.dir/src/TESTS.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/user/Загрузки/Telegram Desktop/project/project/src/TESTS.cc" > CMakeFiles/TESTS.dir/src/TESTS.cc.i

CMakeFiles/TESTS.dir/src/TESTS.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TESTS.dir/src/TESTS.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/user/Загрузки/Telegram Desktop/project/project/src/TESTS.cc" -o CMakeFiles/TESTS.dir/src/TESTS.cc.s

# Object files for target TESTS
TESTS_OBJECTS = \
"CMakeFiles/TESTS.dir/src/TESTS.cc.o"

# External object files for target TESTS
TESTS_EXTERNAL_OBJECTS =

TESTS: CMakeFiles/TESTS.dir/src/TESTS.cc.o
TESTS: CMakeFiles/TESTS.dir/build.make
TESTS: lib/libgtest_main.a
TESTS: libLib.so
TESTS: lib/libgtest.a
TESTS: CMakeFiles/TESTS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/user/Загрузки/Telegram Desktop/project/project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TESTS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TESTS.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=TESTS -D "TEST_EXECUTABLE=/home/user/Загрузки/Telegram Desktop/project/project/build/TESTS" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/user/Загрузки/Telegram Desktop/project/project/build" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=TESTS_TESTS -D "CTEST_FILE=/home/user/Загрузки/Telegram Desktop/project/project/build/TESTS[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.25/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/TESTS.dir/build: TESTS
.PHONY : CMakeFiles/TESTS.dir/build

CMakeFiles/TESTS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TESTS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TESTS.dir/clean

CMakeFiles/TESTS.dir/depend:
	cd "/home/user/Загрузки/Telegram Desktop/project/project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/user/Загрузки/Telegram Desktop/project/project" "/home/user/Загрузки/Telegram Desktop/project/project" "/home/user/Загрузки/Telegram Desktop/project/project/build" "/home/user/Загрузки/Telegram Desktop/project/project/build" "/home/user/Загрузки/Telegram Desktop/project/project/build/CMakeFiles/TESTS.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TESTS.dir/depend

