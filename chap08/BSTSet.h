#ifndef BSTSET_H
#define BSTSET_H

#include "Set.h"
#include "BST.h"
#include "FileOperation.h"

template<typename T>
class BSTSet: public Set<T>{
    private:
        BST<T> *bst;
    public:
        BSTSet(){
            bst = new BST<T>();
        }
        void add(T e){
            bst->add(e);
        }
        void remove(T e){
            bst->remove(e);
        }
        bool contains(T e){
            return bst->contains(e);
        }
        int getSize(){
            return bst->getSize();
        }
        bool isEmpty(){
            return bst->isEmpty();
        }
};


#endif
