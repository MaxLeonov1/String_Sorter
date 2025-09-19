#ifndef __ENUMS__
#define __ENUMS__

/*-------------------------------------------------------*/
typedef enum {

    QUICK_SORT = 0,
    SLOW_BUBLE_SORT = 1

} SortingType;
/*-------------------------------------------------------*/
typedef enum {

    FILE_OPEN_ERROR = 0,
    MEMORY_ALLOCATE_ERROR = 1,
    SUCCSESFUL = 2

} ErrorCode;
/*-------------------------------------------------------*/
typedef enum {

    SCAN_PROCESS = 10,
    SORTING_PROCESS = 20,
    OUTPUT_PROCESS = 30

} ProcessName;
/*-------------------------------------------------------*/

#endif