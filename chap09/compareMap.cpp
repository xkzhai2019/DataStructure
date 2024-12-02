#include "BSTMap.h"
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

template<typename T>
double testData(T *map, vector<int> &dataes) {
    clock_t startTime = clock();
    for (int data : dataes) {
        if (map->contains(data)) {
            map->set(data, map->get(data) + 1);
        } else {
            map->add(data, 1);
        }
    }

    for (int data: dataes) {
        map->contains(data);
    }

    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
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

    int n = 20000000;
    vector<int> testDataes;
    vector<int> testDataes2;
    for(int i = 0; i < n; ++i){
        testDataes.push_back(rand() % INT64_MAX);
        testDataes2.push_back(i);
    }
    
    /*
    BSTMap<int,int> *bstMap2 = new BSTMap<int,int>();
    double time4 = testData(bstMap2,testDataes2);
    cout<<"BST Map: "<<time4<<" s "<<endl;
    */
    AVLMap<int,int> *avlMap2 = new AVLMap<int,int>();
    double time5 = testData(avlMap2,testDataes);
    cout<<"AVL Map: "<<time5<<" s "<<endl;
    RBTree<int,int> *rbTree2 = new RBTree<int,int>();
    double time6 = testData(rbTree2,testDataes);
    cout<<"RBTree: "<<time6<<" s "<<endl;
    
    return 0;
}
