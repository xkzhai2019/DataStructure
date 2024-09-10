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
        // int getData(int index) throw(const char *); //C++98/C++03
        int getData(int index) noexcept(false); // C++11及以上
        bool setData(int index,int elem);//返回值代表是否修改成功
        void print();
        
        //带参构造函数
        intArr(int size);
        // 无参构造函数
        intArr();
        void addLast(int elem);
        void addbyIndex(int index,int elem);
        void addFirst(int elem);
        int removeLast() noexcept(false); // 一般删除时，要返回删除的值，因此有可能抛异常
        int removebyIndex(int index) noexcept(false);
        int removeFirst() noexcept(false);                
        int findElem(int elem); // 查找元素，返回下标
        bool contains(int elem); // 判断数组中是否有该元素
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
//int intArr::getData(int index) throw(const char*){
int intArr::getData(int index) noexcept(false){
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
        cout<<"索引非法，无法获取值：";
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

int intArr::removeLast() noexcept(false){
    /*
    if(length==0){
        cout<<"当前数组为空，不可删除！"<<endl;
        exit(0);
    }
    */
    //    assert(length>0);
    if(length==0){
        cout<<"当前数组为空，不可删除：";
        throw "EmptyArr Error";
    }
    int ret = data[length-1];
    length--;
    if(length <= size/4){
        size = size/2;
        resize(size);
    }
    return ret;
}

int intArr::removebyIndex(int index) noexcept(false){
    if(index<0 || index>=length){
        cout<<"索引非法，不可删除:";
        throw "illegal index error";
    }
    int ret = data[index];
    for(int i=index;i<length-1;i++){
        data[i] = data[i+1];
    }
    length--;
    if(length <= size/4){
        size = size/2;
        resize(size);
    }
    return ret;
}

int intArr::removeFirst() noexcept(false){
        return removebyIndex(0);
}
/*
int intArr::removeFirst(){
        try{
            int ret = removebyIndex(0);
        }catch(const char *msg){
            cout<<msg<<endl;
        }
        return ret;
}
*/
int intArr::findElem(int elem){
    if(length==0){
        return -1;
    }
    for(int i=0;i<length;i++){
        if(elem==data[i])
            return i;
    }
    return -1;
}
bool intArr::contains(int elem){
    if(length==0){
        return false;
    }
    for(int i=0;i<length;i++){
        if(elem==data[i])
            return true;
    }
    return flase;
}

int main(void){
    //intArr myArr; // 创建对象
    //myArr.print();
    intArr myArr(5);
    myArr.print();
    try{
        cout<<"尝试删除空数组最后一个元素:"<<endl;
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

    try{
        cout<<"尝试删除最后一个元素:"<<endl;
        int ret = myArr.removeLast();
        cout<<"最后一个元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();
    try{
        cout<<"尝试删除-1处元素:"<<endl;
        int ret = myArr.removebyIndex(-1);
        cout<<"-1处元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();
    try{
        cout<<"尝试删除头部元素:"<<endl;
        int ret = myArr.removeFirst();
        cout<<"头部元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();

    cout<<"查找100在数组中的位置："<<myArr.findElem(100)<<endl;
    cout<<"数组中是否包含元素10："<<myArr.contains(10)<<endl;

}
