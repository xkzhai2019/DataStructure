//#include <cstdio>
#include <iostream>
//using namespace std;
int main(void){
    int a;
    float b;
    char c;
    //printf("请输入一个整数、浮点数和字符:\n");
    std::cout<<"请输入一个整数、浮点数和字符"<<"\n";
    //scanf("%d %f %c",&a,&b,&c);
    std::cin>>a>>b>>c;
    //printf("你输入了:\n");
    std::cout<<"你输入了："<<"\n";//<<endl
    //printf("%d %.2f %c\n",a,b,c);
    std::cout<<a<<" "<<b<<" "<<c<<std::endl;

    return 0;
}
