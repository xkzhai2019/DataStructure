#include <iostream> 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int arr[], int len){
        this->val = arr[0];
        this->next = nullptr;
        ListNode *cur = this;
        for(int i=1;i<len;i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }
    void print(){
        ListNode *cur = this;
        while(cur!=nullptr){
            std::cout<<cur->val<<"->";
            cur = cur->next;
        }
        std::cout<<"NULL"<<std::endl;
    }
};

class Solution { // 如何在代码层面测试递归程序的正确性
public:
    ListNode* removeElements(ListNode* head, int val, int depth) {
        print(depth);
        std::cout<<"Remove " << val << " in ";
        head->print();

        if(head==nullptr){
            print(depth);
            std::cout<<"Return: ";
            head->print();
            return head;
        }

        ListNode* res = removeElements(head->next,val,depth+1);
        print(depth);
        std::cout<<"After remove "<< val << " in " ;
        head->print();
        ListNode *ret;
        if(head->val == val){
            ret = res;
        }else{
            head->next = res;
            ret = head;
        }
        print(depth);
        std::cout<<"Return: ";
        ret->print();
        return ret;
    }
    void print(int depth){
        for(int i=0;i<depth;i++){
            std::cout<<"--";
        }
    }
};

int main(void){
    int nums[] = {1,2,6,3,4,5,6};
    ListNode *head = new ListNode(nums,7);
    head->print();
    ListNode *res = Solution().removeElements(head,6,0);
    res->print();
    return 0;
}
