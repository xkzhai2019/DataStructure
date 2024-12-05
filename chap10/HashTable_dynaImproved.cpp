#include "AVLTree.h"
#include "FileOperation.h"
#include "BSTMap.h"

template<typename Key, typename Value>
class HashTable {
private:
    const int upperTol = 8;
    const int lowerTol = 2;
    int capacityIndex = 0;
    const int capacity[] = {53, 97, 193, 389, 769, 1543, 3079, 6151};

    int M; // 取模的那个素数，表的长度
    int size; // 表中存储数据的个数
    AVLTree<Key, Value> *hashTable[];

    int hash(Key key) {
        return (hashCode(key) & 0x7fffffff) % M;
    }

    int hashCode(Key key) {
        std::hash<Key> key_hash;
        return key_hash(key);
    }

public:

    HashTable() {
        this->M = capacity[capacityIndex];
        size = 0;
        *hashTable = new AVLTree<Key, Value>[M]{};
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

            if(size >= M*upperTol && capacityIndex + 1 < sizeof(capacity)/ sizeof(int)){
                capacityIndex++;
                resize(capacity[capacityIndex]);
            }
        }
    }
    Value* remove(Key key) {
        Value *ret = nullptr;
        AVLTree<Key, Value> *avlTree = hashTable[hash(key)];
        if(avlTree->contains(key)){
            ret = avlTree->remove(key);
            size--;

            if(size < M*lowerTol && capacityIndex - 1 >= 0){
                capacityIndex--;
                resize(capacity[capacityIndex]);
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
    void resize(int newM){
        AVLTree<Key, Value> *newHashTable[newM];
        for(int i = 0 ; i < newM ; i ++)
            newHashTable[i] = new AVLTree<Key,Value>();

        int oldM = M;
        this->M = newM;
        for(int i = 0 ; i < oldM ; i ++){
            AVLTree<Key, Value> *avlTree = hashTable[i];
            for(Key key: avlTree->keySet())
                newHashTable[this->hash(key)]->add(key, avlTree->get(key));
        }
        hashTable = newHashTable; 
    }
};

int main(){
    vector<string> words;
    HashTable<string,int> *hashTable = new HashTable<string,int>();
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
        
        for (string word : words) {
            hashTable->remove(word);
        }
        
        clock_t endTime = clock();
       // std::cout << "Total different words: " << hashTable->getSize() << std::endl;
       // std::cout << "Frequency of PRIDE: " << (hashTable->get("pride")) << std::endl;
       // std::cout << "Frequency of PREJUDICE: " << (hashTable->get("prejudice")) << std::endl;
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
        for (string word : words3) {
            avl->remove(word);
        }
        clock_t endTime = clock();
        // cout << "Total different words: " << avl->getSize() << endl;
        // cout << "Frequency of PRIDE: " << avl->get("pride") << endl;
        // cout << "Frequency of PREJUDICE: " << avl->get("prejudice") << endl;
        cout << "AVLTree: "<< double(endTime - startTime)/CLOCKS_PER_SEC << "s" <<endl;
    }
    return 0;
}
