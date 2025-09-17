#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input_output_text.h"
#include "structs.h"
#include "supporting_functions.h"
#include "sort_functions.h"

/*-----------------------------------------------------------------------------------------------*/

StrInfo* ScanOnegin ( const char* file_name, Text* all_text) {

    FILE*      onegin_file     = fopen ( file_name, "r");
    all_text->aprox_symbol_num = FileCharCount (onegin_file);
    int   num_str         = 1;
    char* str_terminator  = nullptr;
    char* str_pointer     = nullptr;
    char* text_buffer     = nullptr;
    
    all_text->standart_buffer = (char*) calloc ( all_text->aprox_symbol_num, sizeof(char)); //TODO: calloc cover with testing

    fread( all_text->standart_buffer, sizeof(char), all_text->aprox_symbol_num, onegin_file);
    fclose( onegin_file);

    str_pointer = all_text->standart_buffer;

    while (1) {

        str_terminator = strchr(str_pointer, '\n');

        if ( str_terminator == nullptr) break;
 
        all_text->standart_buffer [ str_terminator - all_text->standart_buffer ] = 0;

        str_pointer = (char*)(str_terminator + 1);

        num_str++;

    }

    // printf("%s\n", text_buffer);

    str_pointer = all_text->standart_buffer;

    all_text->str_info = (StrInfo*) calloc ( num_str + 1, sizeof(StrInfo));

    // printf("%d\n", num_str);

    for (int str_ind = 0; str_ind < num_str; str_ind++) {
        
        str_terminator = strchr(str_pointer, '\0');

        all_text->str_info[str_ind].str_pointer = str_pointer;
        all_text->str_info[str_ind].str_len = (str_terminator + 1) - str_pointer;

        // printf("%p %p\n", str_terminator, str_pointer);
        // printf("%d\n", str_terminator - str_pointer + 1);

        str_pointer = str_terminator + 1;

    }

    // printf("%p %p\n", text_buffer, *text_buffer_point);
    return all_text->str_info;

}

/*-----------------------------------------------------------------------------------------------*/

void PrintOnegin ( StrInfo* str_struct_arr, FILE* output_onegin) {

    for ( int struct_ind = 0;
          str_struct_arr[struct_ind].str_pointer != nullptr;
          struct_ind++ ) {

        fprintf( output_onegin, "%s\n", str_struct_arr[struct_ind].str_pointer);

    }

}

/*-----------------------------------------------------------------------------------------------*/

void OutputOnegin ( Text* all_text) {

    FILE* output_onegin = fopen ( "data/output.txt", "w");

    int (*Comparator) ( const void* str_struct_1,
                        const void* str_struct_2);

    fprintf( output_onegin, "\n\n[SORTED FROM THE BEGINING]\n\n\n");
    PrintOnegin ( all_text->sorted_left, output_onegin);
    printf ("%s", all_text->sorted_left->str_pointer);

    fprintf( output_onegin, "\n\n[SORTED FROM THE END]\n\n\n");
    PrintOnegin ( all_text->sorted_right, output_onegin);
    printf ("%s", all_text->sorted_left->str_pointer);

    fprintf( output_onegin, "\n\n[ORIGINAL TEXT]\n\n\n");
    PrintOnegin ( all_text->str_info, output_onegin);

}