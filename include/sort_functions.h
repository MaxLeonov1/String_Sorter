#ifndef __SORT__FUNC__
#define __SORT__FUNC__

/*-------------------------------------------------------*/
#include "structs.h"
/*-------------------------------------------------------*/

StrInfo* StructSorting ( StrInfo* str_struct_arr, 
                         int (*Comparator) ( const void* str_struct_1,
                                             const void* str_struct_2));

int LetfToRightStrCompare ( const void* arg_1,
                            const void* arg_2);

int FenixSort ( const void* arg_1,
                const void* arg_2);

int RightToLeftStrCompare ( const void* arg_1,
                            const void* arg_2);
/*-------------------------------------------------------*/

#endif