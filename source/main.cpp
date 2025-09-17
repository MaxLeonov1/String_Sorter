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

    char* text_buffer = nullptr;

    if (argc >= 2) {

        if ((strcmp(argv[1], "--sort") == 0 ||
             strcmp(argv[1], "-s") == 0)) {

            FILE* onegin_file = fopen ( "textonegin.txt", "r");
            StrInfo* str_pointer_arr = ScanOnegin ( onegin_file, &text_buffer);
            fclose (onegin_file);

            OutputOnegin ( str_pointer_arr);

            free ( str_pointer_arr);
            free ( text_buffer);
            //printf("%d\n", str_pointer_arr[14].str_pointer);
            //printf("%s", text_buffer);

            //printf("%d", StrStructCompare(&str_pointer_arr[0], &str_pointer_arr[1]));

            // int (*Comparator) ( const void* str_struct_1,
            //                     const void* str_struct_2);

            // //Comparator = LetfToRightStrCompare;
            // Comparator = RightToLeftStrCompare;
            // str_pointer_arr = StructSorting ( str_pointer_arr, Comparator);

            // printf ("%s\n%s\n%s\n\n", str_pointer_arr[0].str_pointer,
            //                           str_pointer_arr[1].str_pointer,
            //                           str_pointer_arr[2].str_pointer);


            // Comparator = FenixSort;
            // str_pointer_arr = StructSorting ( str_pointer_arr, Comparator);

            // printf ("%s\n%s\n%s\n", str_pointer_arr[0].str_pointer,
            //                           str_pointer_arr[1].str_pointer,
            //                           str_pointer_arr[2].str_pointer);

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