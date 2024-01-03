
#!/bin/bash

# Set the build directory
RUN_DIR="build"

# Run the executable if it exists
if [ -d $BUILD_DIR ]; then
    cd $BUILD_DIR
    ./SystemMonitor
else
    echo "Build directory does not exist! Please run build.sh first."
fi