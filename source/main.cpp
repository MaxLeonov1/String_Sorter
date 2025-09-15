#include <stdio.h>
#include <string.h>

#include "supporting_functions.h"
#include "square_matrix.h"
#include "pointer_matrix.h"

/*-----------------------------------------------------------------------------------------------*/
//ВСЁ ДЛЯ СОХРАНЕНИЕ ЧЕРЕЗ МАТРИЦУ
/*-----------------------------------------------------------------------------------------------*/
//Константы для квадратной матрицы
const int num_strof   = 380;
const int max_len_str = 60;
const int num_str     = 14;
/*-----------------------------------------------------------------------------------------------*/

int main ( const int argc, const char* argv[]) {

    if (argc >= 2) {

        if ((strcmp(argv[1], "--version1") == 0 ||
             strcmp(argv[1], "-v1") == 0)) {///* Версия с квадратной матрицей

            FILE* onegin = fopen ("onegin_xxs.txt", "r");
            char* strof_arr = ScanOneginSquare(onegin);
            printf("%s", strof_arr[1]);

        } else if ((strcmp(argv[1], "--version2") == 0 ||
                    strcmp(argv[1], "-v2") == 0)) {///* Версия с матрицей указателей

            FILE* onegin = fopen ("onegin_xxs.txt", "r");
            char** strof_arr = ScanOneginPointer(onegin);
            printf("%s", strof_arr[0]); //null in [0]???

        } else {

            UndefCommandPrint();

        } 

    } else {

        UndefCommandPrint();

    }

    return 0;
}