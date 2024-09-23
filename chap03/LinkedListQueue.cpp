#include <iostream>
template<typename T>
class Node{
    public:
        T e;
        Node<T> *next;
    public:
        Node(){
            next = nullptr;
        }
        Node(T e){
            this->e = e;
            next = nullptr;
        }
        Node(T e,Node<T> *next){
            this->e = e;
            this->next = next;
        }
};

template<typename T>
class LinkedListQueue{
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
    public:
        LinkedListQueue(){
            head = nullptr;
            tail = head;
            length = 0;
        }
        int getLength(){
            return length;
        }
        bool isEmpty(){
            return length==0;
        }
        T getFront(){
            if(isEmpty()){
                throw "empty queue";
            }
            return head->e;
        }
        void enqueue(T e){
            if(tail==nullptr){
                tail = new Node<T>(e);
                head = tail;
            }else{
                tail->next = new Node<T>(e);
                tail = tail->next;
            }
            length++;
        }
        T dequeue(){
            if(isEmpty()){
                throw "empty queue";
            }
            Node<T> *delNode = head;
            head = head->next;
            delNode->next = nullptr;
            if(head == nullptr){
                tail = nullptr;
            }
            length--;
            return delNode->e;
        }
        void print(){
            Node<T> *cur = head;
            std::cout<<"LinkedListQueue: length = "<<getLength()<<std::endl;
            std::cout<<"队首";
            std::cout<<"[";
            while(cur!=nullptr){
                std::cout<<cur->e<<" ";
                cur = cur->next;
            }
            std::cout<<"] 队尾"<<std::endl;
        }
};

int main(){
    LinkedListQueue<int> myQueue;
    for(int i=0;i<10;i++){
        myQueue.enqueue(i);
        myQueue.print();
        if(i%3==0){
            myQueue.dequeue();
            myQueue.print();
        }
    }
    return 0;
}
