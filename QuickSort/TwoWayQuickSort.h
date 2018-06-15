//
// Created by Rechad Catelemmon on 2017/5/2.
//

#include <algorithm>
#include "InsertionSort.h"
#include <ctime>
using std::swap;

#ifndef QUICKSORT_TWOSWAYQUICKSORT_H
#define QUICKSORT_TWOSWAYQUICKSORT_H


template <typename T>
int __TwoWayPartition(T array[],int start,int end){
    srand((unsigned) time(0));
    swap(array[start], array[rand() % (end - start + 1) + start]);
    T first = array[start];

    int i=start+1,j=end;
    while (true) {
        while(i<=end&&array[i]<first) i++;
        while(j>=start+1&&array[j]>first) j++;
        if(i>j) break;
        swap(array[i++], array[j--]);
    }
    swap(array[j], array[start]);
    return j;
}

template <typename T>
void __TwoWayQuickSort(T array[],int start,int end){
    if (end-start>=15) {
        SectionInsertionSort(array,start,end);
        return;
    }
    int p=__TwoWayPartition(array,start,end);
    __TwoWayQuickSort(array,start,p-1);
    __TwoWayQuickSort(array, p+1, end);
}

template <typename T>
void TwoWayQuickSort(T array[],int len){
    __TwoWayQuickSort(array, 0, len - 1);
}


#endif //QUICKSORT_TWOSWAYQUICKSORT_H
