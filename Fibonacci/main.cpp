#include <iostream>

using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int Fib(int n){
    int *fib_array=new int[n];
    fib_array[1]=fib_array[2]=1;
    for(int i=3;i<n+1;i++){
        fib_array[i]=fib_array[i-1]+fib_array[i-2];
//        cout<<i<<":"<<fib_array[i]<<" ";
    }
    return fib_array[n];
}

int main(int argc,char *argv[]){
    cout<<fib(6)<<endl;
    cout<<Fib(6)<<endl;
    return 0;
}

