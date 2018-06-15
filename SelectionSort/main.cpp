#include <iostream>
#include "SelectionSort.h"
#include "SortCommon.h"
#define ARRAY_LEN 10
using namespace std;


void Travel(int *array,int len);

int main(int argc,char *argv[]){
    int *array=new int[ARRAY_LEN];
    sort_common::GenerateRandomIntArray(array, ARRAY_LEN, 0, 100);
    sort_common::Travel(array,ARRAY_LEN);
//    SelectionSort(array, ARRAY_LEN);
    selection_sort::SelectionSort(array,ARRAY_LEN) ;
    sort_common::Travel(array,ARRAY_LEN);
    delete []array;
    int biglen=10000;
    array=new int[biglen];
    sort_common::GenerateRandomIntArray(array,biglen,0,10000);
    sort_common::JudgeSort("SelectionSort",selection_sort::SelectionSort,array,biglen);
    delete []array;
    return 0;
}

void SelectionSort(int *array,int len){
    for(int i=0;i<len;i++){
        int midIndex=i;
        for(int j=i+1;j<len;j++){
            if(array[j]<array[midIndex]){
                midIndex=j;
            }
        }
        swap(array[i],array[midIndex]);
    };
}
