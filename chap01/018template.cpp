#include <iostream>
using namespace std;

void Swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Swap(float *a,float *b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
}
void Swap(char *a,char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    //int a,b;
    //float a,b;
    char a,b;
    cin>>a>>b;
    cout<<"a:"<<a<<" "<<"b: "<<b<<endl;
    Swap(&a,&b);
    cout<<"a:"<<a<<" "<<"b: "<<b<<endl;
    return 0;
}
