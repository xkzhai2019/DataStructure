#include <iostream>
using namespace std;

template<typename T> void Swap(T *a,T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    int a=10,b=20;
    cout<<"a:"<<a<<" "<<"b: "<<b<<endl;
    Swap(&a,&b);
    cout<<"a:"<<a<<" "<<"b: "<<b<<endl;
    float f1=10.1,f2=20.2;
    cout<<"f1:"<<f1<<" "<<"f2: "<<f2<<endl;
    Swap(&f1,&f2);
    cout<<"f1:"<<f1<<" "<<"f2: "<<f2<<endl;
    char c1='A',c2='B';
    cout<<"c1:"<<c1<<" "<<"c2: "<<c2<<endl;
    Swap(&c1,&c2);
    cout<<"c1:"<<c1<<" "<<"c2: "<<c2<<endl;

    return 0;
}
