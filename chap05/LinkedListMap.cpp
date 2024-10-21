#include <iostream>
#include "FileOperation.h"
#include "Map.h"
using namespace std;

template<typename K, typename V>
class LinkedNode{
    public:
        K key;
        V value;
        LinkedNode<K,V> *next;
    public:
        LinkedNode(K key, V value, LinkedNode<K,V> *next){
            this->key = key;
            this->value = value;
            this->next = next;
        }
        LinkedNode(K key, V value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
        LinkedNode(){
            next = nullptr;
        }
};

template<typename K, typename V>
class LinkedListMap: public Map<K,V>{
    private:
        LinkedNode<K,V> *dummyHead; //指向虚拟头节点的指针
        int size; // 存储当前链表中总共有多少节点
        LinkedNode<K,V> *getNode(K key){
            LinkedNode<K,V> *cur = dummyHead->next;
            while(cur!=nullptr){
                if(cur->key == key){
                    return cur;
                }
                cur = cur->next;
            }
            return nullptr;
        }
    public:
        LinkedListMap(){
            dummyHead = new LinkedNode<K,V>(); 
            size = 0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size==0;
        }
        bool contains(K key){
            LinkedNode<K,V> *node = getNode(key);
            return node!=nullptr;
        }

        V get(K key){
            LinkedNode<K,V> *node = getNode(key);
            if(node==nullptr){
                throw "no this key";
            }
            return node->value;
        }
        void add(K key, V value){
            LinkedNode<K,V> *node = getNode(key);
            if(node==nullptr){
                dummyHead->next = new LinkedNode<K,V>(key,value,dummyHead->next);
                size++;
            }else{
                node->value = value;
            }
        }
        void set(K key, V value){
            LinkedNode<K,V> *node = getNode(key);
            if(node!=nullptr){
                node->value = value;
            }else{
                add(key,value);
            }
        }

        V remove(K key){
            LinkedNode<K,V> *node = getNode(key);
            if(node==nullptr){
                throw "no this key";
            }
            V value = node->value;
            
            LinkedNode<K,V> *prev = dummyHead;
            while(prev->next!=nullptr){
                if(prev->next->key == key){
                    break;
                }
                prev = prev->next;
            }
            if(prev->next!=nullptr){
                LinkedNode<K,V> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
                size--;
            }
            return value;
        }
};

int main(){
    cout << "pride-and-prejudice.txt" << endl;
    string filename = "pride-and-prejudice.txt";
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (linkedListMap->contains(word)) {
                linkedListMap->set(word, linkedListMap->get(word) + 1);
            } else {
                linkedListMap->add(word, 1);
            }
        }
        cout << "Total different words: " << linkedListMap->getSize() << endl;
        cout << "Frequency of PRIDE: " << linkedListMap->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << linkedListMap->get("prejudice") << endl;
    }
    return 0;
}
