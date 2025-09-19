#ifndef __SORT__FUNC__
#define __SORT__FUNC__

/*-----------------------------------------------------------------------------------------------*/
#include "structs.h"
#include "enum.h"
/*-----------------------------------------------------------------------------------------------*/

ErrorCode AllSort ( Text* all_text, int sort_type);

ErrorCode Swap ( void* element_1, void* element_2, size_t size);

ErrorCode HandmadeBubleSort ( void *base, size_t num, size_t size, int (*Comparator) (const void *, const void *));

int LetfToRightStrCompare ( const void* arg_1, const void* arg_2);

int FenixSort ( const void* arg_1, const void* arg_2);

int RightToLeftStrCompare ( const void* arg_1, const void* arg_2);

/*-----------------------------------------------------------------------------------------------*/

#endif