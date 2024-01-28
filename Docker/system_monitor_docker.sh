#!/bin/bash

# Set Docker image name
IMAGE_NAME="system_monitor_docker"

# Set the directory path where Dockerfile is located
DOCKERFILE_DIR="./Docker"
SYSTEM_MONITOR_PATH=${PWD}/../../SystemMonitor

# Function to check if the image already exists and ask the user for re-building
check_and_build_image() {
    if docker images | grep -q $IMAGE_NAME; then
        echo "List of built images:"
        docker images | grep $IMAGE_NAME
        read -p "Do you want to rebuild the image? [y/N]: " answer
        case $answer in
            [Yy]* )
                docker build -t $IMAGE_NAME $DOCKERFILE_DIR
                ;;
            * )
                echo "Skipping build."
                ;;
        esac
    else
        docker build -t $IMAGE_NAME $DOCKERFILE_DIR
    fi
}

# Perform actions based on script argument
case "$1" in
    build)
        # Check for existing image and build
        check_and_build_image
        ;;
    run)
        # Set the default Docker run options
        DOCKER_RUN_OPTIONS="-it --network host -v $SYSTEM_MONITOR_PATH:/repo/system_monitor $IMAGE_NAME"

        # Check if a container name is provided
        if [ -n "$2" ]; then
            CONTAINER_NAME=$2
            # Check if a container with the same name already exists
            if [ "$(docker ps -aq -f name=^/$CONTAINER_NAME$)" ]; then
                # Stop and remove the existing container
                echo "Container $CONTAINER_NAME already exists. Stopping and removing it."
                docker stop $CONTAINER_NAME
                docker rm $CONTAINER_NAME
            fi
            # Add the container name to the run options
            DOCKER_RUN_OPTIONS="--name $CONTAINER_NAME $DOCKER_RUN_OPTIONS"
        fi

        # Run Docker container with the specified options
        docker run $DOCKER_RUN_OPTIONS
        ;;
    *)
        echo "Invalid option: $1"
        echo "Use 'build' or 'run'"
        exit 1
        ;;
esac
