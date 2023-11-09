# CMakeList.txt : CMake project for CA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Define the project name and the language you are using (C++)
project ("CA" LANGUAGES CXX)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files and headers for COM using file globbing
file(GLOB COM_SOURCE_FILES 
  "COM/as/*.c"
  "COM/bucketLib/*.c"
  "COM/calc/*.c"
  "COM/cvtFast/*.c"
  "COM/dbmf/*.c"
  "COM/ellLib/*.c"
  "COM/env/*.c"
  "COM/error/*.c"
  "COM/freeList/*.c"
  "COM/gpHash/*.c"
  "COM/macLib/*.c"
  #"COM/misc/*.cpp"
  "COM/misc/*.c"
  "COM/O.Common/*.c"
  "COM/osi/*.c"
  #"COM/osi/os/defualt/*.c"
  "COM/pool/*.c"
  "COM/ring/*.c"
  "COM/taskwd/*.c"
  "COM/iocsh/*.c"
)
file(GLOB COM_HEADER_FILES 
  "COM/as/*.h"
  "COM/bucketLib/*.h"
  "COM/calc/*.h"
  "COM/cvtFast/*.h"
  "COM/dbmf/*.h"
  "COM/ellLib/*.h"
  "COM/env/*.h"
  "COM/error/*.h"
  "COM/freeList/*.h"
  "COM/gpHash/*.h"
  "COM/macLib/*.h"
  "COM/misc/*.h"
  "COM/osi/*.h"
  #"COM/osi/os/defualt/*.h"
  "COM/pool/*.h"
  "COM/ring/*.h"
  "COM/taskwd/*.h"
  "COM/iocsh/*.h"
)

message(STATUS "TZ: COM Source files: ${COM_SOURCE_FILES}")
message(STATUS "TZ: COM Header files: ${COM_HEADER_FILES}")

# Add the COM library target
add_library(COM STATIC ${COM_SOURCE_FILES} ${COM_HEADER_FILES})

# Collect all subdirectories under COM
file(GLOB COM_SUBDIRS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/COM" "${CMAKE_CURRENT_SOURCE_DIR}/COM/*")
foreach(subdir ${COM_SUBDIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/COM/${subdir}")
        target_include_directories(COM PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/COM/${subdir}")
    endif()
endforeach()

# Define source files and headers for CA using file globbing
file(GLOB CA_SOURCE_FILES "*.cpp" "*.c")
file(GLOB CA_HEADER_FILES "*.h")

message(STATUS "TZ: CA Source files: ${CA_SOURCE_FILES}")
message(STATUS "TZ: CA Header files: ${CA_HEADER_FILES}")

# Add the CA library target
add_library(CA STATIC ${CA_SOURCE_FILES} ${CA_HEADER_FILES})

# Link CA against COM
target_link_libraries(CA PRIVATE COM)

# Add the same COM subdirectories to the CA target, only if needed for CA's include paths
# Note: This may not be necessary if CA does not need to include headers from COM's subdirectories directly
foreach(subdir ${COM_SUBDIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/COM/${subdir}")
        target_include_directories(CA PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/COM/${subdir}")
        message(STATUS "TZ: CA include dir: ${CMAKE_CURRENT_SOURCE_DIR}/COM/${subdir}")
    endif()
endforeach()

# Platform-specific compiler options and preprocessor definitions
if(WIN32)
  # Define Windows-specific options here
  target_compile_definitions(COM PRIVATE "COM_WINDOWS_BUILD")
  target_compile_definitions(CA PRIVATE "CA_WINDOWS_BUILD")
elseif(UNIX AND NOT APPLE)
  # Define Linux-specific options here
  target_compile_definitions(COM PRIVATE "COM_LINUX_BUILD")
  target_compile_definitions(CA PRIVATE "CA_LINUX_BUILD")
elseif(APPLE)
  # Define macOS-specific options here
  target_compile_definitions(COM PRIVATE "COM_MAC_BUILD")
  target_compile_definitions(CA PRIVATE "CA_MAC_BUILD")
endif()

# Set the LINKER_LANGUAGE property for the target
set_target_properties(COM PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(CA PROPERTIES LINKER_LANGUAGE CXX)



# If you have any libraries to link against, use target_link_libraries()
# Example:
# target_link_libraries(COM PRIVATE some_other_library)

# For verbose output during build, uncomment the following line
#set(CMAKE_VERBOSE_MAKEFILE ON)

# If there are specific compile options you need, you can set them for your target
# Example:
# target_compile_options(COM PRIVATE -Wall -Wextra)


