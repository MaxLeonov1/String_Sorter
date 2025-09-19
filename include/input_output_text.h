#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

/*-------------------------------------------------------*/
#include "structs.h"
#include "enum.h"
/*-------------------------------------------------------*/
ErrorCode ScanOnegin   ( const char* file_name, Text* all_text);
ErrorCode OutputOnegin ( Text* all_text);
void     PrintOnegin  ( StrInfo* str_struct_arr, FILE* output_onegin, long int num_str);
/*-------------------------------------------------------*/

#endif