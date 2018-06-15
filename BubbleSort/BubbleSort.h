//
// Created by Rechad Catelemmon on 2017/4/26.
//

#ifndef BUBBLESORT_BUBBLESORT_H
#define BUBBLESORT_BUBBLESORT_H

#include <algorithm>
using std::swap;


template <typename T>
void BubbleSort(T array[],int len){
    for(int i=len;i>0;i--){
        for(int j=1;j<i;j++){
            if(array[j-1]>array[j]){
                swap(array[j-1],array[j]);
            }
        }
    }
}


template <typename T>
void OptimizedBubbleSort(T array[],int len){
    int i,j,flag;
    flag=len;
    while(flag>0){
        j=flag;
        flag=0;
        for (i = 1; i < j; ++i) {
            if(array[i-1]>array[i]){
                swap(array[i], array[i - 1]);
                flag=i;
            }
        }
    }
}


#endif //BUBBLESORT_BUBBLESORT_H
