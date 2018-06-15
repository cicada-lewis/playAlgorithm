//
// Created by Rechad Catelemmon on 2017/4/21.
//

#ifndef SELECTION_SORTCOMMON_H
#define SELECTION_SORTCOMMON_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
namespace sort_common{
    void GenerateRandomIntArray(int *array, int len, int r_begin, int r_end);
    void GenerateOrderedIntArray(int *array, int len);
    template <typename T>
    void Travel(T array[],int len);
    template <typename T>
    void JudgeSort(string sort_name,void (*sort)(T[],int len),T array[],int len);
    template <typename T>
    bool isSorted(T array[],int len);
}

void sort_common::GenerateRandomIntArray(int *array, int len, int r_begin, int r_end){
    srand((unsigned)time(0));
    for(int i=0;i<len;i++){
        array[i]=(rand()%(r_end-r_begin+1)+r_begin);
    }
}

void sort_common::GenerateOrderedIntArray(int *array, int len){
    for(int i=0;i<len;i++){
        array[i]=i;
    }
}

template <typename T>
void sort_common::Travel(T array[],int len){
    for(int i=0;i<len;i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
}


template <typename T>
void sort_common::JudgeSort(string sort_name, void (*sort)(T [], int), T array[], int len) {
    clock_t startTime=clock();
    sort(array,len);
    clock_t endTime=clock();
    assert(isSorted(array,len));
    cout<<sort_name<<" : "<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<" s "<<endl;
}

template <typename T>
bool sort_common::isSorted(T *array, int len) {
    for(int i=0;i<len-1;i++){
        if(array[i]>array[i+1]){
            return false;
        }
    }
    return true;
}
#endif //SELECTION_SORTCOMMON_H
