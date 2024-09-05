#include <iostream>
using namespace std;

bool isPrime(int n){
    bool flag=true; // true表示是素数
    if(n<=1){
        return false; // false表示不是素数
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0) flag=false;
    }
    return flag;
}

// 计算1-100之间所有素数的和
int main(void){
    int sum = 0;
    for(int i=1;i<=100;i++){
        if(isPrime(i)){
            cout<<i<<endl;
            sum += i;
        }
    }
    cout<<sum<<endl;
    return 0;
}
