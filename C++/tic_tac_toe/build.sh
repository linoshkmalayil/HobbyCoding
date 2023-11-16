#!/bin/bash

SOURCE_DIR="src"
CMAKE_FILES_DIR="$SOURCE_DIR/CMakeFiles"
MAKE_FILE_PATH="$SOURCE_DIR/Makefile"
CMAKE_CACHE_FILE="$SOURCE_DIR/CMakeCache.txt"
CMAKE_INSTALL_FILE="$SOURCE_DIR/cmake_install.cmake"
BIN_DIR="bin"

if [[ -d "$CMAKE_FILES_DIR" && -f "$MAKE_FILE_PATH" && -f "$CMAKE_CACHE_FILE" && -f "$CMAKE_INSTALL_FILE" ]] 
then
    echo "deleting Cache Files."
    rm -rf $CMAKE_FILES_DIR
    rm $MAKE_FILE_PATH
    rm $CMAKE_CACHE_FILE
    rm $CMAKE_INSTALL_FILE
else
    echo "Cache not created."
fi

if [ -d "$BIN_DIR" ]
then
    echo "Existing built binaries will be deleted"
    rm -rf $BIN_DIR
else
    echo "No binaries are found"
fi

echo "Building for linux x86_64 platform"
cd $SOURCE_DIR && cmake . && make && cd $PWD

if [[ -d "$CMAKE_FILES_DIR" && -f "$MAKE_FILE_PATH" && -f "$CMAKE_CACHE_FILE" && -f "$CMAKE_INSTALL_FILE" ]] 
then
    echo "cleaning up..."
    rm -rf $CMAKE_FILES_DIR
    rm $MAKE_FILE_PATH
    rm $CMAKE_CACHE_FILE
    rm $CMAKE_INSTALL_FILE
else
    echo "Cache not created."
fi

echo "Building for Windows will run based on the assumption that mingw-w64 tools are installed..."
echo "Building for win64 platform"
cd $SOURCE_DIR && cmake -DCMAKE_TOOLCHAIN_FILE=win_build.cmake . && make && cd ..

if [[ -d "$CMAKE_FILES_DIR" && -f "$MAKE_FILE_PATH" && -f "$CMAKE_CACHE_FILE" && -f "$CMAKE_INSTALL_FILE" ]] 
then
    echo "cleaning up..."
    rm -rf $CMAKE_FILES_DIR
    rm $MAKE_FILE_PATH
    rm $CMAKE_CACHE_FILE
    rm $CMAKE_INSTALL_FILE
else
    echo "Cache not created."
fi

echo "Done!"
