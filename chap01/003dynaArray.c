#include <stdio.h>
#include <stdlib.h>
#define Size 80
typedef struct{
    int *data; // 使用数组指针，指向一个名为data的长度不定的数组
    int length;// 记录当前数组的长度
}intArr;
intArr myArr;
int arr[Size];

intArr initArr(intArr myArr){
    myArr.data = arr;
    myArr.length = 0; // 数组长度初始化为0
    return myArr;
}

void printArr(intArr myArr){
    printf("当前动态数组中的元素个数为：%d，元素为：\n",myArr.length);
    for(int i=0;i<myArr.length;i++){
        printf("%d ",myArr.data[i]);
    }
    printf("\n");
}

// 从数组末端插入元素elem
intArr addLast(intArr myArr,int elem){
    if(myArr.length==Size){
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
    if(myArr.length==Size){
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
    
    myArr = initArr(myArr);
    // 向动态数组中添加元素
    for(int i=0;i<10;i++){
        myArr.data[i] = i;
        myArr.length++;
    }
    printArr(myArr);
    // 插入元素测试
    printf("=====插入元素测试=======\n");
    printf("在末尾插入元素20：\n");
    myArr = addLast(myArr,20);
    printArr(myArr);
    printf("在-1处插入元素20：\n");
    myArr = addbyIndex(myArr,20,-1);
    printArr(myArr);
    printf("在1处插入元素20：\n");
    myArr = addbyIndex(myArr,20,1);
    printArr(myArr);
    printf("在length+1处插入元素20：\n");
    myArr = addbyIndex(myArr,20,myArr.length+1);
    printArr(myArr);    
    printf("在开头插入元素20：\n");
    myArr = addFirst(myArr,20);
    printArr(myArr);
    // 删除元素测试
    printf("=====删除元素测试=======\n");
    printf("删除末尾元素：\n");
    myArr = removeLast(myArr);
    printArr(myArr);
    printf("删除开头元素：\n");
    myArr = removeFirst(myArr);
    printArr(myArr);
    printf("删除元素2：\n");
    myArr = removeEle(myArr,2);
    printArr(myArr);
    printf("删除元素100：\n");
    myArr = removeEle(myArr,100);
    printArr(myArr);
    // 修改元素测试
    printf("=====修改元素测试=======\n");
    printf("将索引2处元素换为200，索引3处元素换为300：\n");
    myArr = updateEle(myArr,2,200);
    myArr = updateEle(myArr,3,300);
    printArr(myArr);
    printf("将索引20处元素换为2000:\n");
    myArr = updateEle(myArr,20,2000);
    printArr(myArr);
    // 查询元素
    printf("数组中是否存在元素200: %d\n",contains(myArr,200));
    printf("索引100处的元素是: \n");
    printf("%d\n",getElembyIndex(myArr,100));
//    printf("%d\n",getElembyIndex(myArr,1));
    return 0;
}
