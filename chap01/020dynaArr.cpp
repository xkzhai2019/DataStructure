#include <iostream>
//#include <cassert>
//#include <cstdlib>
using namespace std;
#define Size 10
struct intArr{
    private:
        int *data; // 使用数组指针，指向一个名为data的长度不定的数组
        int length;// 记录当前数组的长度
        int size; // 给数组分配的最大存储容量
        void resize(int newSize); // 扩容函数
    public:
        int getLength();
        int getSize();
        int getData(int index) throw(const char *);
        bool setData(int index,int elem);//返回值代表是否修改成功
        void print();
        
        //带参构造函数
        intArr(int size);
        // 无参构造函数
        intArr();
        void addLast(int elem);
        void addbyIndex(int index,int elem);
        void addFirst(int elem);
        int removeLast();
        int removebyIndex(int index);
        int removeFirst();
                
};

intArr::intArr(){
    data = new int[Size];
    length = 0;
    size = Size;
}
intArr::intArr(int size){
    data = new int[size];
    length = 0;
    this->size = size;
}
void intArr::print(){
    cout<<"当前动态数组的最大容量为"<<size<<"，现有元素为："<<endl;
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";   
    }
    cout<<endl;
}
int intArr::getSize(){
    return size;
}
int intArr::getLength(){
    return length;
}
int intArr::getData(int index) throw(const char*){
    /*
    if(index<0 || index>=length){
        cout<<"索引非法，无法获取元素"<<endl;
        exit(0); //会直接终止程序
    }
    */
    // 断言,同样会终止程序
    //assert(index>=0);
    //assert(index<length);
    if(index<0 || index>=length){
        throw "illegal index error";
    }
    return data[index];
}
bool intArr::setData(int index,int elem){
    if(index<0 || index>=length){
        cout<<"索引不合法，无法修改"<<endl;
        return false;
    }
    data[index] = elem;
    cout<<"修改成功"<<endl;
    return true;
}

void intArr::resize(int newSize){
    int *newData = new int[newSize];
    for(int i=0;i<length;i++){
        newData[i] = data[i];
    }
    data = newData;
}
void intArr::addLast(int elem){
    if(length==size){// 数组已满
        /*
        size = 2*size;
        int *newData = new int[size];
        for(int i=0;i<length;i++){
            newData[i] = data[i];
        }
        data = newData;
        */
        size = 2 * size;
        resize(size);
    }
    data[length] = elem;
    length++;
}
void intArr::addbyIndex(int index,int elem){
    if(length==size){
        size = 2*size;
        resize(size);
    }
    if(index<0 || index>length){
        cout<<"插入位置不合法！\n";
        return;
    }
    for(int i=length-1;i>=index;i--){
        data[i+1] = data[i];
    }
    data[index] = elem;
    length++;
}
void intArr::addFirst(int elem){
    addbyIndex(0,elem);
}

int intArr::removeLast(){
    /*
    if(length==0){
        cout<<"当前数组为空，不可删除！"<<endl;
    }
    */
//    assert(length>0);
    if(length==0){
        throw "EmptyArr Error";
    }

    int ret = data[length-1];
    length--;
    return ret;
}

int main(void){
    //intArr myArr; // 创建对象
    //myArr.print();
    intArr myArr(5);
    myArr.print();
    cout<<"尝试删除最后一个元素:"<<endl;
    try{
        int ret = myArr.removeLast();
        cout<<"最后一个元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    for(int i=0;i<40;i++){
        if(i%2==0)
            myArr.addLast(i);
        else
            myArr.addFirst(i);
        myArr.print();
    }
    try{
        cout<<"获取-1处元素："<<endl;
        cout<<myArr.getData(-1)<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    try{
        cout<<"获取1处元素："<<endl;
        cout<<myArr.getData(1)<<endl; 
    
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    cout<<"修改-1处元素为20："<<endl;
    myArr.setData(-1,20);
    cout<<"修改1处元素为20："<<endl;
    myArr.setData(1,20);

    cout<<"尝试删除最后一个元素:"<<endl;
    try{
        int ret = myArr.removeLast();
        cout<<"最后一个元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();
}
/*
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
*/
