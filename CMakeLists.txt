﻿# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# For verbose output during build, uncomment the following line
set(CMAKE_VERBOSE_MAKEFILE ON)

# Define the project name and the language you are using (C++)
project ("CA" LANGUAGES C CXX)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the BASE directory for the project
set(CA_BASE "${CMAKE_CURRENT_SOURCE_DIR}/CA")
set(COM_BASE "${CA_BASE}/COM")

# Set the RPATH
set(CMAKE_INSTALL_RPATH "$ORIGIN")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Define source files and headers for COM
set(CA_SOURCE_FILES 
  #"${COM_BASE}/as/asLibRoutines.c"
  #"${COM_BASE}/as/asTrapWrite.c"
  "${COM_BASE}/bucketLib/bucketLib.c"
  "${COM_BASE}/calc/postfix.c"
  "${COM_BASE}/calc/calcPerform.c"
  "${COM_BASE}/cvtFast/cvtFast.c"
  #"${COM_BASE}/cxxTemplates/resourceLib.cpp"
  #"${COM_BASE}/cxxTemplates/epicsOnce.cpp"
  "${COM_BASE}/cxxTemplates/epicsSingletonMutex.cpp"
  "${COM_BASE}/dbmf/dbmf.c"
  "${COM_BASE}/ellLib/ellLib.c"
  "${COM_BASE}/ellLib/ellSort.c"
  "${COM_BASE}/env/envSubr.c"
  "${COM_BASE}/error/errlog.c"
  "${COM_BASE}/error/errSymLib.c"
  "${COM_BASE}/fdmgr/fdManager.cpp"
  "${COM_BASE}/fdmgr/fdmgr.cpp"
  "${COM_BASE}/freeList/freeListLib.c"
  "${COM_BASE}/gpHash/gpHashLib.c"
  "${COM_BASE}/iocsh/iocsh.cpp"
  "${COM_BASE}/iocsh/libComRegister.c"
  "${COM_BASE}/iocsh/registry.c"
  "${COM_BASE}/log/iocLog.c"
  "${COM_BASE}/log/logClient.c"
  "${COM_BASE}/macLib/macCore.c"
  "${COM_BASE}/macLib/macEnv.c"
  "${COM_BASE}/macLib/macUtil.c"
  "${COM_BASE}/misc/alarmString.c"
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
  "${COM_BASE}/O.Common/asLib.c"
  #"${COM_BASE}/O.Common/asLib_lex.c"
  "${COM_BASE}/O.Common/envData.c"
  "${COM_BASE}/O.Common/errSymTbl.c"
  "${COM_BASE}/osi/devLibVME.c"
  "${COM_BASE}/osi/epicsEvent.cpp"
  "${COM_BASE}/osi/epicsGeneralTime.c"
  "${COM_BASE}/osi/epicsMath.cpp"
  "${COM_BASE}/osi/epicsMessageQueue.cpp"
  "${COM_BASE}/osi/epicsMutex.cpp"
  "${COM_BASE}/osi/epicsStackTrace.c"
  "${COM_BASE}/osi/epicsStdio.c"
  "${COM_BASE}/osi/epicsThread.cpp"
  "${COM_BASE}/osi/epicsTime.cpp"
  "${COM_BASE}/osi/osiClockTime.c"
  #"${COM_BASE}/osi/osiNTPTime.c"
  "${COM_BASE}/osi/osiSock.c"
  "${COM_BASE}/osi/os/default/osdInterrupt.c"
  "${COM_BASE}/osi/os/default/epicsReadline.c"
  "${COM_BASE}/osi/os/default/osdMessageQueue.cpp"
  "${COM_BASE}/osi/os/default/osdFindAddr.c"
  "${COM_BASE}/osi/os/default/devLibVMEOSD.c"
  "${COM_BASE}/osi/os/default/osdSpin.c"
  "${COM_BASE}/osi/os/default/osdThreadHooks.c"
  "${COM_BASE}/osi/os/default/osdAssert.c"
  #"${COM_BASE}/osi/os/default/osdNetIntf.c"
  "${COM_BASE}/pool/poolJob.c"
  "${COM_BASE}/pool/threadPool.c"
  "${COM_BASE}/ring/epicsRingBytes.c"
  "${COM_BASE}/ring/epicsRingPointer.cpp"
  "${COM_BASE}/taskwd/taskwd.c"
  "${COM_BASE}/timer/epicsTimer.cpp"
  "${COM_BASE}/timer/timer.cpp"
  "${COM_BASE}/timer/timerQueue.cpp"
  "${COM_BASE}/timer/timerQueueActive.cpp"
  "${COM_BASE}/timer/timerQueueActiveMgr.cpp"
  "${COM_BASE}/timer/timerQueuePassive.cpp"
)
if(WIN32)
  list(APPEND CA_SOURCE_FILES 
    "${COM_BASE}/osi/os/WIN32/epicsGetopt.c"
    "${COM_BASE}/osi/os/WIN32/epicsSocketConvertErrnoToString.cpp"
    "${COM_BASE}/osi/os/WIN32/epicsTempFile.cpp"
    "${COM_BASE}/osi/os/WIN32/forceBadAllocException.cpp"
    "${COM_BASE}/osi/os/WIN32/osdBackTrace.cpp"
    "${COM_BASE}/osi/os/WIN32/osdEnv.c"
    "${COM_BASE}/osi/os/WIN32/osdEvent.c"
    "${COM_BASE}/osi/os/WIN32/osdFindSymbol.c"
    "${COM_BASE}/osi/os/WIN32/osdMutex.c"
    "${COM_BASE}/osi/os/WIN32/osdNetIntf.c"
    "${COM_BASE}/osi/os/WIN32/osdPoolStatus.c"
    "${COM_BASE}/osi/os/WIN32/osdProcess.c"
    "${COM_BASE}/osi/os/WIN32/osdSignal.cpp"
    "${COM_BASE}/osi/os/WIN32/osdSock.c"
    "${COM_BASE}/osi/os/WIN32/osdSockAddrReuse.cpp"
    "${COM_BASE}/osi/os/WIN32/osdSockUnsentCount.c"
    "${COM_BASE}/osi/os/WIN32/osdStdio.c"
    "${COM_BASE}/osi/os/WIN32/osdThread.c"
    "${COM_BASE}/osi/os/WIN32/osdThreadExtra.c"
    "${COM_BASE}/osi/os/WIN32/osdTime.cpp"
    "${COM_BASE}/osi/os/WIN32/setThreadName.cpp"
    "${COM_BASE}/osi/os/WIN32/systemCallIntMech.cpp"
  )
elseif(UNIX AND NOT APPLE)
  list(APPEND CA_SOURCE_FILES
    "${COM_BASE}/osi/os/Linux/osdBackTrace.cpp"
    #"${COM_BASE}/osi/os/Linux/osdFindAddr.c"
    #"${COM_BASE}/osi/os/Linux/osdElfFindAddr.c"
    "${COM_BASE}/osi/os/Linux/osdSockUnsentCount.c"
    "${COM_BASE}/osi/os/Linux/osdThreadExtra.c"
    "${COM_BASE}/osi/os/Linux/osdThread.c"
    "${COM_BASE}/osi/os/Linux/osdTime.cpp"
    "${COM_BASE}/osi/os/Linux/osdSock.c"
    "${COM_BASE}/osi/os/Linux/osdSignal.cpp"
    "${COM_BASE}/osi/os/Linux/osdProcess.c"
    "${COM_BASE}/osi/os/Linux/osdSockAddrReuse.cpp"
    "${COM_BASE}/osi/os/Linux/osdStdio.c"
    #"${COM_BASE}/osi/os/posix/osdElfFindAddr.c"
    # Missing from Linux... copied from somewhere else
    "${COM_BASE}/osi/os/Linux/osdMutex.c"
    "${COM_BASE}/osi/os/Linux/osdEvent.c"
    "${COM_BASE}/osi/os/Linux/osdNetIntf.c"
  )
elseif(APPLE)
  list(APPEND CA_SOURCE_FILES
    "${COM_BASE}/osi/os/Darwin/osdBackTrace.cpp"
    "${COM_BASE}/osi/os/Darwin/osdFindAddr.c"
    "${COM_BASE}/osi/os/Darwin/osdSockAddrReuse.cpp"
    "${COM_BASE}/osi/os/Darwin/osdSockUnsentCount.c"
    "${COM_BASE}/osi/os/Darwin/osdThreadExtra.c"
    "${COM_BASE}/osi/os/Darwin/osdTime.cpp"
  )
endif()

set(CA_HEADER_FILES
  "${COM_BASE}/as/asLib.h"
  "${COM_BASE}/as/asTrapWrite.h"
  "${COM_BASE}/bucketLib/bucketLib.h"
  "${COM_BASE}/calc/postfix.h"
  "${COM_BASE}/calc/postfixPvt.h"
  "${COM_BASE}/cvtFast/cvtFast.h"
  "${COM_BASE}/cxxTemplates/epicsGuard.h"
  #"${COM_BASE}/cxxTemplates/epicsOnce.h"
  "${COM_BASE}/cxxTemplates/epicsSingleton.h"
  #"${COM_BASE}/cxxTemplates/resourceLib.h"
  #"${COM_BASE}/cxxTemplates/tsBTree.h"
  #"${COM_BASE}/cxxTemplates/tsDLList.h"
  #"${COM_BASE}/cxxTemplates/tsFreeList.h"
  #"${COM_BASE}/cxxTemplates/tsMinMax.h"
  #"${COM_BASE}/cxxTemplates/tsSLList.h"
  "${COM_BASE}/dbmf/dbmf.h"
  "${COM_BASE}/ellLib/ellLib.h"
  "${COM_BASE}/env/envDefs.h"
  "${COM_BASE}/error/errlog.h"
  "${COM_BASE}/error/errMdef.h"
  "${COM_BASE}/error/error.h"
  "${COM_BASE}/error/errSymTbl.h"
  "${COM_BASE}/fdmgr/fdManager.h"
  "${COM_BASE}/fdmgr/fdmgr.h"
  "${COM_BASE}/freeList/freeList.h"
  "${COM_BASE}/gpHash/gpHash.h"
  "${COM_BASE}/iocsh/iocsh.h"
  "${COM_BASE}/iocsh/libComRegister.h"
  "${COM_BASE}/iocsh/registry.h"
  "${COM_BASE}/log/iocLog.h"
  "${COM_BASE}/log/logClient.h"
  "${COM_BASE}/macLib/macLib.h"
  "${COM_BASE}/misc/adjustment.h"
  "${COM_BASE}/misc/alarmString.h"
  "${COM_BASE}/misc/cantProceed.h"
  "${COM_BASE}/misc/epicsConvert.h"
  "${COM_BASE}/misc/epicsExit.h"
  "${COM_BASE}/misc/epicsStdlib.h"
  "${COM_BASE}/misc/epicsString.h"
  "${COM_BASE}/misc/epicsUnitTest.h"
  "${COM_BASE}/misc/ipAddrToAsciiAsynchronous.h"
  "${COM_BASE}/misc/locationException.h"
  "${COM_BASE}/misc/shareLib.h"
  "${COM_BASE}/misc/testMain.h"
  "${COM_BASE}/misc/unixFileName.h"
  "${COM_BASE}/misc/dbDefs.h"
  "${COM_BASE}/O.Common/epicsVersion.h"
  "${COM_BASE}/osi/compilerDependencies.h"
  "${COM_BASE}/osi/devLib.h"
  "${COM_BASE}/osi/devLibVME.h"
  "${COM_BASE}/osi/devLibVMEImpl.h"
  "${COM_BASE}/osi/epicsAssert.h"
  "${COM_BASE}/osi/epicsAtomic.h"
  "${COM_BASE}/osi/epicsAtomicDefault.h"
  "${COM_BASE}/osi/epicsEndian.h"
  "${COM_BASE}/osi/epicsEvent.h"
  "${COM_BASE}/osi/epicsFindSymbol.h"
  "${COM_BASE}/osi/epicsGeneralTime.h"
  "${COM_BASE}/osi/epicsInterrupt.h"
  "${COM_BASE}/osi/epicsMessageQueue.h"
  "${COM_BASE}/osi/epicsMutex.h"
  "${COM_BASE}/osi/epicsSignal.h"
  "${COM_BASE}/osi/epicsSpin.h"
  "${COM_BASE}/osi/epicsStackTrace.h"
  "${COM_BASE}/osi/epicsStackTracePvt.h"
  "${COM_BASE}/osi/epicsStdio.h"
  "${COM_BASE}/osi/epicsStdioRedirect.h"
  "${COM_BASE}/osi/epicsTempFile.h"
  "${COM_BASE}/osi/epicsThread.h"
  "${COM_BASE}/osi/epicsTime.h"
  "${COM_BASE}/osi/generalTimeSup.h"
  "${COM_BASE}/osi/osiClockTime.h"
  #"${COM_BASE}/osi/osiNTPTime.h"
  "${COM_BASE}/osi/osiPoolStatus.h"
  "${COM_BASE}/osi/osiProcess.h"
  "${COM_BASE}/osi/osiSock.h"
  "${COM_BASE}/osi/osiWireFormat.h"
  "${COM_BASE}/osi/os/default/osdInterrupt.h"
  "${COM_BASE}/osi/os/default/epicsReadline.h"
  "${COM_BASE}/osi/os/default/osdMessageQueue.h"
  "${COM_BASE}/pool/poolPriv.h"
  "${COM_BASE}/ring/epicsRingBytes.h"
  "${COM_BASE}/ring/epicsRingPointer.h"
  "${COM_BASE}/taskwd/taskwd.h"
  "${COM_BASE}/timer/epicsTimer.h"
  "${COM_BASE}/timer/timerPrivate.h"
)

if(WIN32)
  list(APPEND CA_HEADER_FILES 
    "${COM_BASE}/osi/os/WIN32/epicsAtomicMS.h"
    "${COM_BASE}/osi/os/WIN32/epicsAtomicOSD.h"
    "${COM_BASE}/osi/os/WIN32/epicsGetopt.h"
    "${COM_BASE}/osi/os/WIN32/epicsMath.h"
    "${COM_BASE}/osi/os/WIN32/osdEvent.h"
    "${COM_BASE}/osi/os/WIN32/osdMutex.h"
    "${COM_BASE}/osi/os/WIN32/osdPoolStatus.h"
    "${COM_BASE}/osi/os/WIN32/osdSock.h"
    "${COM_BASE}/osi/os/WIN32/osdStrtod.h"
    "${COM_BASE}/osi/os/WIN32/osdThread.h"
    "${COM_BASE}/osi/os/WIN32/osdThreadPvt.h"
    "${COM_BASE}/osi/os/WIN32/osdTime.h"
    "${COM_BASE}/osi/os/WIN32/osdWireConfig.h"
    "${COM_BASE}/osi/os/WIN32/osiFileName.h"
    "${COM_BASE}/osi/os/WIN32/osiUnistd.h"
    "${COM_BASE}/osi/compiler/msvc/compilerSpecific.h"
    "${COM_BASE}/osi/compiler/msvc/epicsAtomicCD.h"
  )
elseif(UNIX AND NOT APPLE)
  list(APPEND CA_HEADER_FILES
    "${COM_BASE}/osi/os/Linux/osdSock.h"
    "${COM_BASE}/osi/os/Linux/osdThread.h"
    "${COM_BASE}/osi/os/Linux/osdTime.h"
    "${COM_BASE}/osi/os/Linux/osdWireConfig.h"
    "${COM_BASE}/osi/os/Linux/osiFileName.h"
    "${COM_BASE}/osi/os/Linux/osiUnistd.h"
    "${COM_BASE}/osi/compiler/gcc/compilerSpecific.h"
    "${COM_BASE}/osi/compiler/gcc/epicsAtomicCD.h"
    # missing... copied from WIN32
    "${COM_BASE}/osi/os/Linux/osdStrtod.h"
    "${COM_BASE}/osi/os/Linux/epicsMath.h"
  )
elseif(APPLE)
  list(APPEND CA_HEADER_FILES
    "${COM_BASE}/osi/os/Darwin/osdSock.h"
    "${COM_BASE}/osi/os/Darwin/osdTime.h"
    "${COM_BASE}/osi/os/Darwin/osiFileName.h"
    "${COM_BASE}/osi/compiler/clang/compilerSpecific.h"
    "${COM_BASE}/osi/compiler/clang/epicsAtomicCD.h"
    # missing from Darwin
    
)
endif()

# Define source files and headers for CA using file globbing
list(APPEND CA_SOURCE_FILES
"${CA_BASE}/access.cpp"
"${CA_BASE}/acctstRegister.cpp"
"${CA_BASE}/acctstMain.c"
"${CA_BASE}/acctst.c"
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

list(APPEND CA_HEADER_FILES 
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
"${CA_BASE}/tcpRecvWatchdog.h"
"${CA_BASE}/tcpSendWatchdog.h"
"${CA_BASE}/ucx.h"
"${CA_BASE}/udpiiu.h"
"${CA_BASE}/virtualCircuit.h"
)

# Add the CA library target
add_library(CA SHARED ${CA_SOURCE_FILES} ${CA_HEADER_FILES})

# Manually add directories to the CA target
target_include_directories(CA PUBLIC "${COM_BASE}/as")
target_include_directories(CA PUBLIC "${COM_BASE}/bucketLib")
target_include_directories(CA PUBLIC "${COM_BASE}/calc")
target_include_directories(CA PUBLIC "${COM_BASE}/cppStd")
target_include_directories(CA PUBLIC "${COM_BASE}/cvtFast")
target_include_directories(CA PUBLIC "${COM_BASE}/cxxTemplates")
target_include_directories(CA PUBLIC "${COM_BASE}/dbmf")
target_include_directories(CA PUBLIC "${COM_BASE}/ellLib")
target_include_directories(CA PUBLIC "${COM_BASE}/env")
target_include_directories(CA PUBLIC "${COM_BASE}/error")
target_include_directories(CA PUBLIC "${COM_BASE}/fdmgr")
target_include_directories(CA PUBLIC "${COM_BASE}/freeList")
target_include_directories(CA PUBLIC "${COM_BASE}/gpHash")
target_include_directories(CA PUBLIC "${COM_BASE}/iocsh")
target_include_directories(CA PUBLIC "${COM_BASE}/log")
target_include_directories(CA PUBLIC "${COM_BASE}/macLib")
target_include_directories(CA PUBLIC "${COM_BASE}/misc")
target_include_directories(CA PUBLIC "${COM_BASE}/O.Common")
target_include_directories(CA PUBLIC "${COM_BASE}/osi")
target_include_directories(CA PUBLIC "${COM_BASE}/osi/compiler/default")
if(WIN32)
  target_include_directories(CA PUBLIC "${COM_BASE}/osi/os/WIN32")
  target_include_directories(CA PUBLIC "${COM_BASE}/compiler/msvc")
elseif(UNIX AND NOT APPLE)
  target_include_directories(CA PUBLIC "${COM_BASE}/osi/os/Linux")
  #target_include_directories(CA PUBLIC "${COM_BASE}/osi/os/posix")
  target_include_directories(CA PUBLIC "${COM_BASE}/compiler/gcc")
elseif(APPLE)
  target_include_directories(CA PUBLIC "${COM_BASE}/osi/os/Darwin")
  target_include_directories(CA PUBLIC "${COM_BASE}/compiler/clang")
endif()
target_include_directories(CA PUBLIC "${COM_BASE}/osi/os/default")
target_include_directories(CA PUBLIC "${COM_BASE}/pool")
target_include_directories(CA PUBLIC "${COM_BASE}/ring")
target_include_directories(CA PUBLIC "${COM_BASE}/taskwd")
target_include_directories(CA PUBLIC "${COM_BASE}/timer")
target_include_directories(CA PUBLIC "${COM_BASE}/iocsh")

target_include_directories(CA PUBLIC "${CA_BASE}")
target_include_directories(CA PUBLIC "${COM_BASE}")

# Platform-specific compiler options and preprocessor definitions
if(WIN32)
  target_compile_definitions(CA PRIVATE "__BYTE_ORDER=__LITTLE_ENDIAN")
  #target_compile_definitions(CA PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(CA PRIVATE "EPICS_BUILD_DLL")
  target_compile_definitions(CA PRIVATE "CA_WINDOWS_BUILD")
  set_target_properties(CA PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
  target_link_libraries(CA PRIVATE Ws2_32)
elseif(UNIX AND NOT APPLE)
  # Define Linux-specific options here
  target_compile_definitions(CA PRIVATE "__BYTE_ORDER=__BIG_ENDIAN")
  #target_compile_definitions(CA PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(CA PRIVATE "EPICS_BUILD_DLL")
  target_compile_definitions(CA PRIVATE "CA_LINUX_BUILD")
elseif(APPLE)
  # Define macOS-specific options here
  target_compile_definitions(CA PRIVATE "__BYTE_ORDER=__BIG_ENDIAN")
  #target_compile_definitions(CA PRIVATE "EPICS_CALL_DLL")
  target_compile_definitions(CA PRIVATE "EPICS_BUILD_DLL")
  target_compile_definitions(CA PRIVATE "CA_MAC_BUILD")
endif()

# Set the LINKER_LANGUAGE property for the target
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

