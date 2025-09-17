#include <stdio.h>
#include <string.h>

#include "supporting_functions.h"
#include "colors.h"
#include "structs.h"
#include "enum.h"

/*-----------------------------------------------------------------------------------------------*/

void UndefCommandPrint (void) {

    printf("%s----------------\n"
             "Undefined comand\n"
             "----------------%s\n",
             RED, RES_COL);

}

/*-----------------------------------------------------------------------------------------------*/

void FileBufferClean (FILE* stream) {

    int symbol = 0;

    while (1) {

        symbol = getc(stream);

        if ( symbol == '\n' || symbol == -1) break; 

    }

}

/*-----------------------------------------------------------------------------------------------*/

long int FileCharCount ( FILE* stream) {

    fseek ( stream, 0, SEEK_END);
    long int file_char_len = ftell (stream); //slightly bigger because of f*cking \r
    fseek ( stream, 0, SEEK_SET);

    return file_char_len;

}

/*-----------------------------------------------------------------------------------------------*/

void StrInfoCopy ( Text* all_text, int copy_type) {

    int struct_ind = 0;

    while ( all_text->str_info[struct_ind].str_pointer != nullptr) {

        switch (copy_type) {

            case LEFT_SORT:
                all_text->sorted_left[struct_ind].str_pointer = all_text->str_info[struct_ind].str_pointer;
                

            case RIGHT_SORT:
                all_text->sorted_left[struct_ind].str_pointer = all_text->str_info[struct_ind].str_pointer;

        }

        struct_ind++;

    }

}