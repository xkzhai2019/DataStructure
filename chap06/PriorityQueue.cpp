#include "Queue.h"
#include "MaxHeap.h"
#include <iostream>
using namespace std;

template<typename T>
class PriorityQueue: public Queue<T>{
    private:
        MaxHeap<T> *maxHeap;
    public:
        PriorityQueue(){
            maxHeap = new MaxHeap<T>();
        }

        int getLength(){
            return maxHeap->getLength();
        }
        bool isEmpty(){
            return maxHeap->isEmpty();
        }
        T getFront(){
            return maxHeap->findMax();        
        }
        void enqueue(T e){
            maxHeap->add(e);
        }
        T dequeue(){
            maxHeap->extractMax();
        }
        void print(){
            cout<< "Queue length = "<<maxHeap->getLength()<<endl;
            cout<<"队首";
            maxHeap->print();
            cout<<"队尾"<<endl;
        }
};

int main(){
    PriorityQueue<int> *queue = new PriorityQueue<int>();
    for(int i=0; i<10; i++){
        queue->enqueue(i);
        queue->print();
        if(i % 3 == 2){
            queue->dequeue();
            queue->print();
        }
    }
    return 0;
}
