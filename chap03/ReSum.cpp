#include <iostream>
using namespace std;

int sum(int arr[], int l,int n){
    if(l==n) return 0;
    int x = sum(arr,l+1,n);
    int res = arr[l] + x;
    return res;
}

int sum(int arr[],int n){
    return sum(arr,0,n);
}

int main(void){
    int nums[] = {1,2,3,4,5,6,7,8};
    cout<<sum(nums,8)<<endl;
    return 0;
}
