#include <stdio.h>

#include "print_sys_message.h"
#include "colors.h"

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