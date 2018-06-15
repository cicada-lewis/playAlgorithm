//
// Created by Rechad Catelemmon on 2017/5/3.
//


#ifndef QUICKSORT_THREEWAYQUICKSORT_H
#define QUICKSORT_THREEWAYQUICKSORT_H

#include <algorithm>
#include "InsertionSort.h"
#include <ctime>
using std::swap;


template<typename T>
void __ThreeWayQuickSort(T array[], int start, int end){
    srand((unsigned) time(0));
//    if(start>=end){
//        return;
//    }
    if(end-start<=15){
        SectionInsertionSort(array, start, end);
        return;
    }
    swap(array[start], array[rand() % (end - start + 1) + start]);
    T first = array[start];

    int i=start+1;
    int lessThan=start;
    int greaterThan=end+1;
    for(;i<greaterThan;){
        if (array[i] < first) {
            swap(array[i++],array[++lessThan]);
        }
        else if(array[i]>first){
            swap(array[i], array[--greaterThan]);
        }
        else{
            i++;
        }
    }
    swap(array[start],array[lessThan]);

    __ThreeWayQuickSort(array, start, lessThan - 1);
    __ThreeWayQuickSort(array, greaterThan, end);
}

template<typename T>
void ThreeWayQuickSort(T array[], int len){
    __ThreeWayQuickSort(array, 0, len - 1);
}



#endif //QUICKSORT_THREEWAYQUICKSORT_H
