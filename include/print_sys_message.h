#ifndef __PRINT_SYS_MESSAGE__
#define __PRINT_SYS_MESSAGE__

/*-------------------------------------------------------*/
#include "enum.h"
/*-------------------------------------------------------*/

void MemAloccErrorPrint   ( void);
void UndefCommandPrint    ( void);
void FileOpenErrorPrint   ( void);
void ProcessFinishedPrint ( const char* process_name);
void SystemStatusHandler  ( ErrorCode status, ProcessName process);
void ProcessTypeHandler   ( ProcessName process);

/*-------------------------------------------------------*/

#endif