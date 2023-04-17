# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zanxi/share/myjson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zanxi/share/myjson

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zanxi/share/myjson/CMakeFiles /home/zanxi/share/myjson/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zanxi/share/myjson/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gendb

# Build rule for target.
gendb: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gendb
.PHONY : gendb

# fast build rule for target.
gendb/fast:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/build
.PHONY : gendb/fast

GenerateDB.o: GenerateDB.cpp.o

.PHONY : GenerateDB.o

# target to build an object file
GenerateDB.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/GenerateDB.cpp.o
.PHONY : GenerateDB.cpp.o

GenerateDB.i: GenerateDB.cpp.i

.PHONY : GenerateDB.i

# target to preprocess a source file
GenerateDB.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/GenerateDB.cpp.i
.PHONY : GenerateDB.cpp.i

GenerateDB.s: GenerateDB.cpp.s

.PHONY : GenerateDB.s

# target to generate assembly for a file
GenerateDB.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/GenerateDB.cpp.s
.PHONY : GenerateDB.cpp.s

SqlDataBase.o: SqlDataBase.cpp.o

.PHONY : SqlDataBase.o

# target to build an object file
SqlDataBase.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/SqlDataBase.cpp.o
.PHONY : SqlDataBase.cpp.o

SqlDataBase.i: SqlDataBase.cpp.i

.PHONY : SqlDataBase.i

# target to preprocess a source file
SqlDataBase.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/SqlDataBase.cpp.i
.PHONY : SqlDataBase.cpp.i

SqlDataBase.s: SqlDataBase.cpp.s

.PHONY : SqlDataBase.s

# target to generate assembly for a file
SqlDataBase.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/SqlDataBase.cpp.s
.PHONY : SqlDataBase.cpp.s

Utils.o: Utils.cpp.o

.PHONY : Utils.o

# target to build an object file
Utils.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/Utils.cpp.o
.PHONY : Utils.cpp.o

Utils.i: Utils.cpp.i

.PHONY : Utils.i

# target to preprocess a source file
Utils.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/Utils.cpp.i
.PHONY : Utils.cpp.i

Utils.s: Utils.cpp.s

.PHONY : Utils.s

# target to generate assembly for a file
Utils.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/Utils.cpp.s
.PHONY : Utils.cpp.s

csvfile.o: csvfile.cpp.o

.PHONY : csvfile.o

# target to build an object file
csvfile.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/csvfile.cpp.o
.PHONY : csvfile.cpp.o

csvfile.i: csvfile.cpp.i

.PHONY : csvfile.i

# target to preprocess a source file
csvfile.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/csvfile.cpp.i
.PHONY : csvfile.cpp.i

csvfile.s: csvfile.cpp.s

.PHONY : csvfile.s

# target to generate assembly for a file
csvfile.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/csvfile.cpp.s
.PHONY : csvfile.cpp.s

data.o: data.cpp.o

.PHONY : data.o

# target to build an object file
data.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/data.cpp.o
.PHONY : data.cpp.o

data.i: data.cpp.i

.PHONY : data.i

# target to preprocess a source file
data.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/data.cpp.i
.PHONY : data.cpp.i

data.s: data.cpp.s

.PHONY : data.s

# target to generate assembly for a file
data.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/data.cpp.s
.PHONY : data.cpp.s

datetime.o: datetime.cpp.o

.PHONY : datetime.o

# target to build an object file
datetime.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/datetime.cpp.o
.PHONY : datetime.cpp.o

datetime.i: datetime.cpp.i

.PHONY : datetime.i

# target to preprocess a source file
datetime.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/datetime.cpp.i
.PHONY : datetime.cpp.i

datetime.s: datetime.cpp.s

.PHONY : datetime.s

# target to generate assembly for a file
datetime.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/datetime.cpp.s
.PHONY : datetime.cpp.s

libjson.o: libjson.cpp.o

.PHONY : libjson.o

# target to build an object file
libjson.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/libjson.cpp.o
.PHONY : libjson.cpp.o

libjson.i: libjson.cpp.i

.PHONY : libjson.i

# target to preprocess a source file
libjson.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/libjson.cpp.i
.PHONY : libjson.cpp.i

libjson.s: libjson.cpp.s

.PHONY : libjson.s

# target to generate assembly for a file
libjson.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/libjson.cpp.s
.PHONY : libjson.cpp.s

logger.o: logger.cpp.o

.PHONY : logger.o

# target to build an object file
logger.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/logger.cpp.o
.PHONY : logger.cpp.o

logger.i: logger.cpp.i

.PHONY : logger.i

# target to preprocess a source file
logger.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/logger.cpp.i
.PHONY : logger.cpp.i

logger.s: logger.cpp.s

.PHONY : logger.s

# target to generate assembly for a file
logger.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/logger.cpp.s
.PHONY : logger.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/gendb.dir/build.make CMakeFiles/gendb.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... gendb"
	@echo "... edit_cache"
	@echo "... GenerateDB.o"
	@echo "... GenerateDB.i"
	@echo "... GenerateDB.s"
	@echo "... SqlDataBase.o"
	@echo "... SqlDataBase.i"
	@echo "... SqlDataBase.s"
	@echo "... Utils.o"
	@echo "... Utils.i"
	@echo "... Utils.s"
	@echo "... csvfile.o"
	@echo "... csvfile.i"
	@echo "... csvfile.s"
	@echo "... data.o"
	@echo "... data.i"
	@echo "... data.s"
	@echo "... datetime.o"
	@echo "... datetime.i"
	@echo "... datetime.s"
	@echo "... libjson.o"
	@echo "... libjson.i"
	@echo "... libjson.s"
	@echo "... logger.o"
	@echo "... logger.i"
	@echo "... logger.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
