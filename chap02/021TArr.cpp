#include <iostream>
using namespace std;
#define Size 10
template<class T> // 模版头
class TArr{
    private:
        T *data; // 使用数组指针，指向一个名为data的长度不定的数组
        int length;// 记录当前数组的长度
        int size; // 给数组分配的最大存储容量
        void resize(int newSize); // 扩容函数
    public:
        int getLength();
        int getSize();
        T getData(int index) noexcept(false); // C++11及以上
        bool setData(int index,T elem);//返回值代表是否修改成功
        void print();
        
        //带参构造函数
        TArr(int size);
        // 无参构造函数
        TArr();
        void addLast(T elem);
        void addbyIndex(int index,T elem);
        void addFirst(T elem);
        T removeLast() noexcept(false); // 一般删除时，要返回删除的值，因此有可能抛异常
        T removebyIndex(int index) noexcept(false);
        T removeFirst() noexcept(false);                
        int findElem(T elem); // 查找元素，返回下标
        bool contains(T elem); // 判断数组中是否有该元素
};

template<class T>// 模版头
TArr<T>::TArr(){
    data = new T[Size];
    length = 0;
    size = Size;
}
template<class T>// 模版头
TArr<T>::TArr(int size){
    data = new T[size];
    length = 0;
    this->size = size;
}
template<class T>// 模版头
void TArr<T>::print(){
    cout<<"当前动态数组的最大容量为"<<size<<"，现有元素为："<<endl;
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";   
    }
    cout<<endl;
}
template<class T>// 模版头
int TArr<T>::getSize(){
    return size;
}
template<class T>// 模版头
int TArr<T>::getLength(){
    return length;
}
template<class T>// 模版头
T TArr<T>::getData(int index) noexcept(false){
    if(index<0 || index>=length){
        cout<<"索引非法，无法获取值：";
        throw "illegal index error";
    }
    return data[index];
}
template<class T>// 模版头
bool TArr<T>::setData(int index,T elem){
    if(index<0 || index>=length){
        cout<<"索引不合法，无法修改"<<endl;
        return false;
    }
    data[index] = elem;
    cout<<"修改成功"<<endl;
    return true;
}

template<class T>// 模版头
void TArr<T>::resize(int newSize){
    T *newData = new T[newSize];
    for(int i=0;i<length;i++){
        newData[i] = data[i];
    }
    data = newData;
}
template<class T>// 模版头
void TArr<T>::addLast(T elem){
    if(length==size){// 数组已满
        size = 2 * size;
        resize(size);
    }
    data[length] = elem;
    length++;
}
template<class T>// 模版头
void TArr<T>::addbyIndex(int index,T elem){
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
template<class T>// 模版头
void TArr<T>::addFirst(T elem){
    addbyIndex(0,elem);
}

template<class T>// 模版头
T TArr<T>::removeLast() noexcept(false){
    if(length==0){
        cout<<"当前数组为空，不可删除：";
        throw "EmptyArr Error";
    }
    T ret = data[length-1];
    length--;
    if(length <= size/4){
        size = size/2;
        resize(size);
    }
    return ret;
}

template<class T>// 模版头
T TArr<T>::removebyIndex(int index) noexcept(false){
    if(index<0 || index>=length){
        cout<<"索引非法，不可删除:";
        throw "illegal index error";
    }
    T ret = data[index];
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

template<class T>// 模版头
T TArr<T>::removeFirst() noexcept(false){
        return removebyIndex(0);
}
template<class T>// 模版头
int TArr<T>::findElem(T elem){
    if(length==0){
        return -1;
    }
    for(int i=0;i<length;i++){
        if(elem==data[i])
            return i;
    }
    return -1;
}
template<class T>// 模版头
bool TArr<T>::contains(T elem){
    if(length==0){
        return false;
    }
    for(int i=0;i<length;i++){
        if(elem==data[i])
            return true;
    }
    return false;
}

int main(void){
    TArr<float> myArr(5);
    myArr.print();
    try{
        cout<<"尝试删除空数组最后一个元素:"<<endl;
        float ret = myArr.removeLast();
        cout<<"最后一个元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    for(int i=0;i<40;i++){
        if(i%2==0)
            myArr.addLast(i+0.1);
        else
            myArr.addFirst(i+0.1);
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
    cout<<"修改-1处元素为20.24："<<endl;
    myArr.setData(-1,20.24);
    cout<<"修改1处元素为20.24："<<endl;
    myArr.setData(1,20.24);

    try{
        cout<<"尝试删除最后一个元素:"<<endl;
        float ret = myArr.removeLast();
        cout<<"最后一个元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();
    try{
        cout<<"尝试删除-1处元素:"<<endl;
        float ret = myArr.removebyIndex(-1);
        cout<<"-1处元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();
    try{
        cout<<"尝试删除头部元素:"<<endl;
        float ret = myArr.removeFirst();
        cout<<"头部元素为"<<ret<<endl;
    }catch(const char* msg){
        cout<<msg<<endl;
    }
    myArr.print();

    cout<<"查找100在数组中的位置："<<myArr.findElem(100.24)<<endl;
    cout<<"数组中是否包含元素10："<<myArr.contains(20.24)<<endl;

}
