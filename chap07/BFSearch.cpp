#include <iostream>
#include <string>
using namespace std;

int Index_BF(string S,string T){
    int i = 0, j = 0;
    while(i<S.size() && j<T.size()){
        if(S[i] == T[j]){// 若相等，继续比较后续字符
            i++;
            j++; 
        }else{
            i = i - j + 1; //S中的指针后退，重新匹配
            j = 0;
        }
    }
    if(j==T.size()){ //j 来到了T的末端
        return i - T.size() + 1;
    }
    // i == S.size()
    return 0;
}


int main(){
    string str = "hello";
    cout<<str.size()<<endl;
    int no = Index_BF("ababcabcacbab","abcac");
    cout<<no<<endl;
    return 0;
}
