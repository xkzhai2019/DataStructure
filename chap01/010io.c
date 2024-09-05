#include <stdio.h>
int main(void){
    int a;
    float b;
    char c;
    printf("请输入一个整数、浮点数和字符:\n");
    scanf("%d %f %c",&a,&b,&c);
    printf("你输入了:\n");
    printf("%d %.2f %c\n",a,b,c);
    return 0;
}
