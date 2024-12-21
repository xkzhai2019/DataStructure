#ifndef AVLMAP_H
#define AVLMAP_H
#include "Map.h"
#include "AVLTree.h"

template<typename K,typename V>
class AVLMap: Map<K,V>{
private:
    AVLTree<K,V>* avlTree;
public:
    AVLMap(){
        avlTree = new AVLTree<K,V>();
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
    V get(K key){
        return avlTree->get(key);
    }

    void add(K key,V value){
        avlTree->add(key,value);
    }
    void set(K key, V value){
        avlTree->set(key,value);
    }
    vector<K> keySet(){
        return avlTree->keySet();
    }
    V remove(K key){
        return *(avlTree->remove(key));
    }
    void print(){
        for(K key: keySet()){
            cout<<"("<<key<<": "<<get(key)<<") ";
        }
    }
};
#endif
