#include "LinkedList.h"
#include "Stack.h"

template<typename T>
class LinkedListStack: public Stack<T>{
    private:
        LinkedList<T> *list;
    public:
        LinkedListStack(){
            list = new LinkedList<T>();
        }
        int getLength(){
            return list->getLength();
        }
        bool isEmpty(){
            return list->isEmpty();
        }
        void push(T e){
            list->addFirst(e);
        }
        T pop(){
            return list->removeFirst();
        }
        T peek(){
            return list->getFirst();
        }

        // 打印栈内所有元素
        void print() {
            std::cout << "LinkedListStack: length = " << getLength() << std::endl;
            std::cout << "top ";
            list->print();
            std::cout << " bottom" << std::endl;
        }
};

int main(){
    using namespace std;
    LinkedListStack<int> myStack;
    for(int i=0;i<5;i++){
        myStack.push(i);
        myStack.print();
    }
    cout <<"top:" <<myStack.peek()<<endl;
    cout<<myStack.pop()<<endl;
    myStack.print();

    LinkedListStack<char> charStack;
    string s = "{}{}{}{}{}[(([[]]))]";
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
