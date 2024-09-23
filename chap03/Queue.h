
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue{
    public: // virtual关键字表明，抽象容器不提供具体实现，具体容器务必给出具体实现
        virtual void enqueue(T elem) = 0;
        virtual T dequeue() = 0;
        virtual T getFront() = 0;
        virtual bool isEmpty() = 0;
        virtual int getLength() = 0;
};
#endif
