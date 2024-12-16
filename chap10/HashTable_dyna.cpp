#include "AVLTree.h"
#include "FileOperation.h"
#include "BSTMap.h"
#include <iostream>
#include <string>
#include <vector>
//#include <ctime>
using namespace std;

template<typename Key, typename Value>
class HashTable {
private:
    const int upperTol = 8;
    const int lowerTol = 2;
    const int initialCapacity = 7;
    int M; // 取模的那个素数，表的长度
    int size; // 表中存储数据的个数
    //AVLTree<Key, Value> *hashTable[];

    // 指向AVL树指针数组的指针
    AVLTree<Key, Value> **hashTable; //by JinLiang

    int hash(Key key) {
        return (hashCode(key) & 0x7fffffff) % M;
    }

    int hashCode(Key key) {
        std::hash<Key> key_hash;
        return key_hash(key);
    }

public:

    HashTable(int M) {
        this->M = M;
        size = 0;
        //*hashTable = new AVLTree<Key, Value>[M]{};
        hashTable = new AVLTree<Key, Value>* [M]; //by JinLiang
        
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new AVLTree<Key, Value>();// 初始化每个槽位(by JinLiang)
        }
    }

    /*
    // 析构函数，by JinLiang
    ~HashTable(){
        for(int i=0;i<M;i++){
            delete hashTable[i]; // 释放每个AVL树
        }
        delete[] hashTable; // 释放哈希表数组
    }
    */
    HashTable() {
        this->M = initialCapacity;
        size = 0;
        hashTable = new AVLTree<Key, Value>* [M];
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new AVLTree<Key, Value>();
        }
    }

    int getSize() {
        return size;
    }

    void add(Key key, Value value) {
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if (avlTree->contains(key)) {
            avlTree->set(key, value);
        } else {
            avlTree->add(key, value);
            size++;

            if(size >= M*upperTol){
                resize(2*M);
            }
        }
    }
    Value* remove(Key key) {
        Value *ret = nullptr;
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if(avlTree->contains(key)){
            ret = avlTree->remove(key);
            size--;

            if(size < M*lowerTol && M / 2 >= initialCapacity){
                resize(M/2);
            }
        }
        return ret;
    }

    bool contains(Key key) {
        return hashTable[hash(key)]->contains(key);
    }

    Value get(Key key) {
        return (hashTable[hash(key)]->get(key));
    }

    void set(Key key, Value value) {
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if (!avlTree->contains(key)) {
            throw key + "doesn't exist";
        }
        avlTree->set(key, value);
    }
    // 调整哈希表大小
    void resize(int newM){
        //AVLTree<Key, Value> *newHashTable[newM];
        AVLTree<Key, Value> **newHashTable = new AVLTree<Key,Value>* [newM]; // 新的哈希表, by JinLiang
        for(int i = 0 ; i < newM ; i ++)
            newHashTable[i] = new AVLTree<Key,Value>();

        int oldM = M;
        this->M = newM;
        // 迁移旧的哈希表数据到新的哈希表, by JinLiang
        for(int i = 0 ; i < oldM ; i ++){
            AVLTree<Key, Value>* avlTree = hashTable[i];
            for(Key key: avlTree->keySet())
                newHashTable[hash(key)]->add(key, avlTree->get(key));
            delete avlTree;
        }
        delete[] hashTable; //释放旧的哈希表数组内存, by JinLiang
        hashTable = newHashTable; // 将新的哈希表地址赋值给hashTable
    }
};

int main(){
    vector<string> words;
    HashTable<string,int>* hashTable = new HashTable<string,int>();
    if (FileOps::readFile("pride-and-prejudice.txt", words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        clock_t startTime = clock();
        for (string word : words) {
            if (hashTable->contains(word)) {
                hashTable->set(word, (hashTable->get(word)) + 1);
            } else {
                hashTable->add(word, 1);
            }
        }

        for (string word : words) {
            hashTable->contains(word);
        }
        
        /*
        for (string word : words) {
            hashTable->remove(word);
        }
        */
        
        clock_t endTime = clock();
       std::cout << "Total different words: " << hashTable->getSize() << std::endl;
       std::cout << "Frequency of PRIDE: " << (hashTable->get("pride")) << std::endl;
       std::cout << "Frequency of PREJUDICE: " << (hashTable->get("prejudice")) << std::endl;
       cout<<"HashTable:"<< double(endTime - startTime) / CLOCKS_PER_SEC << "s"<<endl;
    }

    AVLTree<string, int> *avl = new AVLTree<string, int>();
    vector<string> words3;
    if (FileOps::readFile("pride-and-prejudice.txt", words3)) {
        cout << "Total words: " << words3.size() << endl;
        clock_t startTime = clock();
        for (string word : words3) {
            if (avl->contains(word)) {
                avl->set(word, avl->get(word) + 1);
            } else {
                avl->add(word, 1);
            }
        }
        for(string word: words3){
            avl->contains(word);
        }
        /*
        for (string word : words3) {
            avl->remove(word);
        }
        */
        clock_t endTime = clock();
        cout << "Total different words: " << avl->getSize() << endl;
        cout << "Frequency of PRIDE: " << avl->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << avl->get("prejudice") << endl;
        cout << "AVLTree: "<< double(endTime - startTime)/CLOCKS_PER_SEC << "s" <<endl;
    }
    return 0;
}
