#include <iostream>

using namespace std;


typedef struct unionfind{
    int *ids;
    int count;
}unionfind;

unionfind* Initial(int unionsize){
    unionfind *uf = (unionfind *) malloc(sizeof(unionfind));
    uf->count=unionsize;
    uf->ids = new int[unionsize];
        return uf;
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}