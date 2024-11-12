#include <iostream>
#include <cstdlib>
#include <cstring>

int main(){
    char * a1 = new char[10];
    char * a2 = new char[10];
    strcpy(a1, "China");//将字符串"China"复制给a1
    strcpy(a2, "Beijing");
    int lengthA1 = strlen(a1);//a1串的长度
    int lengthA2 = strlen(a2);//a2串的长度
    //尝试将合并的串存储在 a1 中，如果 a1 空间不够，则用new重新申请
    if (lengthA1 < lengthA1 + lengthA2) {
        char *newA1 = new char[lengthA1+lengthA2+1];
        for(int i=0;i<lengthA1;i++){
            newA1[i] = a1[i];
        }
        a1 = newA1;
        newA1 = nullptr;
        delete []newA1;
    }
    for (int i = lengthA1; i < lengthA1 + lengthA2; i++) {
        a1[i] = a2[i - lengthA1];
    }
    
    //串的末尾要添加 \0，避免出错
    a1[lengthA1 + lengthA2] = '\0';
    std::cout<<a1<<std::endl;
    //用完动态数组要立即释放
    delete []a1;
    delete []a2;
    return 0;
}
