#ifndef STACK_H 
#define STACK_H
template<typename T>
class Stack{
    public: // virtual关键字表明，抽象容器不提供具体实现，具体容器务必给出具体实现
        virtual void push(T elem) = 0;
        virtual T pop() = 0;
        virtual T peek() = 0;
        virtual bool isEmpty() = 0;
        virtual int getLength() = 0;
};
#endif

