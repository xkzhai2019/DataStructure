#include <iostream>

template<typename T>
class Node{
//    private:
    public:
        T e;
        Node<T> *next;
    public:
        Node(T e, Node<T> *next){
            this->e = e;
            this->next = next;
        }
        Node(T e){
            this->e =e;
            //next = NULL;
            next = nullptr;
        }
        Node(){
            next = nullptr;
        }
};

template<typename T>
class LinkedList{
    private:
        Node<T> *dummyHead; //指向虚拟头节点的指针
        int length; // 存储当前链表中总共有多少节点
    public:
        LinkedList(){
            dummyHead = new Node<T>(); // 初始化链表时，没有首个节点，节点个数为0
            length = 0;
        }
        int getLength(){
            return length;
        }
        bool isEmpty(){
            return length==0;
        }
        void addFirst(T e){
            /*
            Node<T> *node = new Node<T>(e);
            node->next = dummyHead->next;
            dummyHead->next = node;
            length++;
            */
            add(0,e);
        }
        void add(int index,T e){
            if(index<0 || index>length){
                std::cout<<"索引越界，无法添加"<<std::endl;
                return;
            }

            Node<T> *prev = dummyHead;
            //for(int i=0;i<index-1;i++){//假设index为1
            for(int i=0;i<index;i++){
                prev = prev->next;
            }
            prev->next = new Node<T>(e,prev->next);
            length++;
        }
        void addLast(T e){
            add(length,e);
        }

        void print(){
            Node<T> *cur = dummyHead->next;
            std::cout<<"LinkedList: length = "<< length<<std::endl;
            std::cout<<"dummyHead->";
            for(int i=0;i<length;i++){
                std::cout<<cur->e<<"->";
                cur = cur->next;
            }
            std::cout<<"NULL"<<std::endl;
        }
        
        T get(int index){
            if(index<0 || index>=length){
                throw "illegal index";
            }
            Node<T> *cur = dummyHead->next;
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
            Node<T> *cur = dummyHead->next;
            /*
            for(int i=0;i<length;i++){
                if(cur->e == e){
                    return true;
                }
                cur = cur->next;
            }
            */
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
            Node<T> *cur = dummyHead->next;
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
            Node<T> *prev = dummyHead;
            for(int i=0;i<index;i++){
                prev = prev->next;
            }
            Node<T> *delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = nullptr;
            length--;
            return delNode->e;
        }
        T removeFirst(){
           return remove(0);
        }
        T removeLast(){
           return remove(length-1);
        }   
};

int main(){
    using namespace std;
    LinkedList<int> linkedList;
    for(int i=0;i<10;i++){
        if(i%2==0){
            linkedList.addFirst(i);
            linkedList.print();
        }else{
            linkedList.addLast(i);
            linkedList.print();
        }
    }
    cout<<"contains(11)"<<linkedList.contains(11)<<endl;
    cout<<"getFirst()"<<linkedList.getFirst()<<endl;
    cout<<"getLast()"<<linkedList.getLast()<<endl;
    cout<<"修改首节点数据为10:"<<endl;
    linkedList.setFirst(10);
    linkedList.print();
    cout<<"修改尾节点数据为20:"<<endl;
    linkedList.setLast(20);
    linkedList.print();
    cout<<"删除2处数据:"<<endl;
    cout<<"删除了："<<linkedList.remove(2)<<endl;
    linkedList.print();
    cout<<"删除头节点:"<<endl;
    cout<<"删除了："<<linkedList.removeFirst()<<endl;
    linkedList.print();
    cout<<"删除尾节点:"<<endl;
    cout<<"删除了："<<linkedList.removeLast()<<endl;
    linkedList.print();
    
    return 0;
}
