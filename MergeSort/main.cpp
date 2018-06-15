#include <iostream>
#include <algorithm>
#include "MergeSort.h"
#include "SortCommon.h"

//#define ARRAY_LEN 10
#define ARRAY_LEN 50000000
using std::copy;
using std::sort;
using namespace sort_common;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {

    int *array = new int[ARRAY_LEN];
    GenerateRandomIntArray(array, ARRAY_LEN, 0, ARRAY_LEN);
//        GenerateNearlyOrderedIntArray(array, ARRAY_LEN, 100);
    int *array_cp = new int[ARRAY_LEN];
    int *array_cp2 = new int[ARRAY_LEN];
    int *array_cp3 = new int[ARRAY_LEN];
    int *array_cp4 = new int[ARRAY_LEN];
    int *array_cp5 = new int[ARRAY_LEN];
    copy(array, array + ARRAY_LEN, array_cp);
    copy(array, array + ARRAY_LEN, array_cp2);
    copy(array, array + ARRAY_LEN, array_cp3);
    copy(array, array + ARRAY_LEN, array_cp4);
    copy(array, array + ARRAY_LEN, array_cp5);

//        Travel(array, ARRAY_LEN);
//        MergeSort(array, ARRAY_LEN);
//        Travel(array, ARRAY_LEN);
    JudgeSort("MergeSort1", MergeSort, array, ARRAY_LEN);
    JudgeSort("OptimizedMergeSort", OptimizedMergeSort, array_cp, ARRAY_LEN);
    clock_t startTime = clock();
    std::sort(array_cp2, array_cp2 + ARRAY_LEN);
    clock_t endTime = clock();
    assert(isSorted(array, ARRAY_LEN));
    cout << "std::sort " << " : " << (double) (endTime - startTime) / CLOCKS_PER_SEC << " s " << endl;
//    JudgeSort("OptimizedInsertionSort",OptimizedInsertionSort,array_cp5,ARRAY_LEN);
    JudgeSort("OptimizedMergeSortFromBottomToTop", OptimizedMergeSortFromBottomToTop, array_cp3, ARRAY_LEN);
    JudgeSort("MergeSortFromBottomToTop", MergeSortFromBottomToTop, array_cp4, ARRAY_LEN);
    delete array_cp, array_cp2, array_cp3, array_cp4,array_cp5;
    delete array;

    return 0;
}