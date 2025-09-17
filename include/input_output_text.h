#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

/*-------------------------------------------------------*/
#include "structs.h"
/*-------------------------------------------------------*/
StrInfo* ScanOnegin   ( FILE* onegin_file, char** text_buffer);
void     OutputOnegin ( StrInfo* str_struct_arr);
void     PrintOnegin  ( StrInfo* str_struct_arr, FILE* output_onegin);
/*-------------------------------------------------------*/

#endif