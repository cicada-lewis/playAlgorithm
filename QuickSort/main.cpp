#include <iostream>
#include "SortCommon.h"
#include "FirstQuickSort2.h"
#include "TwoWayQuickSort.h"
#include "ThreeWayQuickSort.h"
#include "FirstQuickSort.h"
#include "RandomQuickSort.h"
#include <algorithm>
using namespace sort_common;
#define ARRAY_LEN 10000000
using std::copy;

int main(int argc,char *argv[]){

    int *array1 = new int[ARRAY_LEN];
    int *array2 = new int[ARRAY_LEN];
    GenerateRandomIntArray(array1, ARRAY_LEN, 0, ARRAY_LEN);
//    cout<<"sort begin: ";
//    Travel(array1,ARRAY_LEN);
//    cout<<endl;
//    QuickSort1(array1,ARRAY_LEN);
//    cout<<endl;
//    cout<<"sort end: ";
//    Travel(array1,ARRAY_LEN);


//    GenerateNearlyOrderedIntArray(array1, ARRAY_LEN, 100);
    copy(array1, array1 + ARRAY_LEN, array2);
    JudgeSort("QuickSort1", QuickSort1,array1, ARRAY_LEN);
//    JudgeSort("QuickSort2", QuickSort2,array2, ARRAY_LEN);
//    JudgeSort("RandomQuickSort", RandomQuickSort, array1, ARRAY_LEN);
//    Travel(array1, ARRAY_LEN);
//    RandomQuickSort(array1, ARRAY_LEN);
//    ThreeWayQuickSort(array1, ARRAY_LEN);
//    SectionInsertionSort(array1, 0, ARRAY_LEN - 1);
//    Travel(array1, ARRAY_LEN);
//    JudgeSort("TwoWayQuickSort", TwoWayQuickSort, array1, ARRAY_LEN);
    delete[] array1;
    delete[] array2;
    return 0;
}