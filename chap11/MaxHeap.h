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
               if(data->getData(k) > data->getData(j)){
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
        MaxHeap(T arr[], int n){
            data = new TArr<T>(arr,n);
            for(int i = parent(n-1);i>=0;i--){
                shiftDown(i);
            }
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
            T ret = findMax();
            data->swap(0,data->getLength() - 1);
            data->removeLast();
            shiftDown(0);
            return ret;
        }

        T findMax(){
            if(data->isEmpty()){
                throw "堆内无数据";
            }
            return data->getData(0);
        }
        T replace(T e){
            T ret = findMax();
            data->setData(0,e);
            shiftDown(0);
            return ret;
        }
        void print(){
            data->print();
        }
};

