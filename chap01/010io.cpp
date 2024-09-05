//#include <stdio.h>
//#include <string.h>
//#include <math.h>
#include <cstdio>
#include <cstring>
#include <cmath>
int main(void){
    int a;
    float b;
    char c;
    printf("请输入一个整数、浮点数和字符:\n");
    scanf("%d %f %c",&a,&b,&c);
    printf("你输入了:\n");
    printf("%d %.2f %c\n",a,b,c);

    char name[] = "usts";
    printf("%d\n",strlen(name));
    printf("%.2f\n",pow(a,2));
    return 0;
}
