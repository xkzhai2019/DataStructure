#include "BSTMap.h"
#include "HashTable.h"
#include <iostream>
#include <vector>
#include "FileOperation.h"
#include "AVLMap.h"
#include "RBTree.h"
using namespace std;

template<typename T>
double testMap(T *map, string filename){
    clock_t startTime = clock();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        cout << "Total words: " << words.size() << endl;
        for (string word : words) {
            if (map->contains(word)) {
                map->set(word, map->get(word) + 1);
            } else {
                map->add(word, 1);
            }
        }
        for(string word: words){
            map->contains(word);
        }
       cout << "Total different words: " << map->getSize() << endl;
       cout << "Frequency of PRIDE: " << map->get("pride") << endl;
       cout << "Frequency of PREJUDICE: " << map->get("prejudice") << endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime)/CLOCKS_PER_SEC;
}

int main(){
    cout<< "傲慢与偏见"<<endl;
    string filename = "pride-and-prejudice.txt";
    
    BSTMap<string,int> *bstMap = new BSTMap<string,int>();
    double time1 = testMap(bstMap,filename);
    cout<<"BST Map: "<<time1<<" s "<<endl;
    
    AVLMap<string,int> *avlMap = new AVLMap<string,int>();
    double time2 = testMap(avlMap,filename);
    cout<<"AVL Map: "<<time2<<" s "<<endl;
    RBTree<string,int> *rbTree = new RBTree<string,int>();
    double time3 = testMap(rbTree,filename);
    cout<<"RBTree: "<<time3<<" s "<<endl;
    
    // 单独运行时，运行正常
    // 加入HashTable后，执行报错，原因未知
    HashTable<string,int> *hashTable = new HashTable<string,int>(193);
    double time4 = testMap(hashTable,filename);
    cout<<"hashTable: "<<time4<<" s "<<endl;

    return 0;
}
