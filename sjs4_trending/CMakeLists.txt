# Author: Seth Sanasac
# NetID: sjs4
# Date: October 10 2014

# Assignment Number: 2 - trending file

# A simple example CMake Setup for Compiling C Programs. This setup utilizes a single
# subdirectory (src) in which all C source (.c) and header (.h) files within that 
# directory are included within the project.

# CMake projects are forward compatible, but may not be backwards compatible. This
# commands defines the version of CMake used for the current setup.

cmake_minimum_required(VERSION 2.6)

# Define the project name. 

project (trending_project)

# Add a subdirectory to the project. The CMakeLists.txt file in that subdirectory
# will be used for further setting up the project.

add_subdirectory( src )
