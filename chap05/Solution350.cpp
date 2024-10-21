class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        BSTMap<int,int> *map1 = new BSTMap<int,int>();

        for(int num: nums1){
            if(map1->contains(num)){
                map1->set(num,map1->get(num)+1);
            }else{
                map1->add(num,1);
            }
        }
        vector<int> list;
        for(int num: nums2){
            if(map1->contains(num)){
                list.push_vack(num);
                map1.set(num,map1.get(num)-1);
                if(map1->get(num)==0){
                    map1->remove(num);
                }
            }
        }
        return list;
    }
};
