#include <iostream>
using namespace std;
//class Student{
struct Student{
public:
    char *name;
    int age;
    float score;

    void say(){
        cout<<"我的名字是"<<name<<endl;
        cout<<"我今年"<<age<<"岁"<<endl;
        cout<<"我高考考了"<<score<<"分"<<endl;
    }
};


int main(void){
    Student stu1;
    stu1.name = "小米";
    stu1.age = 18;
    stu1.score = 588;
    stu1.say();
    return 0;
}
