#include <iostream>
#include <string>
using namespace std;

void cal_nextval(string T, int *nextval){
    int i=1,k=0;
    nextval[1] = 0;
    while(i<T.size()){
        if(k==0 || T[i-1]==T[k-1]){
            ++i;
            ++k;
            if(T[i-1]!=T[k-1]){
                nextval[i] = k;
            }else{
                nextval[i] = nextval[k];
            }
        }else{
            k = nextval[k];
        }
    }
}

int Index_KMPImproved(string S,string T){
    int i = 1, j = 1;
    int nextval[T.size()+1];
    cal_nextval(T,nextval);
    for(int i=1;i<=T.size();i++){
        cout<<nextval[i]<<endl;
    }
    while(i<=S.size() && j<=T.size()){
        if(j == 0 || S[i-1] == T[j-1]){// 若相等，继续比较后续字符
            i++;
            j++; 
        }else{
            j = nextval[j];
        }
    }
    if(j>T.size()){ //j 来到了T的末端
        return i - T.size();
    }
    return 0;
}


int main(){
    //int no = Index_KMPImproved("ababcabcacbab","abcac");
    int no = Index_KMPImproved("aaaabcdefefafefa","ababaaababaa");
    cout<<no<<endl;
    return 0;
}
