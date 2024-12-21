#ifndef AVLSET_H
#define AVLSET_H
#include "Set.h"
#include "AVLTree.h"
#include <vector>
using namespace std;

template<typename K>
class AVLSet: Set<K>{
private:
    AVLTree<K,K>* avlTree;
public:
    AVLSet(){
        avlTree = new AVLTree<K,K>();
    }
    int getSize(){
        return avlTree->getSize();
    }
    bool isEmpty(){
        return avlTree->isEmpty();
    }
    bool contains(K key){
        return avlTree->contains(key);
    }
    void add(K key){
        avlTree->add(key,key);
    }
    void remove(K key){
        avlTree->remove(key);
    }
    vector<K> allElement(){
    	return avlTree->keySet();
    }
    void print(){
    	for(K key: allElement()){
            cout<<key<<" ";
        }
    }
};
#endif
