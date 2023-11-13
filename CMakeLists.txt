# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# For verbose output during build, uncomment the following line
set(CMAKE_VERBOSE_MAKEFILE ON)

# Define the project name and the language you are using (C++)
project ("CA" LANGUAGES CXX)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the BASE directory for the project
set(CA_BASE "${CMAKE_CURRENT_SOURCE_DIR}/CA")
set(COM_BASE "${CMAKE_CURRENT_SOURCE_DIR}/COM")

# Define source files and headers for COM using file globbing
file(GLOB COM_SOURCE_FILES 
  "${COM_BASE}/bucketLib/*.c"
  "${COM_BASE}/calc/*.c"
  "${COM_BASE}/cvtFast/*.c"
  "${COM_BASE}/cxxTemplates/resourceLib.cpp"
  "${COM_BASE}/cxxTemplates/epicsOnce.cpp"
  "${COM_BASE}/cxxTemplates/epicsSingletonMutex.cpp"
  "${COM_BASE}/dbmf/*.c"
  "${COM_BASE}/ellLib/*.c"
  "${COM_BASE}/env/*.c"
  "${COM_BASE}/error/*.c"
  "${COM_BASE}/freeList/*.c"
  "${COM_BASE}/gpHash/*.c"
  "${COM_BASE}/macLib/*.c"
  "${COM_BASE}/misc/aToIPAddr.c"
  "${COM_BASE}/misc/adjustment.c"
  "${COM_BASE}/misc/cantProceed.c"
  "${COM_BASE}/misc/epicsConvert.c"
  "${COM_BASE}/misc/epicsExit.c"
  "${COM_BASE}/misc/epicsStdlib.c"
  "${COM_BASE}/misc/epicsString.c"
  "${COM_BASE}/misc/truncateFile.c"
  "${COM_BASE}/misc/ipAddrToAsciiAsynchronous.cpp"
  "${COM_BASE}/misc/epicsUnitTest.c"
  "${COM_BASE}/O.Common/*.c"
  "${COM_BASE}/osi/epicsThread.cpp"
  "${COM_BASE}/osi/epicsMutex.cpp"
  "${COM_BASE}/osi/epicsEvent.cpp"
  "${COM_BASE}/osi/epicsTime.cpp"
  "${COM_BASE}/osi/epicsMessageQueue.cpp"
  "${COM_BASE}/osi/epicsMath.cpp"
  "${COM_BASE}/osi/epicsGeneralTime.c"
  "${COM_BASE}/osi/osiClockTime.c"
  "${COM_BASE}/osi/osiSock.c"
  "${COM_BASE}/osi/epicsStdio.c"
  "${COM_BASE}/osi/devLibVME.c"
  if(WIN32)
  "${COM_BASE}/osi/os/WIN32/*.c"
  endif()
  "${COM_BASE}/pool/*.c"
  "${COM_BASE}/ring/*.c"
  "${COM_BASE}/taskwd/*.c"
  "${COM_BASE}/timer/*.cpp"
  "${COM_BASE}/iocsh/*.c"
)
file(GLOB COM_HEADER_FILES 
  "${COM_BASE}/bucketLib/*.h"
  "${COM_BASE}/calc/*.h"
  "${COM_BASE}/cppStd/*.h"
  "${COM_BASE}/cvtFast/*.h"
  "${COM_BASE}/cxxTemplates/resourceLib.h"
  "${COM_BASE}/cxxTemplates/tsDLList.h"
  "${COM_BASE}/cxxTemplates/tsSLList.h"
  "${COM_BASE}/cxxTemplates/tsMinMax.h"
  "${COM_BASE}/cxxTemplates/tsBTree.h"
  "${COM_BASE}/cxxTemplates/tsFreeList.h"
  "${COM_BASE}/cxxTemplates/epicsSingleton.h"
  "${COM_BASE}/cxxTemplates/epicsGuard.h"
  "${COM_BASE}/cxxTemplates/epicsOnce.h"
  "${COM_BASE}/dbmf/*.h"
  "${COM_BASE}/ellLib/*.h"
  "${COM_BASE}/env/*.h"
  "${COM_BASE}/error/*.h"
  "${COM_BASE}/freeList/*.h"
  "${COM_BASE}/gpHash/*.h"
  "${COM_BASE}/macLib/*.h"
  "${COM_BASE}/misc/adjustment.h"
  "${COM_BASE}/misc/cantProceed.h"
  "${COM_BASE}/misc/dbDefs.h"
  "${COM_BASE}/misc/epicsConvert.h"
  "${COM_BASE}/misc/epicsExit.h"
  "${COM_BASE}/misc/epicsStdlib.h"
  "${COM_BASE}/misc/epicsString.h"
  "${COM_BASE}/misc/epicsTypes.h"
  "${COM_BASE}/misc/shareLib.h"
  "${COM_BASE}/misc/epicsExport.h"
  "${COM_BASE}/misc/unixFileName.h"
  "${COM_BASE}/misc/locationException.h"
  "${COM_BASE}/misc/ipAddrToAsciiAsynchronous.h"
  "${COM_BASE}/misc/compilerDependencies.h"
  "${COM_BASE}/misc/epicsUnitTest.h"
  "${COM_BASE}/misc/testMain.h"
  "${COM_BASE}/O.Common/*.h"
  "${COM_BASE}/osi/osiSock.h"
  "${COM_BASE}/osi/epicsInterrupt.h"
  "${COM_BASE}/osi/epicsMutex.h"
  "${COM_BASE}/osi/epicsEvent.h"
  "${COM_BASE}/osi/epicsAssert.h"
  "${COM_BASE}/osi/epicsFindSymbol.h"
  "${COM_BASE}/osi/osiPoolStatus.h"
  "${COM_BASE}/osi/epicsThread.h"
  "${COM_BASE}/osi/epicsTime.h"
  "${COM_BASE}/osi/epicsGeneralTime.h"
  "${COM_BASE}/osi/generalTimeSup.h"
  "${COM_BASE}/osi/osiClockTime.h"
  "${COM_BASE}/osi/epicsSignal.h"
  "${COM_BASE}/osi/osiProcess.h"
  "${COM_BASE}/osi/osiWireFormat.h"
  "${COM_BASE}/osi/epicsEndian.h"
  "${COM_BASE}/osi/epicsMessageQueue.h"
  "${COM_BASE}/osi/epicsStdio.h"
  "${COM_BASE}/osi/epicsStdioRedirect.h"
  "${COM_BASE}/osi/devLib.h"
  "${COM_BASE}/osi/devLibVME.h"
  "${COM_BASE}/osi/devLibVMEImpl.h"
  if(WIN32)
  "${COM_BASE}/osi/os/WIN32/*.h"
  endif()
  "${COM_BASE}/pool/*.h"
  "${COM_BASE}/ring/*.h"
  "${COM_BASE}/taskwd/*.h"
  "${COM_BASE}/timer/*.h"
  "${COM_BASE}/iocsh/*.h"
)

# Add the COM library target
add_library(COM SHARED ${COM_SOURCE_FILES} ${COM_HEADER_FILES})

# Manually add directories to the COM target
#target_include_directories(COM PUBLIC "${COM_BASE}/as")
target_include_directories(COM PUBLIC "${COM_BASE}/bucketLib")
target_include_directories(COM PUBLIC "${COM_BASE}/calc")
target_include_directories(COM PUBLIC "${COM_BASE}/cppStd")
target_include_directories(COM PUBLIC "${COM_BASE}/cvtFast")
target_include_directories(COM PUBLIC "${COM_BASE}/cxxTemplates")
target_include_directories(COM PUBLIC "${COM_BASE}/dbmf")
target_include_directories(COM PUBLIC "${COM_BASE}/ellLib")
target_include_directories(COM PUBLIC "${COM_BASE}/env")
target_include_directories(COM PUBLIC "${COM_BASE}/error")
target_include_directories(COM PUBLIC "${COM_BASE}/freeList")
target_include_directories(COM PUBLIC "${COM_BASE}/gpHash")
target_include_directories(COM PUBLIC "${COM_BASE}/macLib")
target_include_directories(COM PUBLIC "${COM_BASE}/misc")
target_include_directories(COM PUBLIC "${COM_BASE}/O.Common")
target_include_directories(COM PUBLIC "${COM_BASE}/osi")
target_include_directories(COM PUBLIC "${COM_BASE}/osi/compiler/default")
if(WIN32)
  target_include_directories(COM PUBLIC "${COM_BASE}/osi/os/WIN32")
  target_include_directories(COM PUBLIC "${COM_BASE}/compiler/msvc")
elseif(UNIX AND NOT APPLE)
  target_include_directories(COM PUBLIC "${COM_BASE}/osi/os/Linux")
  target_include_directories(COM PUBLIC "${COM_BASE}/compiler/clang")
elseif(APPLE)
  target_include_directories(COM PUBLIC "${COM_BASE}/osi/os/Darwin")
  target_include_directories(COM PUBLIC "${COM_BASE}/compiler/clang")
endif()
target_include_directories(COM PUBLIC "${COM_BASE}/osi/os/default")
target_include_directories(COM PUBLIC "${COM_BASE}/pool")
target_include_directories(COM PUBLIC "${COM_BASE}/ring")
target_include_directories(COM PUBLIC "${COM_BASE}/taskwd")
target_include_directories(COM PUBLIC "${COM_BASE}/timer")
target_include_directories(COM PUBLIC "${COM_BASE}/iocsh")

# Define source files and headers for CA using file globbing
file(GLOB CA_SOURCE_FILES
"${CA_BASE}/access.cpp"
"${CA_BASE}/acctstRegister.cpp"
"${CA_BASE}/baseNMIU.cpp"
"${CA_BASE}/bhe.cpp"
"${CA_BASE}/ca_client_context.cpp"
"${CA_BASE}/cac.cpp"
"${CA_BASE}/cacChannel.cpp"
"${CA_BASE}/cacChannelNotify.cpp"
"${CA_BASE}/cacContextNotify.cpp"
"${CA_BASE}/cacReadNotify.cpp"
"${CA_BASE}/cacStateNotify.cpp"
"${CA_BASE}/cacWriteNotify.cpp"
"${CA_BASE}/CASG.cpp"
"${CA_BASE}/comBuf.cpp"
"${CA_BASE}/comQueRecv.cpp"
"${CA_BASE}/comQueSend.cpp"
"${CA_BASE}/convert.cpp"
"${CA_BASE}/disconnectGovernorTimer.cpp"
"${CA_BASE}/getCallback.cpp"
"${CA_BASE}/getCopy.cpp"
"${CA_BASE}/hostNameCache.cpp"
"${CA_BASE}/iocinf.cpp"
"${CA_BASE}/localHostName.cpp"
"${CA_BASE}/msgForMultiplyDefinedPV.cpp"
"${CA_BASE}/nciu.cpp"
"${CA_BASE}/netiiu.cpp"
"${CA_BASE}/netReadNotifyIO.cpp"
"${CA_BASE}/netSubscription.cpp"
"${CA_BASE}/netWriteNotifyIO.cpp"
"${CA_BASE}/noopiiu.cpp"
"${CA_BASE}/oldChannelNotify.cpp"
"${CA_BASE}/oldSubscription.cpp"
"${CA_BASE}/putCallback.cpp"
"${CA_BASE}/repeater.cpp"
"${CA_BASE}/repeaterSubscribeTimer.cpp"
"${CA_BASE}/searchTimer.cpp"
"${CA_BASE}/syncGroupNotify.cpp"
"${CA_BASE}/syncGroupReadNotify.cpp"
"${CA_BASE}/syncGroupWriteNotify.cpp"
"${CA_BASE}/syncgrp.cpp"
"${CA_BASE}/tcpiiu.cpp"
"${CA_BASE}/tcpRecvThread.cpp"
"${CA_BASE}/tcpRecvWatchdog.cpp"
"${CA_BASE}/tcpSendWatchdog.cpp"
"${CA_BASE}/templateInstances.cpp"
"${CA_BASE}/test_event.cpp"
"${CA_BASE}/udpiiu.cpp"

)

file(GLOB CA_HEADER_FILES 
"${CA_BASE}/addrList.h"
"${CA_BASE}/autoPtrDestroy.h"
"${CA_BASE}/autoPtrFreeList.h"
"${CA_BASE}/autoPtrRecycle.h"
"${CA_BASE}/bhe.h"
"${CA_BASE}/cac.h"
"${CA_BASE}/cacIO.h"
"${CA_BASE}/cadef.h"
"${CA_BASE}/caDiagnostics.h"
"${CA_BASE}/caerr.h"
"${CA_BASE}/caeventmask.h"
"${CA_BASE}/caProto.h"
"${CA_BASE}/caServerID.h"
"${CA_BASE}/comBuf.h"
"${CA_BASE}/comQueRecv.h"
"${CA_BASE}/comQueSend.h"
"${CA_BASE}/db_access.h"
"${CA_BASE}/disconnectGovernorTimer.h"
"${CA_BASE}/hostNameCache.h"
"${CA_BASE}/inetAddrID.h"
"${CA_BASE}/iocinf.h"
"${CA_BASE}/localHostName.h"
"${CA_BASE}/msgForMultiplyDefinedPV.h"
"${CA_BASE}/nciu.h"
"${CA_BASE}/net_convert.h"
"${CA_BASE}/netiiu.h"
"${CA_BASE}/netIO.h"
"${CA_BASE}/noopiiu.h"
"${CA_BASE}/oldAccess.h"
"${CA_BASE}/repeaterClient.h"
"${CA_BASE}/repeaterSubscribeTimer.h"
"${CA_BASE}/SearchDest.h"
"${CA_BASE}/searchTimer.h"
"${CA_BASE}/sgAutoPtr.h"
"${CA_BASE}/syncGroup.h"
"${CA_BASE}/topRecvWatchdog.h"
"${CA_BASE}/topSendWatchdog.h"
"${CA_BASE}/ucx.h"
"${CA_BASE}/udpiiu.h"
"${CA_BASE}/virtualCircuit.h"
)

# Add the CA library target
add_library(CA SHARED ${CA_SOURCE_FILES} ${CA_HEADER_FILES})

# Manually add directories to the CA target
target_include_directories(CA PUBLIC "${CA_BASE}")

# Link CA against COM
target_link_libraries(CA PRIVATE COM)

# Platform-specific compiler options and preprocessor definitions
if(WIN32)
  # Define Windows-specific options here
  target_compile_definitions(COM PRIVATE "COM_WINDOWS_BUILD")
  target_compile_definitions(COM PRIVATE "__BYTE_ORDER=__LITTLE_ENDIAN")
  #target_compile_definitions(COM PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(COM PRIVATE "EPICS_BUILD_DLL")
  set_target_properties(COM PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

  target_compile_definitions(CA PRIVATE "CA_WINDOWS_BUILD")
  target_compile_definitions(CA PRIVATE "__BYTE_ORDER=__LITTLE_ENDIAN")
  #target_compile_definitions(CA PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(CA PRIVATE "EPICS_BUILD_DLL")
  set_target_properties(CA PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
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

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# If you have any libraries to link against, use target_link_libraries()
# Example:
# target_link_libraries(COM PRIVATE some_other_library)



# If there are specific compile options you need, you can set them for your target
# Example:
# target_compile_options(COM PRIVATE -Wall -Wextra)


