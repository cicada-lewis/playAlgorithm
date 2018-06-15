//
// Created by Rechad Catelemmon on 2017/4/25.
//

#ifndef SHELLSORT_SHELLSORT_H
#define SHELLSORT_SHELLSORT_H

template <typename T>
void ShellSort(T array[],int len){
    for(int gap=len/2;gap>=1;gap/=2){
        for(int i=gap;i<len;i++){
            T temp=array[i];
            int j;
            for(j = i;j>=gap&&temp<array[j-gap];j-=gap){
                array[j]=array[j-gap];
            }
            array[j]=temp;
        }
    }
}

#endif //SHELLSORT_SHELLSORT_H
