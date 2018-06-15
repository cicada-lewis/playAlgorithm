//
// Created by Rechad Catelemmon on 2017/5/2.
//
#include <algorithm>
#include <ctime>
#include "InsertionSort.h"


#ifndef QUICKSORT_RANDOMQUICKSORT_H
#define QUICKSORT_RANDOMQUICKSORT_H
using std::swap;

template<typename T>
int __RandomPartition(T *array, int start, int end){
    srand((unsigned) time(0));
    swap(array[start], array[rand() % (end - start + 1) + start]);
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
void __RandomQuickSort(T array[],int start, int end){
    if (end-start<=15) {
        SectionInsertionSort(array,start,end);
        return;
    }
    int p=__RandomPartition(array,start,end);
    __RandomQuickSort(array,start,p-1);
    __RandomQuickSort(array, p+1, end);
}

template <typename T>
void RandomQuickSort(T array[],int len){
    __RandomQuickSort(array, 0, len - 1);
}

#endif //QUICKSORT_RANDOMQUICKSORT_H
