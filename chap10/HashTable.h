#include "AVLTree.h"
#include "FileOperation.h"

template<typename Key, typename Value>
class HashTable {
private:
    int M; // 取模的那个素数，表的长度
    int size; // 表中存储数据的个数
    AVLTree<Key, Value> **hashTable;

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
        hashTable = new AVLTree<Key, Value>* [M];
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new AVLTree<Key, Value>();
        }
    }

    HashTable() {
        this->M = 97;
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
        }
    }

    Value* remove(Key key) {
        Value *ret = nullptr;
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if(avlTree->contains(key)){
            ret = avlTree->remove(key);
            size--;
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
};
