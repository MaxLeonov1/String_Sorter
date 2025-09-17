#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

/*-------------------------------------------------------*/
#include "structs.h"
/*-------------------------------------------------------*/
StrInfo* ScanOnegin   ( const char* file_name, Text* all_text);
void     OutputOnegin ( Text* all_text);
void     PrintOnegin  ( StrInfo* str_struct_arr, FILE* output_onegin);
/*-------------------------------------------------------*/

#endif