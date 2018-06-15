#include <iostream>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define RAND_RANGE 100


typedef struct MaxHeap {
    int *arr;
    int capacity;
    int count;
} *MaxTopHeap;


MaxTopHeap InitHeap(int capacity);

void Insert(MaxTopHeap &heap, int elem);

void ShiftUp(MaxTopHeap &heap, int index);

void TravelHeap(MaxTopHeap &head);

int *GenerateArray(int length);

void TravelArray(int *arr, int length);

void TravelHeap(MaxTopHeap &heap);

void ShiftDown(MaxTopHeap &heap, int index);

int ExtractMax(MaxTopHeap &heap);

int main(int argc, char *argv[]) {

//    int *arr = GenerateArray(10);
    int *arr=new int[10]{97,79,16,46,49,93,57,69,35,99};
    TravelArray(arr,10);
    MaxTopHeap heap = InitHeap(10);
    for (int i = 0; i < 10; i++)
        Insert(heap, arr[i]);
//    cout<<heap->count<<endl;
//    TravelHeap(heap);
    for (int i = 0; i < 10; i++) {
        cout<<ExtractMax(heap)<<" ";
    }
    return 0;
}


MaxTopHeap InitHeap(int capacity) {
    MaxTopHeap heap = new MaxHeap();
    heap->capacity = capacity;
    heap->count = 0;
    heap->arr = new int[capacity + 1];
    return heap;
}

void Insert(MaxTopHeap &heap, int elem) {
    assert(heap->count + 1 <= heap->capacity);
    heap->arr[++heap->count] = elem;
    ShiftUp(heap, heap->count);
}

void ShiftUp(MaxTopHeap &heap, int index) {
    while (index > 1 && heap->arr[index / 2] < heap->arr[index]) {
        swap(heap->arr[index / 2], heap->arr[index]);
        index /= 2;
    }
}

int *GenerateArray(int length) {
    int *arr = new int[length];
    srand((unsigned) time(0));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % RAND_RANGE;
    }
    return arr;
}

void TravelArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void TravelHeap(MaxTopHeap &heap) {
    int numcount = 1, level = 0, level_num_count = 1;
    int lastLevel=0;
    while (numcount <= heap->count + 1&&lastLevel<=1) {
        cout << "level " << level + 1 << ": ";
        for (int i = pow(2, level); i <level_num_count+pow(2,level); i++)
            cout << heap->arr[i] << " ";
        cout << endl;
        level++;
        level_num_count = pow(2, level);
        if (numcount + level_num_count >= heap->count){
            level_num_count = heap->count - numcount;
            lastLevel++;
        }
        numcount +=level_num_count;
    }
}

int ExtractMax(MaxTopHeap &heap){
    assert(heap->count > 0);
    int res = heap->arr[1];
    swap(heap->arr[1], heap->arr[heap->count--]);
    ShiftDown(heap,1);
    return res;
}

void ShiftDown(MaxTopHeap &heap, int index) {
    while (2 * index <= heap->count) {
        int j=2*index;//这是左边孩子
        if (j + 1 <= heap->count&&heap->arr[j+1]>heap->arr[j]) {//右边孩子是不是大于左边孩子
            j+=1;
        }
        if(heap->arr[index]>=heap->arr[j]){//这个已经是最大了
            break;
        }
        swap(heap->arr[index], heap->arr[j]);//最后就交换
        index=j;
    }
}

