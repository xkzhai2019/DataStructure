#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include "LinkedList.h"
#include "Stack.h"

template<typename T>
class LinkedListStack: public Stack<T>{
    private:
        LinkedList<T> *list;
    public:
        LinkedListStack(){
            list = new LinkedList<T>();
        }
        int getLength(){
            return list->getLength();
        }
        bool isEmpty(){
            return list->isEmpty();
        }
        void push(T e){
            list->addFirst(e);
        }
        T pop(){
            return list->removeFirst();
        }
        T peek(){
            return list->getFirst();
        }

        // 打印栈内所有元素
        void print() {
            std::cout << "LinkedListStack: length = " << getLength() << std::endl;
            std::cout << "top ";
            list->print();
            std::cout << " bottom" << std::endl;
        }
};
#endif
