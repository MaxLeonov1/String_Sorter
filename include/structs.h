#ifndef __STRUCTS__
#define __STRUCTS__

/*-------------------------------------------------------*/

typedef struct {

    char* str_pointer = nullptr;
    int   str_len     = 0;

} StrInfo;

/*-------------------------------------------------------*/

typedef struct {

    long aprox_symbol_num = 0;
    long num_str = 0;

    char* standart_buffer = nullptr;

    StrInfo* sorted_left  = nullptr;
    StrInfo* sorted_right = nullptr;
    StrInfo* str_info     = nullptr;

} Text;

/*-------------------------------------------------------*/

//typedef int (*Comparator) ( const void* str_struct_1, const void* str_struct_2); //TODO: ask about this

/*-------------------------------------------------------*/


#endif