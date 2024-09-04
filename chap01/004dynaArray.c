#include <stdio.h>
#include <stdlib.h>
#define Size 10
typedef struct MyArray{
    int *data; // 使用数组指针，指向一个名为data的长度不定的数组
    int length;// 记录当前数组的长度
    int size; // 给数组分配的最大存储容量
}intArr;
intArr myArr;

intArr initArr(){
    myArr.data = (int *)malloc(Size*sizeof(int));// 动态申请存储空间
    myArr.length = 0; // 数组长度初始化为0
    myArr.size = Size; // 数组存储空间初始化为Size
    return myArr;
}

void printArr(intArr myArr){
    printf("当前动态数组最大容量为%d,现有元素为：\n",myArr.size);
    for(int i=0;i<myArr.length;i++){
        printf("%d ",myArr.data[i]);
    }
    printf("\n");
}
// 从数组末端插入元素elem
intArr addLast(intArr myArr,int elem){
    if(myArr.length==myArr.size){
        //printf("数组空间已满，无法插入新元素!\n");
        //return myArr;
        myArr.size *= 2;
        myArr.data = (int *)realloc(myArr.data,myArr.size*sizeof(int));
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
        //printf("数组空间已满，无法插入新元素!\n");
        //return myArr;
        myArr.size *= 2;
        myArr.data = (int *)realloc(myArr.data,myArr.size*sizeof(int));
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
// 查找元素，返回元素所在下标
int findEle(intArr myArr, int ele){
    for(int i=0;i<myArr.length;i++){
        if(myArr.data[i]==ele){
            return i;
        }
    }
    return -1;
}
// 删除末尾元素
intArr removeLast(intArr myArr){
    if(myArr.length==0){
        printf("数组为空，无法删除!\n");
        return myArr;
    }
    myArr.length--;
    if(myArr.length<=myArr.size/2){
        myArr.size /= 2;
        myArr.data = (int *)realloc(myArr.data,myArr.size*sizeof(int));
    }
    return myArr;
}
// 删除指定位置的元素
intArr removebyIndex(intArr myArr, int index){
    if(myArr.length==0){
        printf("数组为空，无法删除!\n");
        return myArr;
    }
    if(index<0 || index>=myArr.length){
        printf("元素位置不合法，无法删除!\n");
        return myArr;
    }
    for(int i=index;i<myArr.length-1;i++){
        myArr.data[i] = myArr.data[i+1];
    }
    myArr.length--;
    if(myArr.length<=myArr.size/2){
        myArr.size /= 2;
        myArr.data = (int *)realloc(myArr.data,myArr.size*sizeof(int));
    }
    return myArr;
}
// 删除指定元素
intArr removeEle(intArr myArr, int ele){
    int index = findEle(myArr,ele);
    if(index==-1){
        printf("数组不存在该元素，无法删除！\n");
        return myArr;
    }
    return removebyIndex(myArr, index);
}
// 删除数组头部元素
intArr removeFirst(intArr myArr){
    if(myArr.length==0){
        printf("数组为空，无法删除!\n");
        return myArr;
    }
    int ele = myArr.data[0];
    return removeEle(myArr,ele);
}
// 修改数组中指定位置的元素
intArr updateEle(intArr myArr, int index, int elem){
    if(index<0 || index>=myArr.length){
        printf("指定位置不合规!\n");
        return myArr;
    }
    myArr.data[index] = elem;
    return myArr;
}
// 判断某元素是否在数组中
int contains(intArr myArr, int elem){
    int index = findEle(myArr, elem);
    if(index==-1){
        return 0;
    }
    return 1;
}

// 获取某指定位置的元素值
int getElembyIndex(intArr myArr, int index){
    if(index<0 || index>=myArr.length){
        printf("指定位置不合规!\n");
        exit(0);
    }
    return myArr.data[index];
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
    // 插入元素测试
    printf("=====插入元素测试=======\n");
    printf("末尾插入20：\n");
    myArr = addLast(myArr,20);
    printArr(myArr);
    printf("在索引-1处插入20: \n");
    myArr = addbyIndex(myArr,20,-1);
    printArr(myArr);
    printf("在索引1处插入20：\n");
    myArr = addbyIndex(myArr,20,1);
    printArr(myArr);
    printf("在索引length+1处插入20：\n");
    myArr = addbyIndex(myArr,20,myArr.length+1);
    printArr(myArr);
    printf("开头插入20：\n");
    myArr = addFirst(myArr,20);
    printArr(myArr);
    // 删除元素测试
    printf("=====删除元素测试=======\n");
    printf("删除最后两个元素:\n");
    myArr = removeLast(myArr);
    myArr = removeLast(myArr);
    printArr(myArr);
    printf("删除开头元素:\n");
    myArr = removeFirst(myArr);
    printArr(myArr);
    printf("开头插入元素:\n");
    myArr = addFirst(myArr,200);
    printArr(myArr);
    printf("删除元素2:\n");
    myArr = removeEle(myArr,2);
    printArr(myArr);
    return 0;
}
