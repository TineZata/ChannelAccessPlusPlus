# CMakeList.txt : CMake project for CA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Define the project name and the language you are using (C++)
project ("CA" LANGUAGES CXX)
project ("COM" LANGUAGES CXX)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define COM as a separate shared library
add_library(COM SHARED
    #"COM/misc/epicsExit.c"
    #"COM/osi/epicsThread.cpp"
    #"COM/as/asLibRoutines.c"
    #"COM/as/asTrapWrite.c"
    #"COM/as/asTrapWrite.c"
    #"COM/O.Common/asLib_lex.c"
    #"COM/bucketLib/bucketLib.c"
    # Add all other source files (.cpp) that are part of the COM library here.
    "COM/misc/epicsExit.c"
)

# Specify where the COM library's headers are
target_include_directories(COM PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/misc"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/cxxTemplates"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/as"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/cppStd"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/error"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/ellLib"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/timer"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/O.Common"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/freeList"
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/os/default"
    if(WIN32)
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/compiler/msvc"
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/os/WIN32"
    elseif(UNIX AND NOT APPLE)
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/compiler/gcc"
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/os/posix"
    elseif(APPLE)
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/compiler/clang"
      "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi/os/iOS"
    endif()
    "${CMAKE_CURRENT_SOURCE_DIR}/COM/osi"

    # Add any additional directories where COM's header files are located.
)

# Define CA as a separate shared library
add_library(CA SHARED
    "access.cpp"
    # Add all other source files (.cpp) that are part of the CA library here.
)

# Specify where the CA library's headers are
target_include_directories(CA PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}" # Adjust the path to where CA's headers are located
    "${CMAKE_CURRENT_SOURCE_DIR}/CA/misc" 
)

# Link CA against COM
target_link_libraries(CA PRIVATE COM)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Platform-specific compiler options and preprocessor definitions
if(WIN32)
  # Define Windows-specific options here
  target_compile_definitions(CA PRIVATE "CA_WINDOWS_BUILD")
  target_compile_definitions(CA PRIVATE "EPICS_BYTE_ORDER=EPICS_ENDIAN_LITTLE")
elseif(UNIX AND NOT APPLE)
  # Define Linux-specific options here
  target_compile_definitions(CA PRIVATE "CA_LINUX_BUILD")
  target_compile_definitions(CA PRIVATE "EPICS_BYTE_ORDER=EPICS_ENDIAN_BIG")
elseif(APPLE)
  # Define macOS-specific options here
  target_compile_definitions(CA PRIVATE "CA_MAC_BUILD")
  target_compile_definitions(CA PRIVATE "EPICS_BYTE_ORDER=EPICS_ENDIAN_BIG")
endif()

set_target_properties(COM PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(CA PROPERTIES LINKER_LANGUAGE CXX)
# TODO: Add tests and install targets if needed.
