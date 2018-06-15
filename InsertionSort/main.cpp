#include <iostream>
#include "SortCommon.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
using namespace std;
#define ARRAY_LEN 10000
int main() {
    int *array=new int[ARRAY_LEN];
    int *array_cp1 = new int[ARRAY_LEN];
    int *array_cp2 = new int[ARRAY_LEN];
//    sort_common::GenerateRandomIntArray(array, ARRAY_LEN, 0, 10000);
    sort_common::GenerateNearlyOrderedIntArray(array, ARRAY_LEN, 100);
    copy(array, array + ARRAY_LEN, array_cp1);
    copy(array, array + ARRAY_LEN, array_cp2);
    sort_common::JudgeSort("InsertionSort",InsertionSort,array,ARRAY_LEN);
    sort_common::JudgeSort("OptimizedInsertionSort",OptimizedInsertionSort,array_cp2,ARRAY_LEN);
    sort_common::JudgeSort("SelectionSort", selection_sort::SelectionSort, array_cp1, ARRAY_LEN);

    delete array;
    delete array_cp1;
    delete array_cp2;
//    array=new int[10];
//    sort_common::GenerateRandomIntArray(array, 10, 0, 100);
//    sort_common::Travel(array,10);
//    OptimizedInsertionSort(array,10);
//    sort_common::Travel(array, 10);
//    delete array;
    return 0;
}