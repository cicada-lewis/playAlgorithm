
#ifndef SELECTION_SELECTION_H
#define SELECTION_SELECTION_H

#include <iostream>
#include <time.h>
#include <algorithm>


namespace selection_sort{
    template<typename T>
    void SelectionSort(T array[],int len){
        for(int i=0;i<len;i++){
            int tinyIndex=i;
            for(int f=i+1;f<len;f++){
                if( array[f]<array[tinyIndex]){
                    tinyIndex=f;
                }
            }
            std::swap(array[i],array[tinyIndex]);
        }
    }
}
#endif