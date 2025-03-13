cmake_minimum_required(VERSION 3.10)
project(advanced-copy-paste)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(VSCode REQUIRED)

# Add source files
set(SOURCES
    src/extension.cpp
)

# Create the extension
add_library(advanced-copy-paste SHARED ${SOURCES})

# Include directories
target_include_directories(advanced-copy-paste PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link against VSCode
target_link_libraries(advanced-copy-paste PRIVATE
    vscode
)

# Set output directory
set_target_properties(advanced-copy-paste PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out"
)

# Install targets
install(TARGETS advanced-copy-paste
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
) 