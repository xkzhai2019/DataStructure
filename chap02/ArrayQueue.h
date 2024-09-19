#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "TArr.h"
#include "Queue.h"

template<typename T>
class ArrayQueue: public Queue<T>{
    private:
        TArr<T> *myArr;
    public:
        ArrayQueue(){
            myArr = new TArr<T>();
        }
        
        ArrayQueue(int size){
            myArr = new TArr<T>(size);
        }

        void enqueue(T elem){
            myArr->addLast(elem);
        }

        T dequeue(){
            return myArr->removeFirst();
        }

        T getFront(){
            return myArr->getData(0);    
        }

        int getLength(){
            return myArr->getLength();            
        }

        bool isEmpty(){
            return myArr->isEmpty(); 
        }

        // 打印队列所有元素
        void print() {
            std::cout << "ArrayQueue: length = " << getLength() << ", Size = " << myArr->getSize() << std::endl;
            std::cout << "队首 ";
            myArr->print();
            std::cout << " 队尾" << std::endl;
        }
};

#endif
