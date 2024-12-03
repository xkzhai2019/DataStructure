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
            hash<std::string> hash_string;
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

        /*
        bool isequals(const Student &another){ 
        // 产生hash冲突时，还是需要判断两个对象
        //     
        }
        */
};

int main() {
    std::hash<int> hash_int;
    std::hash<double> hash_double;
    std::hash<std::string> hash_string;
    int a = 42;
    std::cout << hash_int(a) << std::endl;

    int b = -42;
    std::cout << hash_int(b) << std::endl;

    double c = 3.1415926;
    std::cout << hash_double(c) << std::endl;

    std::string d = "imooc";
    std::cout << hash_string(d) << std::endl;

//    std::cout << INT64_MAX + 1 << std::endl;

    
    Student student(3, 2, "Bobo", "Liu");
    std::cout << student.hashCode() << std::endl;

    Student student2(3, 2, "BObO", "LIU");
    std::cout << student2.hashCode() << std::endl;

//    std::cout << std::boolalpha << student.isequals(student2) << std::endl;


    return 0;
}
