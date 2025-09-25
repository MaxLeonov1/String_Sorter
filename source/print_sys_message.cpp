#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------------------------*/

#include "print_sys_message.h"
#include "colors.h"
#include "enum.h"

/*-----------------------------------------------------------------------------------------------*/

void SystemStatusHandler ( ErrorCode status, ProcessName process) {

    switch ( status) {

        case MEMORY_ALLOCATE_ERROR:
            MemAloccErrorPrint();
            exit(0);

        case FILE_OPEN_ERROR:
            FileOpenErrorPrint();
            exit(0);

        // case SUCCSESFUL:
        //     ProcessTypeHandler( process);

    }

}

/*-----------------------------------------------------------------------------------------------*/

void ProcessTypeHandler ( ProcessName process) {

    process = SCAN_PROCESS;

    switch ( process) {

        case SCAN_PROCESS:
            ProcessFinishedPrint ("SCAN");
        
        case SORTING_PROCESS:
            ProcessFinishedPrint ("SORTING");

        case OUTPUT_PROCESS:
            ProcessFinishedPrint ("OUTPUT");

    }

}

/*-----------------------------------------------------------------------------------------------*/

void ProcessFinishedPrint ( const char* process_name) {

    printf("%s-------------------------------\n"
           "%s SUCCSESSFUL\n"
             "-------------------------------%s\n",
             GREEN, process_name, RES_COL);


}

/*-----------------------------------------------------------------------------------------------*/

void UndefCommandPrint ( void) {

    printf("%s----------------\n"
             "Undefined comand\n"
             "----------------%s\n",
             RED, RES_COL);

}

/*-----------------------------------------------------------------------------------------------*/

void MemAloccErrorPrint ( void) {

    printf("%s-----------------------\n"
             "Memory allocation error\n"
             "-----------------------%s\n",
             RED, RES_COL);

}

/*-----------------------------------------------------------------------------------------------*/

void FileOpenErrorPrint ( void) {

    printf("%s---------------\n"
             "File open error\n"
             "---------------%s\n",
             RED, RES_COL);

}