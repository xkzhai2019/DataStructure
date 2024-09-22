#include <iostream>
#include "ArrayStack.h"
#include "LinkedListStack.h"
#include "Stack.h"
using namespace std;
template<typename T>
double testStack(T *Stack, int opCount){
    clock_t startTime = clock(); //记录从程序启动到函数调用，占用的CPU时钟计时单元数
    srand(66);
    for(int i = 0; i < opCount; ++i){
        Stack->push(rand());
    }
    for(int j = 0; j < opCount; ++j){
        Stack->pop();
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;//一秒钟会有多少个时钟计时单元
}

int main(){
    int opCount = 100000;
    ArrayStack<int> *arrayStack = new ArrayStack<int>();
    cout<<"ArrayStack time: "<<testStack(arrayStack, opCount)<<" s"<<endl;
    LinkedListStack<int> *linkedListStack = new LinkedListStack<int>();
    cout<<"LinkedListStack time: "<<testStack(linkedListStack, opCount)<<" s"<<endl;

    return 0;
}
