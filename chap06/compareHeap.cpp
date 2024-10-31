#include "TArr.h"
#include "MaxHeap.h"
#include <iostream>
using namespace std;

template<typename T>
double testHeap(T testArr[], int n, bool isHeapify){
    clock_t startTime = clock();
    MaxHeap<T> *maxHeap; 
    if(isHeapify){
        maxHeap = new MaxHeap<T>(testArr,n);
    }else{
        maxHeap = new MaxHeap<int>();
        for(int i = 0; i < n; i++){
            maxHeap->add(testArr[i]);
        }
    }
    int *arr = new int[n];
    for(int j = 0; j < n; j++){
        arr[j] = maxHeap->extractMax();
    }
    for(int k = 1; k < n; k++){
        if(arr[k-1] < arr[k]){
            cout<<"堆删除元素出错"<<endl;
        }
    }
    cout<<"堆测试完成"<<endl;
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}


int main(){
    int n = 10000000;
    int *testArr = new int[n];
    for(int i=0; i<n; i++){
        testArr[i] = rand();
    }
    //MaxHeap<int> *maxHeap = new MaxHeap<int>(testArr,n);
    /*
    MaxHeap<int> *maxHeap = new MaxHeap<int>();
    for(int i = 0; i < n; i++){
        maxHeap->add(testArr[i]);
    }*/
    double time1 = testHeap(testArr,n,false);
    cout<<"without heapify: "<<time1<<" s "<<endl;
    double time2 = testHeap(testArr,n,true);
    cout<<"with heapify: "<<time2<<" s "<<endl;
    return 0;
}
