#ifndef __SORT__FUNC__
#define __SORT__FUNC__

/*-----------------------------------------------------------------------------------------------*/
#include "structs.h"
/*-----------------------------------------------------------------------------------------------*/

void AllSort ( Text* all_text);

void Swap ( void* element_1, void* element_2, size_t size);

int LetfToRightStrCompare ( const void* arg_1, const void* arg_2);

int FenixSort ( const void* arg_1, const void* arg_2);

int RightToLeftStrCompare ( const void* arg_1, const void* arg_2);

void HandmadeBubleSort ( void *base, size_t num, size_t size, int (*Comparator) (const void *, const void *));

/*-----------------------------------------------------------------------------------------------*/

#endif