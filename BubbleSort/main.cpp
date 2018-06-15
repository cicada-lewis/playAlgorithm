#include <iostream>
#include "BubbleSort.h"
#include "SortCommon.h"
using namespace sort_common;
using std::copy;
#define ARRAY_LEN 10
int main() {

    int *array = new int[ARRAY_LEN];
    GenerateRandomIntArray(array, ARRAY_LEN, 0, 100);
    Travel(array, ARRAY_LEN);
//    BubbleSort(array, ARRAY_LEN);
    OptimizedBubbleSort(array, ARRAY_LEN);
    Travel(array, ARRAY_LEN);

    delete array;
    int jlen=50000;
    array = new int[jlen];
//    GenerateNearlyOrderedIntArray(array, 10000, 100);
    GenerateRandomIntArray(array, jlen, 0, jlen);
    int *array_cp=new int[jlen];
    copy(array, array + jlen, array_cp);
    JudgeSort("BubbleSort", BubbleSort, array, jlen);
    JudgeSort("OptimizedBubbleSort", OptimizedBubbleSort, array_cp, jlen);

    delete array_cp;
    delete array;

    return 0;
}