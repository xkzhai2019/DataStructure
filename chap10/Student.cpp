#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student{
    private:
        int grade;
        int cls;
        string firstName;
        string lastName;
    public:
        Student(int grade, int cls, string firstName,string lastName){
            this->grade = grade;
            this->cls = cls;
            this->firstName = firstName;
            this->lastName = lastName;
        }

        int hashCode(){// 帮助计算hash函数的值
            hash<int> hash_int;
            hash<string> hash_string;
            transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
            transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
            int B = 31;
            int hash = 0;
            hash = hash * B + hash_int(grade);
            hash = hash * B + hash_int(cls);
            hash = hash * B + hash_string(firstName);
            hash = hash * B + hash_string(lastName);
            return hash;    
        }

        bool isequals(Student *another){ 
            bool flag  = (this->hashCode() == another->hashCode());
            if(flag==false){
                return flag;
            }else{// 有可能产生hash冲突，所以还是需要判断两个对象内容是否一致
                return this->grade == another->grade && 
                       this->cls == another->cls &&
                       this->firstName == another->firstName &&
                       this->lastName == another->lastName;
            }
        }
};

int main() {
    
    Student *student = new Student(3, 2, "Da", "Liu");
    cout << student->hashCode() << endl;

    Student *student2 = new Student(3, 2, "DA", "LIU");
    cout << student2->hashCode() << endl;
    cout << student->isequals(student2) << endl;

    return 0;
}
