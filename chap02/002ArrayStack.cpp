#include "TArr.h"
#include "Stack.h"

template<typename T>
class ArrayStack: public Stack<T>{
    private:
        TArr<T> *myArr;
    public:
        ArrayStack(){
            myArr = new TArr<T>();
        }
        
        ArrayStack(int size){
            myArr = new TArr<T>(size);
        }

        void push(T elem){
            myArr->addLast(elem);
        }

        T pop(){
            return myArr->removeLast();
        }

        T peek(){
            return myArr->getLast();    
        }

        int getLength(){
            return myArr->getLength();            
        }

        bool isEmpty(){
            return myArr->isEmpty(); 
        }

        // 打印栈内所有元素
        void print() {
            std::cout << "ArrayStack: length = " << getLength() << ", Size = " << myArr->getSize() << std::endl;
            std::cout << "bottom ";
            myArr->print();
            std::cout << " top" << std::endl;
        }
};


int main(void){
    ArrayStack<int> myStack(10);
    for(int i=0;i<5;i++){
        myStack.push(i);
        myStack.print();
    }
    std::cout <<"top:" <<myStack.peek()<<endl;
    std::cout<<myStack.pop()<<std::endl;
    myStack.print();

    return 0;
}
