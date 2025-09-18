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

    assert ( (file_name != nullptr) && (all_text != nullptr));

    FILE*      onegin_file     = FopenWithCheck ( file_name, "r");
    all_text->aprox_symbol_num = FileCharCount ( onegin_file);
    int   num_str         = 1;
    char* str_terminator  = nullptr;
    char* str_pointer     = nullptr;
    char* text_buffer     = nullptr;
    
    all_text->standart_buffer = (char*) CallocWithCheck ( all_text->aprox_symbol_num, sizeof(char)); //TODO: calloc cover with testing

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

    all_text->num_str = num_str;
    str_pointer = all_text->standart_buffer;

    all_text->str_info = (StrInfo*) CallocWithCheck ( num_str + 1, sizeof(StrInfo));

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

void PrintOnegin ( StrInfo* struct_arr, FILE* output_onegin, long int num_str) {

    assert ( (struct_arr != nullptr) && (output_onegin != nullptr));

    for ( int struct_ind = 0;
          struct_ind < num_str;
          struct_ind++ ) {

        //printf ( "%s\n", struct_arr[struct_ind].str_pointer);
        fprintf( output_onegin, "%s\n", struct_arr[struct_ind].str_pointer);

    }

}

/*-----------------------------------------------------------------------------------------------*/

void OutputOnegin ( Text* all_text) {

    assert ( all_text != nullptr);

    FILE* output_onegin = FopenWithCheck ( "data/output.txt", "w");

    fprintf ( output_onegin, "\n\n[SORTED FROM THE BEGINING]\n\n\n");
    PrintOnegin ( all_text->sorted_left, output_onegin, all_text->num_str);

    fprintf ( output_onegin, "\n\n[SORTED FROM THE END]\n\n\n");
    PrintOnegin ( all_text->sorted_right, output_onegin, all_text->num_str);

    fprintf ( output_onegin, "\n\n[ORIGINAL TEXT]\n\n\n");
    PrintOnegin ( all_text->str_info, output_onegin, all_text->num_str);

}