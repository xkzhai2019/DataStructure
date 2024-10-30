#include "TArr.h"
#include <iostream>
using namespace std;

template<typename T>
class MaxHeap{
    private:
        TArr<T>* data;
        int parent(int index){
            if(index==0){
                throw "No parent";
            }
            return (index-1)/2;
        }
        int leftChild(int index){
            return 2*index + 1;
        }
        int rightChild(int index){
            return 2*index + 2;
        }
        void shiftUp(int k){
            while(k>0 && data->getData(parent(k)) < data->getData(k)){
                data->swap(parent(k),k);
                k = parent(k);
            }
        }

        void shiftDown(int k){
            while(leftChild(k) < data->getLength()){
               //int j = data->getData(leftChild(k)) > data->getData(rightChild(k)) ? leftChild(k) : rightChild(k); 
               int j = leftChild(k);
               if(j+1 < data->getLength() && data->getData(j+1) > data->getData(j)){
                   j++;
               }
               if(data->getData(k) >= data->getData(j)){
                   break;
               }
               data->swap(k,j);
               k = j;
            }
        }

    public:
        MaxHeap(int size){
            data = new TArr<T>(size);
        }
        MaxHeap(){
            data = new TArr<T>();
        }
        int getLength(){
            return data->getLength();
        }
        bool isEmpty(){
            return data->isEmpty();
        }
        void add(T e){
            data->addLast(e);
            shiftUp(data->getLength()-1);
        }
        T extractMax(){
            if(data->isEmpty()){
                throw "堆内无数据";
            }
            T ret = data->getData(0);
            data->swap(0,data->getLength() - 1);
            data->removeLast();
            shiftDown(0);
            return ret;
        }
};

int main(){
    int n = 1000000;
    MaxHeap<int> *maxHeap = new MaxHeap<int>(10);
    for(int i = 0; i < n; ++i){
        maxHeap->add(rand());
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
    return 0;
}
