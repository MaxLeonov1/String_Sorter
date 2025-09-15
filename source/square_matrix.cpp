#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "square_matrix.h"
#include "supporting_functions.h"



const int num_strof   = 380;
const int max_len_str = 60;
const int num_str     = 14;



char* ScanOneginSquare ( FILE* onegin_file) {

    char  str_arr[num_strof*num_str][max_len_str] = {0};
    char* break_str = nullptr;
    int   str_index = 0;

    while (1) {

        break_str = fgets ( str_arr[str_index], max_len_str, onegin_file );

        //printf("%s", break_str);

        if ( break_str == nullptr ) return (char*)str_arr;

        str_index++;
        printf("%s\n", str_arr[str_index]);

    }

}

char* SortOneginSquare ( char* strof_arr ) {

    for ( int str_index = 0; str_index < (num_str - 1); str_index++) {



    }

}