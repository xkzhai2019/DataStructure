#ifndef TARR_H
#define TARR_H
#include <iostream>
using namespace std;

template<typename T> // 模版头
class TArr{
    private:
        T *data; // 使用数组指针，指向一个名为data的长度不定的数组
        int length;// 记录当前数组的长度
        int size; // 给数组分配的最大存储容量
        void resize(int newSize){
            T *newData = new T[newSize];
            for(int i=0;i<length;i++){
                newData[i] = data[i];
            }
            data = newData;
        }
    public:
        int getLength(){
            return length;
        }
        int getSize(){
            return size;
        }
        T getData(int index) noexcept(false){
            if(index<0 || index>=length){
                cout<<"索引非法，无法获取值：";
                throw "illegal index error";
            }
            return data[index];
        }
        T getLast() noexcept(false){
            return getData(length-1);
        }
        bool setData(int index,T elem){
            if(index<0 || index>=length){
                cout<<"索引不合法，无法修改"<<endl;
                return false;
            }
            data[index] = elem;
            cout<<"修改成功"<<endl;
            return true;
        }
        void print(){
            for(int i=0;i<length;i++){
                cout<<data[i]<<" ";   
            }
        }
        
        //带参构造函数
        TArr(int size){
            data = new T[size];
            length = 0;
            this->size = size;
        }
        TArr(){ // 无参构造默认申请容量为10的空间
            data = new T[10];
            length = 0;
            size = 10;
        }
        void addLast(T elem){
            if(length==size){// 数组已满
                size = 2 * size;
                resize(size);
            }
            data[length] = elem;
            length++;
        }
        void addbyIndex(int index,T elem){
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
        void addFirst(T elem){
            addbyIndex(0,elem);
        }
        T removeLast() noexcept(false){
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
        T removebyIndex(int index) noexcept(false){
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
        T removeFirst() noexcept(false){
                return removebyIndex(0);
        }
        int findElem(T elem){
            if(length==0){
                return -1;
            }
            for(int i=0;i<length;i++){
                if(elem==data[i])
                    return i;
            }
            return -1;
        }
        bool contains(T elem){
            if(length==0){
                return false;
            }
            for(int i=0;i<length;i++){
                if(elem==data[i])
                    return true;
            }
            return false;
        }
        bool isEmpty(){ // 判断数组是否为空
            return length==0;
        }
};
#endif
