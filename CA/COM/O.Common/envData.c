/* Generated file envData.c
 *
 * Created from
 *   C:/Users/saf92974/Documents/0.repos/epics.dotnet/base-3.15.9/src/libCom/env/envDefs.h
 *   C:/Users/saf92974/Documents/0.repos/epics.dotnet/base-3.15.9/configure/CONFIG_ENV
 *   C:/Users/saf92974/Documents/0.repos/epics.dotnet/base-3.15.9/configure/CONFIG_SITE_ENV
 */

#include <stddef.h>
#define epicsExportSharedSymbols
#include "envDefs.h"

epicsShareDef const ENV_PARAM EPICS_CA_ADDR_LIST =
    {"EPICS_CA_ADDR_LIST", ""};
epicsShareDef const ENV_PARAM EPICS_CA_CONN_TMO =
    {"EPICS_CA_CONN_TMO", "30.0"};
epicsShareDef const ENV_PARAM EPICS_CA_AUTO_ADDR_LIST =
    {"EPICS_CA_AUTO_ADDR_LIST", "YES"};
epicsShareDef const ENV_PARAM EPICS_CA_REPEATER_PORT =
    {"EPICS_CA_REPEATER_PORT", "5065"};
epicsShareDef const ENV_PARAM EPICS_CA_SERVER_PORT =
    {"EPICS_CA_SERVER_PORT", "5064"};
epicsShareDef const ENV_PARAM EPICS_CA_MAX_ARRAY_BYTES =
    {"EPICS_CA_MAX_ARRAY_BYTES", "16384"};
epicsShareDef const ENV_PARAM EPICS_CA_MAX_SEARCH_PERIOD =
    {"EPICS_CA_MAX_SEARCH_PERIOD", "300.0"};
epicsShareDef const ENV_PARAM EPICS_CA_NAME_SERVERS =
    {"EPICS_CA_NAME_SERVERS", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_INTF_ADDR_LIST =
    {"EPICS_CAS_INTF_ADDR_LIST", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_IGNORE_ADDR_LIST =
    {"EPICS_CAS_IGNORE_ADDR_LIST", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_AUTO_BEACON_ADDR_LIST =
    {"EPICS_CAS_AUTO_BEACON_ADDR_LIST", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_BEACON_ADDR_LIST =
    {"EPICS_CAS_BEACON_ADDR_LIST", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_SERVER_PORT =
    {"EPICS_CAS_SERVER_PORT", ""};
epicsShareDef const ENV_PARAM EPICS_CA_BEACON_PERIOD =
    {"EPICS_CA_BEACON_PERIOD", "15.0"};
epicsShareDef const ENV_PARAM EPICS_CAS_BEACON_PERIOD =
    {"EPICS_CAS_BEACON_PERIOD", ""};
epicsShareDef const ENV_PARAM EPICS_CAS_BEACON_PORT =
    {"EPICS_CAS_BEACON_PORT", ""};
epicsShareDef const ENV_PARAM EPICS_BUILD_COMPILER_CLASS =
    {"EPICS_BUILD_COMPILER_CLASS", ""};
epicsShareDef const ENV_PARAM EPICS_BUILD_OS_CLASS =
    {"EPICS_BUILD_OS_CLASS", ""};
epicsShareDef const ENV_PARAM EPICS_BUILD_TARGET_ARCH =
    {"EPICS_BUILD_TARGET_ARCH", ""};
epicsShareDef const ENV_PARAM EPICS_TZ =
    {"EPICS_TZ", "CST6CDT,M3.2.0/2,M11.1.0/2"};
epicsShareDef const ENV_PARAM EPICS_TS_NTP_INET =
    {"EPICS_TS_NTP_INET", ""};
epicsShareDef const ENV_PARAM EPICS_IOC_LOG_PORT =
    {"EPICS_IOC_LOG_PORT", "7004"};
epicsShareDef const ENV_PARAM EPICS_IOC_LOG_INET =
    {"EPICS_IOC_LOG_INET", ""};
epicsShareDef const ENV_PARAM EPICS_IOC_LOG_FILE_LIMIT =
    {"EPICS_IOC_LOG_FILE_LIMIT", "1000000"};
epicsShareDef const ENV_PARAM EPICS_IOC_LOG_FILE_NAME =
    {"EPICS_IOC_LOG_FILE_NAME", ""};
epicsShareDef const ENV_PARAM EPICS_IOC_LOG_FILE_COMMAND =
    {"EPICS_IOC_LOG_FILE_COMMAND", ""};
epicsShareDef const ENV_PARAM EPICS_CMD_PROTO_PORT =
    {"EPICS_CMD_PROTO_PORT", ""};
epicsShareDef const ENV_PARAM EPICS_AR_PORT =
    {"EPICS_AR_PORT", "7002"};
epicsShareDef const ENV_PARAM IOCSH_PS1 =
    {"IOCSH_PS1", "epics> "};
epicsShareDef const ENV_PARAM IOCSH_HISTSIZE =
    {"IOCSH_HISTSIZE", "50"};

epicsShareDef const ENV_PARAM* env_param_list[] = {
    &EPICS_CA_ADDR_LIST, &EPICS_CA_CONN_TMO, &EPICS_CA_AUTO_ADDR_LIST,
    &EPICS_CA_REPEATER_PORT, &EPICS_CA_SERVER_PORT,
    &EPICS_CA_MAX_ARRAY_BYTES, &EPICS_CA_MAX_SEARCH_PERIOD,
    &EPICS_CA_NAME_SERVERS, &EPICS_CAS_INTF_ADDR_LIST,
    &EPICS_CAS_IGNORE_ADDR_LIST, &EPICS_CAS_AUTO_BEACON_ADDR_LIST,
    &EPICS_CAS_BEACON_ADDR_LIST, &EPICS_CAS_SERVER_PORT,
    &EPICS_CA_BEACON_PERIOD, &EPICS_CAS_BEACON_PERIOD,
    &EPICS_CAS_BEACON_PORT, &EPICS_BUILD_COMPILER_CLASS,
    &EPICS_BUILD_OS_CLASS, &EPICS_BUILD_TARGET_ARCH, &EPICS_TZ,
    &EPICS_TS_NTP_INET, &EPICS_IOC_LOG_PORT, &EPICS_IOC_LOG_INET,
    &EPICS_IOC_LOG_FILE_LIMIT, &EPICS_IOC_LOG_FILE_NAME,
    &EPICS_IOC_LOG_FILE_COMMAND, &EPICS_CMD_PROTO_PORT, &EPICS_AR_PORT,
    &IOCSH_PS1, &IOCSH_HISTSIZE, NULL
};
