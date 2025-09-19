#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------*/

#include "supporting_functions.h"
#include "print_sys_message.h"
#include "sort_functions.h"
#include "input_output_text.h"
#include "structs.h"
#include "colors.h"
#include "enum.h"

/*-----------------------------------------------------------------------------------------------*/

int main ( const int argc, const char* argv[]) {

    Text all_text  = {};
    int  sort_type = 0;
    ErrorCode status = SUCCSESFUL;

    if (argc >= 2) {

        if ((strcmp(argv[1], "--sort") == 0 ||
             strcmp(argv[1], "-s") == 0) &&
             (argc == 3 || argc == 4)) {

            if ( argc == 4) {

                if ( strcmp(argv[3], "--qsort") == 0 ||
                     strcmp(argv[3], "-qs") == 0 ) {

                     sort_type = QUICK_SORT;
                
                }

                if ( strcmp(argv[3], "--bublesort") == 0 ||
                     strcmp(argv[3], "-bs") == 0 ) {

                     sort_type = SLOW_BUBLE_SORT;
                
                }

            }

            status = ScanOnegin ( argv[2], &all_text);
            SystemStatusHandler ( status, SCAN_PROCESS);

            status = AllSort ( &all_text, sort_type);
            //SystemStatusHandler ( status, SORTING_PROCESS);

            status = OutputOnegin ( &all_text);
            //SystemStatusHandler ( status, OUTPUT_PROCESS);

            FreeText ( &all_text);

        } else if ((strcmp(argv[1], "--test") == 0 ||
                    strcmp(argv[1], "-t") == 0)) {

            printf("%s[sorry I have paws, I haven't made test :(]%s", YELLOW, RES_COL);

        } else {

            UndefCommandPrint();

        } 

    } else {

        UndefCommandPrint();

    }

    return 0;
}