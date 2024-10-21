#include "Set.h"
#include "BST.h"
#include "FileOperation.h"

template<typename T>
class BSTSet: public Set<T>{
    private:
        BST<T> *bst;
    public:
        BSTSet(){
            bst = new BST<T>();
        }
        void add(T e){
            bst->add(e);
        }
        void remove(T e){
            bst->remove(e);
        }
        bool contains(T e){
            return bst->contains(e);
        }
        int getSize(){
            return bst->getSize();
        }
        bool isEmpty(){
            return bst->isEmpty();
        }
};

int main(){
    std::cout<<"双城记"<<std::endl;
    vector<string> words;
    if(FileOps::readFile("a-tale-of-two-cities.txt",words)){
        std::cout<< "Total words: "<<words.size()<<std::endl;
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word: words){
            bstSet->add(word);
        }
        std::cout<< "Total different words: "<<bstSet->getSize()<<std::endl;
    }
    
    std::cout<<"傲慢与偏见"<<std::endl;
    vector<string> words2;
    
    if(FileOps::readFile("pride-and-prejudice.txt",words2)){
        std::cout<< "Total words: "<<words2.size()<<std::endl;
        BSTSet<string> *bstSet2 = new BSTSet<string>();
        for(string word: words2){
            bstSet2->add(word);
        }
        std::cout<< "Total different words: "<<bstSet2->getSize()<<std::endl;
    }
    return 0;
}
