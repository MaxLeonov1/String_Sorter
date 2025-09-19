#ifndef __SUPP_FUNC__
#define __SUPP_FUNC__

/*-------------------------------------------------------*/
#include "structs.h"
/*-------------------------------------------------------*/
void     StrInfoCopy       ( Text* all_text);
void     FreeText          ( Text* all_text);
void     UndefCommandPrint ( void);
long int FileCharCount     ( FILE* stream);
//void*    CallocWithCheck   ( size_t num_elements, size_t size_element);
/*-------------------------------------------------------*/

#endif 