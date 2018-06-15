//
// Created by Rechad Catelemmon on 2017/5/2.
//

#include <algorithm>
#include "InsertionSort.h"
#ifndef QUICKSORT_FIRSTQUICKSORT_H
#define QUICKSORT_FIRSTQUICKSORT_H


using std::swap;

template<typename T>
int __FirstPartition1(T array[], int start, int end){
    T first = array[start];
    int j=start;
    for(int i=start+1;i<=end;i++){
        if(array[i]<first){
            swap(array[++j],array[i]);
        }
    }
    swap(array[j], array[start]);
    return j;
}

template <typename T>
void __QuickSort1(T array[],int start, int end){
    //if (start-end>=15) {
    //    SectionInsertionSort(array,start,end);
     //   return;
    //}
    if(start>end){
        return;
    }
    int p=__FirstPartition1(array,start,end);
//    Travel(array,10);
    __QuickSort1(array,start,p-1);
    __QuickSort1(array, p+1, end);
}

template <typename T>
void QuickSort1(T array[],int len){
    __QuickSort1(array, 0, len - 1);
}

#endif //QUICKSORT_FIRSTQUICKSORT_H
