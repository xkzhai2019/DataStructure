#include <stdio.h>

typedef struct MyArray{
    int *data; // 使用数组指针，指向一个名为data的长度不定的数组
    int length;// 记录当前数组的长度
}intArray;

int main(void){
    int arr[] = {1,2,3,4,5};
    intArray myArr;
    myArr.data = arr;
    myArr.length = sizeof(arr) / sizeof(int);

    for(int i=0;i<myArr.length;i++){
        //printf("%d ",*(myArr.data+i));
        printf("%d ",myArr.data[i]);
    }
    return 0;
}
