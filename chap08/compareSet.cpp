#include "BSTSet.h"
#include "LinkedListSet.h"
#include "AVLSet.h"
#include <iostream>
using namespace std;


template<typename T>
double testSet(T *set, string filename){
    clock_t startTime = clock();
    vector<string> words;
    if(FileOps::readFile(filename,words)){
        cout<< "Total words: "<<words.size()<<endl;
        for(string word: words){
            set->add(word);
        }
        cout<< "Total different words: "<<set->getSize()<<endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime)/CLOCKS_PER_SEC;
}

int main(){
    cout<< "双城记"<<endl;
    string filename = "a-tale-of-two-cities.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    double time1 = testSet(bstSet,filename);
    cout<<"BST Set: "<<time1<<" s "<<endl;

    LinkedListSet<string> *listSet = new LinkedListSet<string>();
    double time2 = testSet(listSet,filename);
    cout<<"LinkedList Set: "<<time2<<" s "<<endl;

    AVLSet<string> *avlSet = new AVLSet<string>();
    double time3 = testSet(avlSet,filename);
    cout<<"AVL Set: "<<time3<<" s "<<endl;
    return 0;
}
