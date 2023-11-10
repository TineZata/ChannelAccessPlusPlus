# CMakeList.txt : CMake project for CA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Define the project name and the language you are using (C++)
project ("CA" LANGUAGES CXX)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the BASE directory for the project
set(CA_BASE "${CMAKE_CURRENT_SOURCE_DIR}/CA")

# Define source files and headers for COM using file globbing
file(GLOB COM_SOURCE_FILES 
  "${CA_BASE}/COM/as/*.c"
  "${CA_BASE}/COM/bucketLib/*.c"
  "${CA_BASE}/COM/calc/*.c"
  "${CA_BASE}/COM/cvtFast/*.c"
  "${CA_BASE}/COM/cssTemplates/*.c"
  "${CA_BASE}/COM/cssTemplates/*.cpp"
  "${CA_BASE}/COM/dbmf/*.c"
  "${CA_BASE}/COM/ellLib/*.c"
  "${CA_BASE}/COM/env/*.c"
  "${CA_BASE}/COM/error/*.c"
  "${CA_BASE}/COM/freeList/*.c"
  "${CA_BASE}/COM/gpHash/*.c"
  "${CA_BASE}/COM/macLib/*.c"
  "${CA_BASE}/COM/misc/*.cpp"
  "${CA_BASE}/COM/misc/*.c"
  "${CA_BASE}/COM/O.Common/*.c"
  "${CA_BASE}/COM/osi/*.c"
  if(WIN32)
  "${CA_BASE}/COM/osi/os/WIN32/*.c"
  endif()
  "${CA_BASE}/COM/osi/compiler/default/*.c"
  "${CA_BASE}/COM/osi/os/default/*.c"
  "${CA_BASE}/COM/osi/os/default/*.cpp"
  "${CA_BASE}/COM/pool/*.c"
  "${CA_BASE}/COM/ring/*.c"
  "${CA_BASE}/COM/taskwd/*.c"
  "${CA_BASE}/COM/timer/*.cpp"
  "${CA_BASE}/COM/iocsh/*.c"
)
file(GLOB COM_HEADER_FILES 
  "${CA_BASE}/COM/as/*.h"
  "${CA_BASE}/COM/bucketLib/*.h"
  "${CA_BASE}/COM/calc/*.h"
  "${CA_BASE}/COM/cppStd/*.h"
  "${CA_BASE}/COM/cvtFast/*.h"
  "${CA_BASE}/COM/cssTemplates/*.h"
  "${CA_BASE}/COM/dbmf/*.h"
  "${CA_BASE}/COM/ellLib/*.h"
  "${CA_BASE}/COM/env/*.h"
  "${CA_BASE}/COM/error/*.h"
  "${CA_BASE}/COM/freeList/*.h"
  "${CA_BASE}/COM/gpHash/*.h"
  "${CA_BASE}/COM/macLib/*.h"
  "${CA_BASE}/COM/misc/*.h"
  "${CA_BASE}/COM/osi/*.h"
  if(WIN32)
  "${CA_BASE}/COM/osi/os/WIN32/*.h"
  endif()
  "${CA_BASE}/COM/osi/compiler/default/*.h"
  "${CA_BASE}/COM/osi/os/default/*.h"
  "${CA_BASE}/COM/pool/*.h"
  "${CA_BASE}/COM/ring/*.h"
  "${CA_BASE}/COM/taskwd/*.h"
  "${CA_BASE}/COM/timer/*.h"
  "${CA_BASE}/COM/iocsh/*.h"
)

message(STATUS "TZ: COM Source files: ${COM_SOURCE_FILES}")
message(STATUS "TZ: COM Header files: ${COM_HEADER_FILES}")

# Add the COM library target
add_library(COM SHARED ${COM_SOURCE_FILES} ${COM_HEADER_FILES})

# Manually add directories to the COM target
target_include_directories(COM PUBLIC "${CA_BASE}/COM/as")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/bucketLib")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/calc")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/cppStd")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/cvtFast")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/cxxTemplates")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/dbmf")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/ellLib")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/env")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/error")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/freeList")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/gpHash")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/macLib")
#"${CA_BASE}/COM/misc/*.cpp"
target_include_directories(COM PUBLIC "${CA_BASE}/COM/misc")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/O.Common")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi/compiler/default")
if(WIN32)
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi/os/WIN32")
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/compiler/msvc")
elseif(UNIX AND NOT APPLE)
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi/os/Linux")
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/compiler/clang")
elseif(APPLE)
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi/os/Darwin")
  target_include_directories(COM PUBLIC "${CA_BASE}/COM/compiler/clang")
endif()
#"${CA_BASE}/COM/osi/os/defualt/*.c"
target_include_directories(COM PUBLIC "${CA_BASE}/COM/osi/os/default")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/pool")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/ring")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/taskwd")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/timer")
target_include_directories(COM PUBLIC "${CA_BASE}/COM/iocsh")
#

# Define source files and headers for CA using file globbing
file(GLOB CA_SOURCE_FILES "${CA_BASE}/*.cpp" "${CA_BASE}/*.c")
file(GLOB CA_HEADER_FILES "${CA_BASE}/*.h")

message(STATUS "TZ: CA Source files: ${CA_SOURCE_FILES}")
message(STATUS "TZ: CA Header files: ${CA_HEADER_FILES}")

# Add the CA library target
add_library(CA SHARED ${CA_SOURCE_FILES} ${CA_HEADER_FILES})

# Link CA against COM
target_link_libraries(CA PRIVATE COM)

# Platform-specific compiler options and preprocessor definitions
if(WIN32)
  # Define Windows-specific options here
  #add_definitions(-D__BYTE_ORDER=__LITTLE_ENDIAN)
  target_compile_definitions(COM PRIVATE "COM_WINDOWS_BUILD")
  target_compile_definitions(COM PRIVATE "__BYTE_ORDER=__LITTLE_ENDIAN")
  target_compile_definitions(COM PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(COM PRIVATE "EPICS_BUILD_DLL")

  target_compile_definitions(CA PRIVATE "CA_WINDOWS_BUILD")
  target_compile_definitions(CA PRIVATE "__BYTE_ORDER=__LITTLE_ENDIAN")
  target_compile_definitions(CA PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(CA PRIVATE "EPICS_BUILD_DLL")
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


