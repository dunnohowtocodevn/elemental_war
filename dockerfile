# Use an official lightweight C++ runtime as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /usr/src/myapp

# Copy the current directory contents into the container at /usr/src/myapp
COPY . .

# Build the C++ program inside the Docker container (optional if build is done in Jenkins)


# Make the container run the compiled program
CMD ["./game"]
