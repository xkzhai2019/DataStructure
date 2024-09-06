#include <iostream>
using namespace std;
struct Student{
    private:
        char *m_name;
        int m_age;
        float m_score;
    public:
        void say();//在类内部对成员函数做声明
        void setAge(int age);
        void setName(char *name);
        void setScore(float score);
        int getAge();
        float getScore();
        char *getName();
};
void Student::say(){ //在类外部对成员函数进行定义
    cout<<"我的名字是"<<m_name<<endl;
    cout<<"我今年"<<m_age<<"岁"<<endl;
    cout<<"我高考考了"<<m_score<<"分"<<endl;
}

void Student::setAge(int age){
    m_age = age;
}
void Student::setName(char *name){
    m_name = name;
}
void Student::setScore(float score){
    m_score = score;
}
char* Student::getName(){
    return m_name;
}
int Student::getAge(){
    return m_age;
}
float Student::getScore(){
    return m_score;
}

int main(void){
    Student stu1;
    stu1.setName("小明");
    stu1.setAge(20);
    stu1.setScore(568);
    stu1.say();
    cout<<"Name: "<<stu1.getName()<<endl;
    cout<<"Age: "<<stu1.getAge()<<endl;
    cout<<"Score: "<<stu1.getScore()<<endl;

    return 0;
}
