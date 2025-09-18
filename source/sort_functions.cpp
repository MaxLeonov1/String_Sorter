#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "sort_functions.h"
#include "supporting_functions.h"
#include "structs.h"

/*-----------------------------------------------------------------------------------------------*/

void AllSort ( Text* all_text) {

    assert ( all_text != nullptr);

    int (*Comparator) ( const void* str_struct_1,
                        const void* str_struct_2);

    all_text->sorted_left =  (StrInfo*) CallocWithCheck ( all_text->num_str, sizeof(StrInfo));
    all_text->sorted_right = (StrInfo*) CallocWithCheck ( all_text->num_str, sizeof(StrInfo));

    StrInfoCopy( all_text);

    Comparator = LetfToRightStrCompare;
    qsort ( all_text->sorted_left, all_text->num_str, sizeof(StrInfo), Comparator);

    Comparator = RightToLeftStrCompare;
    HandmadeBubleSort ( all_text->sorted_right, all_text->num_str, sizeof(StrInfo), Comparator);

}

/*-----------------------------------------------------------------------------------------------*/

void Swap ( void* element_1, void* element_2, size_t size) {

    assert ( (element_1 != nullptr) && (element_2 != nullptr));

    void* mini_buffer = CallocWithCheck ( 1, size);

    memcpy ( mini_buffer, element_1, size);
    memcpy ( element_1, element_2, size);
    memcpy ( element_2, mini_buffer, size);

    free ( mini_buffer);

}

/*-----------------------------------------------------------------------------------------------*/

void HandmadeBubleSort ( void *base,
                         size_t num,
                         size_t size,
                         int (*Comparator) (const void *, const void *)) {

    assert ( (base != nullptr) && (Comparator != nullptr));

    for ( size_t ind_1 = 0; ind_1 < num - 1; ind_1++) {

        for ( size_t ind_2 = 0; ind_2 < ( num - 1) - ind_1; ind_2++) {

            void* element_1 = base + ind_2 * size;
            void* element_2 = base + (ind_2 + 1) * size;

            if ( Comparator( element_1, element_2) > 0) {

                Swap ( element_1, element_2, size);

            }

        }

    }

}

/*-----------------------------------------------------------------------------------------------*/

int LetfToRightStrCompare ( const void* arg_1,
                            const void* arg_2) {

    assert ( (arg_1 != nullptr) && (arg_2 != nullptr));

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

    assert ( (arg_1 != nullptr) && (arg_2 != nullptr));

    const StrInfo* struct_pointer_1 = (const StrInfo*)arg_1;
    const StrInfo* struct_pointer_2 = (const StrInfo*)arg_2;

    char* str_1 = struct_pointer_1->str_pointer;
    char* str_2 = struct_pointer_2->str_pointer;

    return (int)(str_1 - str_2);

}

/*-----------------------------------------------------------------------------------------------*/

int RightToLeftStrCompare ( const void* arg_1,
                            const void* arg_2) {

    assert ( (arg_1 != nullptr) && (arg_2 != nullptr));

    const StrInfo* struct_pointer_1 = (const StrInfo*)arg_1;
    const StrInfo* struct_pointer_2 = (const StrInfo*)arg_2;

    // printf("%s\n", struct_pointer_1->str_pointer);
    // printf("%s\n", struct_pointer_2->str_pointer);

    // printf("%d\n", struct_pointer_1->str_len);
    // printf("%d\n", struct_pointer_2->str_len);

    char* str_end_1 = (struct_pointer_1->str_pointer + struct_pointer_1->str_len - 2);
    char* str_end_2 = (struct_pointer_2->str_pointer + struct_pointer_2->str_len - 2);

    // printf("%c\n", *str_end_1);
    // printf("%c\n", *str_end_2);

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