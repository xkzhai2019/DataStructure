#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedNode{
    public:
        T e;
        LinkedNode<T> *next;
    public:
        LinkedNode(T e, LinkedNode<T> *next){
            this->e = e;
            this->next = next;
        }
        LinkedNode(T e){
            this->e =e;
            next = nullptr;
        }
        LinkedNode(){
            next = nullptr;
        }
};

template<typename T>
class LinkedList{
    private:
        LinkedNode<T> *dummyHead; //指向虚拟头节点的指针
        int length; // 存储当前链表中总共有多少节点
    public:
        LinkedList(){
            dummyHead = new LinkedNode<T>(); // 初始化链表时，没有首个节点，节点个数为0
            length = 0;
        }
        int getLength(){
            return length;
        }
        bool isEmpty(){
            return length==0;
        }
        void addFirst(T e){
            add(0,e);
        }
        void add(int index,T e){
            if(index<0 || index>length){
                std::cout<<"索引越界，无法添加"<<std::endl;
                return;
            }

            LinkedNode<T> *prev = dummyHead;
            for(int i=0;i<index;i++){
                prev = prev->next;
            }
            prev->next = new LinkedNode<T>(e,prev->next);
            length++;
        }
        void addLast(T e){
            add(length,e);
        }

        void print(){
            LinkedNode<T> *cur = dummyHead->next;
            for(int i=0;i<length;i++){
                std::cout<<cur->e<<"->";
                cur = cur->next;
            }
            std::cout<<"NULL";
        }
        
        T get(int index){
            if(index<0 || index>=length){
                throw "illegal index";
            }
            LinkedNode<T> *cur = dummyHead->next;
            for(int i=0;i<index;i++){
               cur = cur->next; 
            }
            return cur->e;
        }
        T getFirst(){
            return get(0);
        }
        T getLast(){
            return get(length-1);
        }
        bool contains(T e){
            LinkedNode<T> *cur = dummyHead->next;
            for(;cur!=nullptr;cur=cur->next){
                if(cur->e == e){
                    return true;
                }
            }
            return false;
        }
        void set(int index,T e){
            if(index<0 || index>=length){
                throw "illegal index";
            }
            LinkedNode<T> *cur = dummyHead->next;
            for(int i=0;i<index;i++){
               cur = cur->next;
            }
            cur->e = e;
        }
        void setFirst(T e){
            set(0,e);
        }
        void setLast(T e){
            set(length-1,e);
        }
        T remove(int index){
            if(index<0 || index>=length){
                throw "illegal index";
            }
            LinkedNode<T> *prev = dummyHead;
            for(int i=0;i<index;i++){
                prev = prev->next;
            }
            LinkedNode<T> *delLinkedNode = prev->next;
            prev->next = delLinkedNode->next;
            delLinkedNode->next = nullptr;
            length--;
            return delLinkedNode->e;
        }
        T removeFirst(){
           return remove(0);
        }
        T removeLast(){
           return remove(length-1);
        }   
        void removeEle(T e){
            LinkedNode<T> *prev = dummyHead;
            while(prev->next != nullptr){
                if(prev->next->e ==e ){
                    break;
                }else{
                    prev = prev->next;
                }
            }
            if(prev->next != nullptr){
                LinkedNode<T> *delLinkedNode = prev->next;
                prev->next = delLinkedNode->next;
                delLinkedNode->next = nullptr;
                length--;
                delete delLinkedNode;
            }
        }
};
#endif
