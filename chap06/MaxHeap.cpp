#include "TArr.h"

template<typename T>
class MaxHeap{
    private:
        TArr<T>* data;
        int parent(int index){
            if(index==0){
                throw "No parent";
            }
            return (index-1)/2;
        }
        int leftChild(int index){
            return 2*index + 1;
        }
        int rightChild(int index){
            return 2*index + 2;
        }
    public:
        MaxHeap(int size){
            data = new TArr<T>(size);
        }
        MaxHeap(){
            data = new TArr<T>();
        }
        int getLength(){
            return data->getLength();
        }
        bool isEmpty(){
            return data->isEmpty();
        }
};

int main(){
    return 0;
}
