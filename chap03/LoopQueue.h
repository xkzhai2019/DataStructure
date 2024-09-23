#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H

#include <iostream>
#include "Queue.h"

template<typename T>
class LoopQueue: public Queue<T>{
    private:
        T *data;
        int front,tail;
        int size;
        void resize(int newSize){
            T *newData = new T[newSize+1];
            for(int i=0;i<getLength();i++){
                newData[i] = data[(i+front)%size];
            }
            data = newData;
            front = 0;
            tail = getLength();
            size = newSize;
        }
    public:
        LoopQueue(){//无参构造，默认size为10
            data = new T[10];
            front = 0;
            tail = 0;
            size = 9;
        }
        
        LoopQueue(int size){
            data = new T[size+1];
            front = 0;
            tail = 0;
            this->size = size;
        }

        void enqueue(T elem){
            // 判断队列是否已满
            if((tail+1)%size == front){
                resize(size*2);
            }
            data[tail] = elem;
            tail = (tail + 1)%size;
        }

        T dequeue(){
            // 判断队列是否为空
            if(isEmpty()){
                throw "empty exception";
            }
            T ret = data[front];
            front = (front + 1)%size;

            if(getLength() == size/4 && size/2!=0){
                resize(size/2);
            }
            return ret;

        }

        T getFront(){
            // 判断队列是否为空
            if(isEmpty()){
                throw "empty exception";
            }
            return data[front];   
        }

        int getLength(){
            return (tail + size+1 - front) % size;            
        }

        int getSize(){
            return size;
        }
        bool isEmpty(){
            return front==tail; 
        }

        // 打印队列所有元素
        void print() {
            std::cout << "LoopQueue: length = " << getLength() << ", Size = " << getSize() << std::endl;
            std::cout << "队首[ ";
            for(int i=front;i!=tail;i=(i+1)%size){
                std::cout<<data[i]<<" ";
            }
            std::cout << " ]队尾" << std::endl;
        }
};
#endif
