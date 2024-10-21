#include "Set.h"
#include "LinkedList.h"
#include "FileOperation.h"

template<typename T>
class LinkedListSet{
private:
    LinkedList<T> *list;
public:
    LinkedListSet(){
        list = new LinkedList<T>();
    }
    void add(T e){
        if(!list->contains(e)){
            list->addFirst(e);
        }
    }
    void remove(T e){
        list->removeEle(e);        
    }
    bool contains(T e){
        return list->contains(e);        
    }
    int getSize(){
        return list->getLength();
    }
    bool isEmpty(){
        return list->isEmpty();
    }
};

int main(){
    std::cout<<"双城记"<<std::endl;
    vector<string> words;
    if(FileOps::readFile("a-tale-of-two-cities.txt",words)){
        std::cout<< "Total words: "<<words.size()<<std::endl;
        LinkedListSet<string> *listSet = new LinkedListSet<string>();
        for(string word: words){
            listSet->add(word);
        }
        std::cout<< "Total different words: "<<listSet->getSize()<<std::endl;
    }
    
    std::cout<<"傲慢与偏见"<<std::endl;
    vector<string> words2;
    
    if(FileOps::readFile("pride-and-prejudice.txt",words2)){
        std::cout<< "Total words: "<<words2.size()<<std::endl;
        LinkedListSet<string> *listSet2 = new LinkedListSet<string>();
        for(string word: words2){
            listSet2->add(word);
        }
        std::cout<< "Total different words: "<<listSet2->getSize()<<std::endl;
    }
    return 0;
}
