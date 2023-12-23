
#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Remove the build directory if it exists
if [ -d $BUILD_DIR ]; then
    rm -rf $BUILD_DIR
fi

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Change to the build directory
cd $BUILD_DIR

# Run CMake to generate the build files
cmake ..

# Build the project
make
