#include <set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> *set1 = new set<int>();

        for(int num: nums1){
                set1->insert(num);
        }

        vector<int> list;
        for(int num: nums2){
            if(set1->contains(num)){
                list.push_back(num);
                set1->erase(num);
            }
        }
        return list;
    }
};
