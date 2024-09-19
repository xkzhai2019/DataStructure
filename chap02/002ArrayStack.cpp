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

    ArrayStack<char> charStack;
    string s = "{[]}[]())";
    //string s = "{[]}[]()";
    cout<<s.length()<<endl;
    cout<<s[1]<<endl;
    bool flag = true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            charStack.push(s[i]);
        }else{
            if(charStack.isEmpty()){
                flag = false;
                break;
            }
            char tc = charStack.pop();
            if(tc=='(' && s[i]!=')'){
                flag = false;
                break;
            }
            if(tc=='{' && s[i]!='}'){
                flag = false;
                break;
            }
            if(tc=='[' && s[i]!=']'){
                flag = false;
                break;
            }
        }
    }
    if(charStack.isEmpty()==false){
        flag = false;
    }
    if(flag) 
        cout<<"合法字符串"<<endl;
    else
        cout<<"非法字符串"<<endl;
    return 0;
}
