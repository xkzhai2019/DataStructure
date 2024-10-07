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
 
class Solution { // 不考虑虚拟头节点
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=nullptr && head->val == val){
            ListNode* delNode = head;
            head = head->next;
            delNode->next = nullptr;
            delNode = nullptr;
            delete delNode;
        }
        if(head == nullptr){
            return head;
        }
        ListNode* prev = head;
        while(prev->next!=nullptr){
            if(prev->next->val == val){
                ListNode* delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
                delNode = nullptr;
                delete delNode;
            }else{
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return head;
    }
};

int main(void){
    int nums[] = {1,2,6,3,4,5,6};
    ListNode *head = new ListNode(nums,7);
    head->print();
    ListNode *res = Solution().removeElements(head,6);
    res->print();
    return 0;
}
