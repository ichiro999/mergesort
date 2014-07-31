#ifndef __SORT_FUNC_H__
#define __SORT_FUNC_H__

#include <stdint.h>
#include <assert.h>

/* This module gives a macro definition of the body of
 * a standard sort function for an array of elements of any
 * type. The comparison function is given as a parameter to
 * the macro. The sort algorithm is mergesort which has logarithmic
 * worst case.
 * */


/***********************************************************************
 * This macro expands to the body of a standard sort function.
 * The sort function uses mergesort and must be defined separately
 * for each type of array.
 * Also the comparison function has to be defined individually
 * for each array cell type. SORT_FUN is the sort function name.
 * The function takes the array to be sorted (ARR),
 * the array of auxiliary space (AUX_ARR) of same size,
 * and the low (LOW), inclusive, and high (HIGH), noninclusive,
 * limits for the sort interval as arguments.
 * CMP_FUN is the comparison function name. It takes as arguments
 * two elements from the array and returns 1, if the first is bigger,
 * 0 if equal, and -1 if the second bigger. */

#define UT_SORT_FUNCTION_BODY(SORT_FUN, ARR, AUX_ARR, LOW, HIGH, CMP_FUN) {\
    uint32_t ut_sort_mid; \
    uint32_t ut_sort_i; \
    uint32_t ut_sort_low; \
    uint32_t ut_sort_high; \
\
    assert((LOW) < (HIGH)); \
    assert(ARR); \
    assert(AUX_ARR); \
\
    if ((LOW) == (HIGH) - 1) {\
        return; \
    } else if ((LOW) == (HIGH) -2) {\
        if (CMP_FUN((ARR)[LOW], (ARR)[(HIGH) - 1]) > 0) {\
            (AUX_ARR)[LOW] = (ARR)[LOW];\
            (ARR)[LOW] = (ARR)[(HIGH) - 1];\
            (ARR)[(HIGH) - 1] = (AUX_ARR)[LOW];\
        }\
        return;\
    }\
\
    ut_sort_mid = ((LOW) + (HIGH)) / 2;\
\
    SORT_FUN((ARR), (AUX_ARR), (LOW), ut_sort_mid);\
    SORT_FUN((ARR), (AUX_ARR), ut_sort_mid, (HIGH));\
\
    ut_sort_low = (LOW);\
    ut_sort_high = ut_sort_mid;\
\
    for (ut_sort_i = (LOW); ut_sort_i < (HIGH); ut_sort_i++) {\
\
        if (ut_sort_low >= ut_sort_mid) {\
            (AUX_ARR)[ut_sort_i] = (ARR)[ut_sort_high];\
            ut_sort_high++;\
        } else if (ut_sort_high >= (HIGH)) {\
            (AUX_ARR)[ut_sort_i] = (ARR)[ut_sort_low];\
            ut_sort_low++;\
        } else if (CMP_FUN((ARR)[ut_sort_low], \
                (ARR)[ut_sort_high]) > 0) {\
            (AUX_ARR)[ut_sort_i] = (ARR)[ut_sort_high];\
            ut_sort_high++;\
        } else {\
            (AUX_ARR)[ut_sort_i] = (ARR)[ut_sort_low];\
            ut_sort_low++;\
        }\
    }\
\
    for (ut_sort_i = (LOW); ut_sort_i < (HIGH); ut_sort_i++) {\
        (ARR)[ut_sort_i] = (AUX_ARR)[ut_sort_i];\
    }\
}\

#endif //__SORT_FUNC_H__
