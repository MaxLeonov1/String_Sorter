#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "supporting_functions.h"
#include "sort_functions.h"
#include "input_output_text.h"
#include "structs.h"
#include "colors.h"

/*-----------------------------------------------------------------------------------------------*/

int main ( const int argc, const char* argv[]) {

    Text all_text;

    if (argc >= 2) {

        if ((strcmp(argv[1], "--sort") == 0 ||
             strcmp(argv[1], "-s") == 0) &&
             argc == 3 &&
             fopen(argv[2], "r") != nullptr) {

            all_text.str_info = ScanOnegin ( argv[2], &all_text);

            AllSort ( &all_text);

            OutputOnegin ( &all_text);//TODO: separate sorting and printing

            free ( all_text.str_info);//TODO: make free func
            free ( all_text.standart_buffer);

        } else if ((strcmp(argv[1], "--test") == 0 ||
                    strcmp(argv[1], "-t") == 0)) {

            printf("%s[PLACEHOLDER]%s", RED, RES_COL);

        } else {

            UndefCommandPrint();

        } 

    } else {

        UndefCommandPrint();

    }

    return 0;
}