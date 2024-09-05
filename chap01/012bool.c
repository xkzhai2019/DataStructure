#include <stdio.h>

int isPrime(int n){
    int flag=1; // 1表示是素数
    if(n<=1){
        return 0; // 0表示不是素数
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0) flag=0;
    }
    return flag;
}

// 计算1-100之间所有素数的和
int main(void){
    int sum = 0;
    for(int i=1;i<=100;i++){
        if(isPrime(i)==1){
            printf("%d\n",i);
            sum += i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
