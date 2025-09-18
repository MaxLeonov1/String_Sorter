#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "supporting_functions.h"
#include "print_sys_message.h"
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
             argc == 3) {

            all_text.str_info = ScanOnegin ( argv[2], &all_text);

            AllSort ( &all_text);

            OutputOnegin ( &all_text);

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