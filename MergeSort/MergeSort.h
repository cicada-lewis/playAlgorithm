//
// Created by Rechad Catelemmon on 2017/4/26.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <algorithm>
#include "InsertionSort.h"
using std::min;

template <typename T>
void __merge(T array[],int start,int mid,int end){
    T *aux = new T[end - start + 1];//auxiliary
    for (int i = start; i <= end; i++)
        aux[i - start] = array[i];
    int i=start,j=mid+1;
    for(int k=start;k<=end;k++){
        if(i>mid) {
            array[k] = aux[j - start];
            j++;
        }
        else if(j>end){
            array[k] = aux[i - start];
            i++;
        }
        else if(aux[i-start]<aux[j-start]){
            array[k] = aux[i - start];
            i++;
        }
        else{
            array[k] = aux[j - start];
            j++;
        }
    }
    delete aux;
}

template <typename T>
void __merge2(T array[],int start,int mid,int end){
    T *aux=new T[end-start+1];
    for(int i=start;i<=end;i++)
        aux[i-start]=array[i];
    int i=start,j=mid+1,k=start;
    while(i<=mid&&j<=end){
        if(aux[i-start]>aux[j-start]){
            array[k++]=aux[j-start];
            j++;
        }
        else if(aux[i-start]<aux[j-start]){
            array[k++]=aux[i-start];
            i++;
        }
        else{
            array[k++]=aux[i-start];
            array[k++]=aux[j-start];
            i++,j++;
        }
    }
    while(i<=mid){
        array[k++]=aux[i-start];
        i++;
    }
    while(j<=end){
        array[k++]=aux[j-start];
        j++;
    }
    delete aux;
}

//使用Merge2要比Merge稍微快一点点，因为没有那么多判定

template <typename T>
void __mergeSort(T array[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    __mergeSort(array, start, mid);
    __mergeSort(array, mid + 1, end);
    __merge(array,start,mid,end);

//    __merge2(array, start, mid, end);
}


template <typename T>
void __mergeSort2(T array[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    __mergeSort(array, start, mid);
    __mergeSort(array, mid + 1, end);
//    __merge(array,start,mid,end);
    __merge2(array, start, mid, end);
}

template <typename T>
void __optimizedMergeSort(T array[],int start,int end){
    if(end-start<=15){
        SectionInsertionSort(array,start,end);
    }
    int mid=(start+end)/2;
    __mergeSort(array, start, mid);
    __mergeSort(array, mid + 1, end);
    if(array[mid]>array[mid+1]){
        __merge2(array,start,mid,end);
    }
}

template <typename T>
void MergeSort(T array[],int len){
    __mergeSort(array, 0, len - 1);
}

template <typename T>
void MergeSort2(T array[],int len){
    __mergeSort2(array, 0, len - 1);
}


template <typename T>
void OptimizedMergeSort(T array[],int len){
    __optimizedMergeSort(array, 0, len - 1);
}

template <typename T>
void MergeSortFromBottomToTop(T array[],int len){
    for(int size=1;size<=len;size+=size){
        for(int i =0;i+size<len;i+=size+size){
            __merge2(array,i,i+size-1,min(i+size+size-1,len-1));
        }
    }
}

template <typename T>
void OptimizedMergeSortFromBottomToTop(T array[],int len){
    for(int size=1;size<=len;size+=size){
        for(int i =0;i+size<len;i+=size+size){
            if(array[i+size-1]>array[i+size]){
                __merge2(array,i,i+size-1,min(i+size+size-1,len-1));
            }
        }
    }
}

#endif //MERGESORT_MERGESORT_H
