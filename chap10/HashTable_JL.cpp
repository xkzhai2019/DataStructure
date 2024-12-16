#include "AVLTree.h"
#include "FileOperation.h"
#include "BSTMap.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

template<typename Key, typename Value>
class HashTable {
private:
    const int upperTol = 8;
    const int lowerTol = 2;
    const int initialCapacity = 7;
    int M;  // 哈希表的大小
    int size;  // 当前存储的元素数量
    AVLTree<Key, Value> **hashTable;  // 指向AVL树指针数组的指针
    
    int hash(Key key) {
        return (hashCode(key) & 0x7fffffff) % M;
    }
    
    int hashCode(Key key) {
        std::hash<Key> key_hash;
        return key_hash(key);
    }
    
public:
    // 构造函数
    HashTable(int M = 7) {
        this->M = M;
        size = 0;
        hashTable = new AVLTree<Key, Value>*[M];  // 分配内存
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new AVLTree<Key, Value>();  // 初始化每个槽位
        }
    }
    
    // 析构函数
    ~HashTable() {
        for (int i = 0; i < M; ++i) {
            delete hashTable[i];  // 释放每个AVL树
        }
        delete[] hashTable;  // 释放哈希表数组
    }
    
    int getSize() {
        return size;
    }
    
    // 添加键值对
    void add(Key key, Value value) {
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if (avlTree->contains(key)) {
            avlTree->set(key, value);
        } else {
            avlTree->add(key, value);
            size++;
            
            if (size >= M * upperTol) {
                resize(2 * M);
            }
        }
    }
    
    // 删除键值对
    Value* remove(Key key) {
        Value *ret = nullptr;
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if (avlTree->contains(key)) {
            ret = avlTree->remove(key);
            size--;
            
            if (size < M * lowerTol && M / 2 >= initialCapacity) {
                resize(M / 2);
            }
        }
        return ret;
    }
    
    // 判断哈希表中是否包含键
    bool contains(Key key) {
        return hashTable[hash(key)]->contains(key);
    }
    
    // 获取值
    Value get(Key key) {
        return hashTable[hash(key)]->get(key);
    }
    
    // 设置值
    void set(Key key, Value value) {
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if (!avlTree->contains(key)) {
            throw key + " doesn't exist";
        }
        avlTree->set(key, value);
    }
    
    // 调整哈希表大小
    void resize(int newM) {
        AVLTree<Key, Value> **newHashTable = new AVLTree<Key, Value>*[newM];  // 分配新的哈希表
        for (int i = 0; i < newM; i++) {
            newHashTable[i] = new AVLTree<Key, Value>();  // 初始化每个槽位
        }
        
        int oldM = M;
        M = newM;
        
        // 迁移旧的哈希表数据到新的哈希表
        for (int i = 0; i < oldM; i++) {
            AVLTree<Key, Value>* avlTree = hashTable[i];
            for (Key key : avlTree->keySet()) {
                newHashTable[hash(key)]->add(key, avlTree->get(key));
            }
            delete avlTree;  // 释放旧的AVL树内存
        }
        
        delete[] hashTable;  // 释放旧的哈希表数组内存
        hashTable = newHashTable;  // 将新的哈希表赋值给 hashTable
    }
};

int main() {
    vector<string> words;
    HashTable<string, int>* hashTable = new HashTable<string, int>();
    
    if (FileOps::readFile("pride-and-prejudice.txt", words)) {
        cout << "Total words: " << words.size() << endl;
        clock_t startTime = clock();
        
        // 向哈希表中添加单词及其频率
        for (string word : words) {
            if (hashTable->contains(word)) {
                hashTable->set(word, hashTable->get(word) + 1);
            } else {
                hashTable->add(word, 1);
            }
        }
        
        clock_t endTime = clock();
        cout << "HashTable: " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    
    AVLTree<string, int>* avl = new AVLTree<string, int>();
    vector<string> words3;
    
    if (FileOps::readFile("pride-and-prejudice.txt", words3)) {
        cout << "Total words: " << words3.size() << endl;
        clock_t startTime = clock();
        
        // 向 AVL 树中添加单词及其频率
        for (string word : words3) {
            if (avl->contains(word)) {
                avl->set(word, avl->get(word) + 1);
            } else {
                avl->add(word, 1);
            }
        }
        
        clock_t endTime = clock();
        cout << "AVLTree: " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    
    return 0;
}
