#include <iostream>
#include <string>
using namespace std;

void cal_next(string T, int *next){
    int i=1,k=0;
    next[1] = 0;
    next[2] = 1;
    while(i<T.size()){
        if(k==0 || T[i-1]==T[k-1]){
            ++i;
            ++k;
            next[i] = k;
        }else{
            k = next[k];
        }
    }
}

int Index_KMP(string S,string T){
    int i = 1, j = 1;
    int next[T.size()+1];
    cal_next(T,next);
    for(int i=1;i<=T.size();i++){
        cout<<next[i]<<endl;
    }
    while(i<=S.size() && j<=T.size()){
        if(j == 0 || S[i-1] == T[j-1]){// 若相等，继续比较后续字符
            i++;
            j++; 
        }else{
            j = next[j];
        }
    }
    if(j>T.size()){ //j 来到了T的末端
        return i - T.size();
    }
    return 0;
}


int main(){
    int no = Index_KMP("ababcabcacbab","abcac");
    cout<<no<<endl;
    return 0;
}
