#ifndef ARRSTACK_H
#define ARRSTACK_H

#include "TArr.h"
#include "Stack.h"

template<typename T>
class ArrayStack: public Stack<T>{
    private:
        TArr<T> *myArr;
    public:
        ArrayStack(){
            myArr = new TArr<T>();
        }
        
        ArrayStack(int size){
            myArr = new TArr<T>(size);
        }

        void push(T elem){
            myArr->addLast(elem);
        }

        T pop(){
            return myArr->removeLast();
        }

        T peek(){
            return myArr->getLast();    
        }

        int getLength(){
            return myArr->getLength();            
        }

        bool isEmpty(){
            return myArr->isEmpty(); 
        }

        // 打印栈内所有元素
        void print() {
            std::cout << "ArrayStack: length = " << getLength() << ", Size = " << myArr->getSize() << std::endl;
            std::cout << "bottom ";
            myArr->print();
            std::cout << " top" << std::endl;
        }
};

#endif
