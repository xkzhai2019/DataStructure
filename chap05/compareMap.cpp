#include "BSTMap.h"
#include "LinkedListMap.h"
#include <iostream>
#include <vector>
#include "FileOperation.h"
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
        cout << "Total different words: " << map->getSize() << endl;
        cout << "Frequency of PRIDE: " << map->get("pride") << endl;
        cout << "Frequency of PREJUDICE: " << map->get("prejudice") << endl;
    }
    clock_t endTime = clock();
    return (endTime - startTime)/CLOCKS_PER_SEC;
}

int main(){
    cout<< "傲慢与偏见"<<endl;
    string filename = "pride-and-prejudice.txt";
    BSTMap<string,int> *bstMap = new BSTMap<string,int>();
    double time1 = testMap(bstMap,filename);
    cout<<"BST Map: "<<time1<<" s "<<endl;
    LinkedListMap<string,int> *listMap = new LinkedListMap<string,int>();
    double time2 = testMap(listMap,filename);
    cout<<"LinkedList Map: "<<time2<<" s "<<endl;
    return 0;
}
