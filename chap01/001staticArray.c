#include <stdio.h>
int main(){
    int n = 5;
    //int arr[n] = {1,2,3,4,5};
    int arr[n];

    // 数组元素的遍历访问
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    // 查询数组第2个元素是多少
    printf("%d\n",arr[1]);
    // 修改数组第2个元素
    arr[1] = 10;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
	return 0;
}
