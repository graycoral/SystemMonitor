
#!/bin/bash

# Set the build directory
RUN_DIR=${PWD}/build/
APP='SystemMonitor'

# Run the executable if it exists
if [ -f ${RUN_DIR}/${APP} ]; then
    echo "Running SystemMonitor..."
    echo "Current directory: ${RUN_DIR}"
    ${RUN_DIR}/${APP}
else
    echo "Build binary does not exist! Please run build.sh first."
fi