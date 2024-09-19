#include <iostream>
using namespace std;

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
        T getLast() noexcept(false); // C++11及以上
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
        bool isEmpty(); // 判断数组是否为空
};

template<class T>// 模版头
bool TArr<T>::isEmpty(){
    return length==0;
}

template<class T>// 模版头
TArr<T>::TArr(){ // 无参构造默认申请容量为10的空间
    data = new T[10];
    length = 0;
    size = 10;
}
template<class T>// 模版头
TArr<T>::TArr(int size){
    data = new T[size];
    length = 0;
    this->size = size;
}
template<class T>// 模版头
void TArr<T>::print(){
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";   
    }
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
T TArr<T>::getLast() noexcept(false){
    return getData(length-1);
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
