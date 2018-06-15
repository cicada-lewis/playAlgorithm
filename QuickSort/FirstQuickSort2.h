//
// Created by Rechad Catelemmon on 2017/4/28.
//

#include <algorithm>
#include "InsertionSort.h"
#ifndef QUICKSORT_SORT_H
#define QUICKSORT_SORT_H
#include "SortCommon.h"
using namespace sort_common;
using std::swap;




template<typename T>
int __FirstPartition2(T array[], int start, int end){
    T first = array[start];
    int j=start;
    for(int i=start+1;i<=end;i++){
        if(array[j+1]==first){
            j++;
            continue;
        }
        else if(array[i]<first){
            swap(array[++j],array[i]);
        }
    }
    swap(array[j], array[start]);
    return j;
}


template <typename T>
void __QuickSort2(T array[],int start, int end){
//    if (start-end>=15) {
//        SectionInsertionSort(array,start,end);
//        return;
//    }
    int p=__FirstPartition2(array,start,end);
//    Travel(array,10);
    __QuickSort2(array,start,p-1);
    __QuickSort2(array, p+1, end);
}


template <typename T>
void QuickSort2(T array[],int len){
    __QuickSort2(array, 0, len - 1);
}





#endif //QUICKSORT_SORT_H
