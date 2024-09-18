#include <iostream>

using namespace std;

int fib(int n){
    return (n==1 || n==2) ? 1 : fib(n-1)+fib(n-2);
}

int main(void){
    cout<<"fib(7)="<<fib(7)<<endl;
	return 0;
}
