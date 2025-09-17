#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "input_output_text.h"
#include "structs.h"
#include "supporting_functions.h"
#include "sort_functions.h"

/*-----------------------------------------------------------------------------------------------*/

StrInfo* ScanOnegin ( FILE* onegin_file, char** text_buffer_point) {

    long int   file_char_len  = FileCharCount (onegin_file);
         int   num_str        = 1;
         char* str_terminator = nullptr;
         char* str_pointer    = nullptr;
         char* text_buffer    = nullptr;
    
    *text_buffer_point = (char*) calloc ( file_char_len, sizeof(char)); // \note reduce size by realloc and fread value? 
    text_buffer = *text_buffer_point;

    fread( text_buffer, sizeof(char), file_char_len, onegin_file);

    str_pointer = text_buffer;

    while (1) {

        str_terminator = strchr(str_pointer, '\n');

        if ( str_terminator == nullptr) break;
 
        text_buffer[str_terminator - text_buffer] = 0;

        str_pointer = (char*)(str_terminator + 1);

        num_str++;

    }

    // printf("%s\n", text_buffer);

    str_pointer = text_buffer;

    StrInfo* str_struct_arr = (StrInfo*) calloc ( num_str + 1, sizeof(StrInfo));

    // printf("%d\n", num_str);

    for (int str_ind = 0; str_ind < num_str; str_ind++) {
        
        str_terminator = strchr(str_pointer, '\0');

        str_struct_arr[str_ind].str_pointer = str_pointer;
        str_struct_arr[str_ind].str_len = (str_terminator + 1) - str_pointer;

        // printf("%p %p\n", str_terminator, str_pointer);
        // printf("%d\n", str_terminator - str_pointer + 1);

        str_pointer = str_terminator + 1;

    }

    // printf("%p %p\n", text_buffer, *text_buffer_point);
    return str_struct_arr;

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

void OutputOnegin ( StrInfo* str_struct_arr) {

    FILE* output_onegin = fopen ( "output.txt", "w");

    int (*Comparator) ( const void* str_struct_1,
                        const void* str_struct_2);

    fprintf( output_onegin, "\n\n[SORTED FROM THE BEGINING]\n\n\n");

    Comparator = LetfToRightStrCompare;
    str_struct_arr = StructSorting ( str_struct_arr, Comparator);
    PrintOnegin ( str_struct_arr, output_onegin);

    fprintf( output_onegin, "\n\n[SORTED FROM THE END]\n\n\n");

    Comparator = RightToLeftStrCompare;
    str_struct_arr = StructSorting ( str_struct_arr, Comparator);
    PrintOnegin ( str_struct_arr, output_onegin);

    fprintf( output_onegin, "\n\n[ORIGINAL TEXT]\n\n\n");

    Comparator = FenixSort;
    str_struct_arr = StructSorting ( str_struct_arr, Comparator);
    PrintOnegin ( str_struct_arr, output_onegin);

}