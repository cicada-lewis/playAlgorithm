#include <iostream>
#include "SortCommon.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "algorithm"
#define ARRAY_LEN 10
using std::cout;
using std::endl;
using namespace sort_common;
using namespace selection_sort;
using std::copy;
int main(int argc,char *argv[]){

    int *array = new int[ARRAY_LEN];
    GenerateRandomIntArray(array,ARRAY_LEN,0,100);
    Travel(array, ARRAY_LEN);
    ShellSort(array, ARRAY_LEN);
//    Travel(array, ARRAY_LEN);
    delete array;

    array = new int[10000];
    int *array_cp1 = new int[10000];
    int *array_cp2 = new int[10000];
//    GenerateRandomIntArray(array,10000,0,10000);
    GenerateNearlyOrderedIntArray(array, 10000, 100);
    copy(array, array + 10000, array_cp1);
    copy(array, array + 10000, array_cp2);
    JudgeSort("OptimizedInsertionSort", OptimizedInsertionSort,array,10000);
    JudgeSort("SelectionSort", SelectionSort, array_cp1, 10000);
    JudgeSort("ShellSort", ShellSort, array_cp2, 10000);

    return 0;
}