#include <stdio.h>
#include <stdlib.h>
#define Size 80
typedef struct MyArray{
    int *data; // 使用数组指针，指向一个名为data的长度不定的数组
    int length;// 记录当前数组的长度
    int size; // 给数组分配的最大存储容量
}intArr;

intArr initArr(){
    intArr myArr;
    /*
    int arr[Size];
    myArr.data = arr;
    */
    myArr.data = (int *)malloc(Size*sizeof(int));// 动态申请存储空间
    myArr.length = 0; // 数组长度初始化为0
    myArr.size = Size; // 数组存储空间初始化为Size
    return myArr;
}

void printArr(intArr myArr){
    printf("动态数组中的元素为：\n");
    for(int i=0;i<myArr.length;i++){
        printf("%d ",myArr.data[i]);
    }
    printf("\n");
}
// 从数组末端插入元素elem
intArr addLast(intArr myArr,int elem){
    if(myArr.length==myArr.size){
        printf("数组空间已满，无法插入新元素!\n");
        return myArr;
    }
    myArr.data[myArr.length] = elem;
    myArr.length++;
    return myArr;
}
// 在数组index处插入elem
intArr addbyIndex(intArr myArr, int elem, int index){
    if(index>=myArr.length+1 || index< 0){
        printf("插入位置有问题!\n");
        return myArr;
    }
    if(myArr.length==myArr.size){
        printf("数组空间已满，无法插入新元素!\n");
        return myArr;
    }
    for(int i=myArr.length;i>index;i--){
        myArr.data[i] = myArr.data[i-1];
    }
    myArr.data[index] = elem;
    myArr.length++;
    return myArr;
}
// 在数组头部插入elem
intArr addFirst(intArr myArr,int elem){
    return addbyIndex(myArr,elem,0);
}
int main(void){
    
    intArr myArr = initArr();
    // 向动态数组中添加元素
    for(int i=0;i<10;i++){
    //for(int i=0;i<Size-10;i++){
        myArr.data[i] = i;
        myArr.length++;
    }
    printArr(myArr);
    myArr = addLast(myArr,20);
    printArr(myArr);
    myArr = addbyIndex(myArr,20,-1);
    printArr(myArr);
    myArr = addbyIndex(myArr,20,1);
    printArr(myArr);
    myArr = addbyIndex(myArr,20,myArr.length+1);
    printArr(myArr);
    myArr = addFirst(myArr,20);
    printArr(myArr);
    
    return 0;
}
