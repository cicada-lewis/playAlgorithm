//
// Created by Rechad Catelemmon on 2017/4/24.
//

#ifndef INSERTIONSORT_INSERTIONSORT_H
#define INSERTIONSORT_INSERTIONSORT_H
#include <algorithm>
using std::swap;
template <typename T>
void InsertionSort(T array[],int len){
    if(len<=1){
        return;
    }
    for(int i=1;i<len;i++){
        for(int j=i;j>0&&array[j]<array[j-1];j--){
            swap(array[j],array[j-1]);
        }
    }
}

template <typename T>
void OptimizedInsertionSort(T array[],int len){
    if(len<=1){
        return;
    }
    for(int i=1;i<len;i++){
        T temp=array[i];
        int j=i;
        for(;j>0&&array[j-1]>temp;j--){
            array[j]=array[j-1];
        }
        array[j]=temp;
    }
}

template <typename T>
void SectionInsertionSort(T array[],int start,int end){
    if(start<0||end<0){
        return;
    }
    for(int i=start+1;i<=end;i++){
        T temp=array[i];
        int j=i;
        for(;j>start&&array[j-1]>temp;j--){
            array[j]=array[j-1];
        }
        array[j]=temp;
    }
}

#endif //INSERTIONSORT_INSERTIONSORT_H
