#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pointer_matrix.h"

/*-----------------------------------------------------------------------------------------------*/
const int num_strof   = 380;
const int num_str     = 14;
const int max_len_str = 60;
/*-----------------------------------------------------------------------------------------------*/

char** ScanOneginPointer ( FILE* onegin_file) {

    char* pointer_arr[num_strof*num_str] = {0};
    char  exchange_str[max_len_str]      = {0};
    char* break_str = nullptr;
    int   str_index = 0;
     
    while (1) {

        break_str = fgets ( exchange_str, max_len_str, onegin_file );

        if ( break_str == nullptr ) return pointer_arr;

        str_index++;
        pointer_arr[str_index] = strdup (exchange_str);

        printf("%s", pointer_arr[str_index]);

    }

}