#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sort_functions.h"
#include "supporting_functions.h"
#include "enum.h"
#include "structs.h"

/*-----------------------------------------------------------------------------------------------*/

void AllSort ( Text* all_text) {

    int (*Comparator) ( const void* str_struct_1,
                        const void* str_struct_2);

    Comparator = LetfToRightStrCompare;
    all_text->sorted_left = (StrInfo*) calloc ( all_text->num_str, sizeof(StrInfo));
    StrInfoCopy ( all_text, LEFT_SORT);
    qsort ( all_text->sorted_left, all_text->num_str, sizeof(StrInfo), Comparator);


    printf("%p\n", all_text->sorted_left);

    Comparator = RightToLeftStrCompare;
    all_text->sorted_right = (StrInfo*) calloc ( all_text->num_str, sizeof(StrInfo));
    StrInfoCopy ( all_text, RIGHT_SORT);
    qsort ( all_text->sorted_right, all_text->num_str, sizeof(StrInfo), Comparator);

    printf("%p\n", all_text->sorted_right);

}

/*-----------------------------------------------------------------------------------------------*/

StrInfo* StructSorting ( StrInfo* str_struct_arr, int (*Comparator) ( const void* str_struct_1, const void* str_struct_2)) {

    int struct_num = 0;

    for ( int struct_ind = 0;
          str_struct_arr[struct_ind].str_pointer != nullptr;
          struct_ind++ ) struct_num++;

    // printf("%d", Comparator(&str_struct_arr[0], &str_struct_arr[1]));

    qsort ( str_struct_arr, struct_num, sizeof(StrInfo), Comparator);

    return str_struct_arr;

}

/*-----------------------------------------------------------------------------------------------*/

int LetfToRightStrCompare ( const void* arg_1, // TODO: assert
                            const void* arg_2) {

    const StrInfo* struct_pointer_1 = (const StrInfo*)arg_1;
    const StrInfo* struct_pointer_2 = (const StrInfo*)arg_2;

    char* str_1 = struct_pointer_1->str_pointer;
    char* str_2 = struct_pointer_2->str_pointer;

    while ( *str_1 || *str_2) {

        while ( *str_1 && !isalpha(*str_1)) str_1++;
        while ( *str_2 && !isalpha(*str_2)) str_2++;

        if ( tolower(*str_1) != tolower(*str_2))
            return tolower(*str_1) - tolower(*str_2);

        if ( !(*str_1 || *str_2)) 
            return 0;

        str_1++;
        str_2++;

    }

}

/*-----------------------------------------------------------------------------------------------*/

int FenixSort ( const void* arg_1,
                const void* arg_2) {

    const StrInfo* struct_pointer_1 = (const StrInfo*)arg_1;
    const StrInfo* struct_pointer_2 = (const StrInfo*)arg_2;

    char* str_1 = struct_pointer_1->str_pointer;
    char* str_2 = struct_pointer_2->str_pointer;

    return (int)(str_1 - str_2);

}

/*-----------------------------------------------------------------------------------------------*/

int RightToLeftStrCompare ( const void* arg_1,
                            const void* arg_2) {

    const StrInfo* struct_pointer_1 = (const StrInfo*)arg_1;
    const StrInfo* struct_pointer_2 = (const StrInfo*)arg_2;

    char* str_end_1 = (struct_pointer_1->str_pointer + struct_pointer_1->str_len - 2);
    char* str_end_2 = (struct_pointer_2->str_pointer + struct_pointer_2->str_len - 2);

    while ( *str_end_1 || *str_end_2) {

        while ( *str_end_1 && !isalpha(*str_end_1)) str_end_1--;
        while ( *str_end_2 && !isalpha(*str_end_2)) str_end_2--;

        if ( tolower(*str_end_1) != tolower(*str_end_2))
            return tolower(*str_end_1) - tolower(*str_end_2);

        if ( !(*str_end_1 || *str_end_2)) 
            return 0;

        str_end_1--;
        str_end_2--;

    }

}