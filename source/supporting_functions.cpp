#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "supporting_functions.h"
#include "print_sys_message.h"
#include "colors.h"
#include "structs.h"

/*-----------------------------------------------------------------------------------------------*/

long int FileCharCount ( FILE* stream) {

    assert ( stream != nullptr);

    fseek ( stream, 0, SEEK_END);
    long int file_char_len = ftell (stream); //slightly bigger because of f*cking \r
    fseek ( stream, 0, SEEK_SET);

    return file_char_len;

}

/*-----------------------------------------------------------------------------------------------*/

void StrInfoCopy ( Text* all_text) {

    assert ( all_text != nullptr);

    int struct_ind = 0;

    while ( struct_ind < all_text->num_str) {

        all_text->sorted_left[struct_ind].str_pointer = all_text->str_info[struct_ind].str_pointer;
        all_text->sorted_right[struct_ind].str_pointer = all_text->str_info[struct_ind].str_pointer;

        all_text->sorted_left[struct_ind].str_len = all_text->str_info[struct_ind].str_len;
        all_text->sorted_right[struct_ind].str_len = all_text->str_info[struct_ind].str_len;

        struct_ind++;

    }

}

/*-----------------------------------------------------------------------------------------------*/

void FreeText ( Text* all_text) {

    assert ( all_text != nullptr);

    free ( all_text->str_info);
    free ( all_text->sorted_left);
    free ( all_text->sorted_right);
    free ( all_text->standart_buffer);

}

/*-----------------------------------------------------------------------------------------------*/

void* CallocWithCheck ( size_t num_elements, size_t size_element) {

    void* alloc_mem_pointer = calloc ( num_elements, size_element);

    if ( alloc_mem_pointer == nullptr) {

        MemAloccErrorPrint(); 
        exit(0);

    }

}

/*-----------------------------------------------------------------------------------------------*/

FILE* FopenWithCheck ( const char* file_name, const char* mode) {

    assert ( (file_name != nullptr) && (mode != nullptr));

    FILE* file_pointer = fopen ( file_name, mode);

    if ( file_pointer == nullptr) {

        FileOpenErrorPrint();
        exit(0);

    }

}

/*-----------------------------------------------------------------------------------------------*/