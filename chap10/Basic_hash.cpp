#include <iostream>
#include <string>
using namespace std;

int main() {
    hash<int> hash_int;
    hash<double> hash_double;
    hash<float> hash_float;
    hash<string> hash_string;
    int a = 42;
    cout << hash_int(a) << endl;
    int b = -42;
    cout << hash_int(b) << endl;

    double c = 3.1415926;
    float c2 = 3.1415926;
    cout << hash_double(c) << endl;
    cout << hash_float(c2) << endl;

    string d = "usts";
    cout << hash_string(d) << endl;
    cout << hash_string("USTS") <<endl;

    return 0;
}
