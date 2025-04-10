cmake_minimum_required(VERSION 3.10)
project(md2man)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/parser.cpp
    src/converter.cpp
    src/generator.cpp
)

# Add header files
set(HEADERS
    src/parser.h
    src/converter.h
    src/generator.h
    src/utils.h
)

# Create executable
add_executable(md2man ${SOURCES})

# Add include directories
target_include_directories(md2man PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Install target
install(TARGETS md2man DESTINATION bin)

# Copy template files to build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/templates)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/templates/style.css ${CMAKE_BINARY_DIR}/templates/style.css COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/templates/script.js ${CMAKE_BINARY_DIR}/templates/script.js COPYONLY)

# Create examples directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/examples)
