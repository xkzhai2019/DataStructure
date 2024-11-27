#ifndef LINKLISTSET_H
#define LINKLISTSET_H

#include "Set.h"
#include "LinkedList.h"
#include "FileOperation.h"

template<typename T>
class LinkedListSet{
private:
    LinkedList<T> *list;
public:
    LinkedListSet(){
        list = new LinkedList<T>();
    }
    void add(T e){
        if(!list->contains(e)){
            list->addFirst(e);
        }
    }
    void remove(T e){
        list->removeEle(e);        
    }
    bool contains(T e){
        return list->contains(e);        
    }
    int getSize(){
        return list->getLength();
    }
    bool isEmpty(){
        return list->isEmpty();
    }
};


#endif
