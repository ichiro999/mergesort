#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_func.h"

int cmp_int(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

void sort_int_array(int *arr, int *aux_arr, uint32_t low, uint32_t high) {
    UT_SORT_FUNCTION_BODY(sort_int_array, arr, aux_arr, low, high, cmp_int);
}


int main() {
    int arr[10];
    int aux_arr[10];
    srand(time(NULL));
    printf("++++++++++++++++before sort++++++++++++++++++\n");
    for(int i = 0; i < 10; i++) {
        arr[i] = rand();
        printf("%d ", arr[i]);
        aux_arr[i] = 0;
    }
    printf("\n");

    sort_int_array(arr, aux_arr, 0, 10);

    printf("++++++++++++++++after sort++++++++++++++++++\n");
    
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
