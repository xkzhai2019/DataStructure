#include <iostream>
#include "BSTMap.h"
#include "PriorityQueue.h"

using namespace std;

class Freq{
public:
    int key;
    int freq;
    Freq(int key = 0, int freq = 0){
        this->key = key;
        this->freq = freq;
    }
    bool operator<(const Freq &another) {
        if (this->freq < another.freq) {
            return false;
        } else {
            return true;
        }
    }

    bool operator>(const Freq &another) {
        if (this->freq > another.freq) {
            return false;
        } else {
            return true;
        }
    }
    /*
    bool operator>=(const Freq &another) {
        if (this->freq > another.freq) {
            return false;
        } else {
            return true;
        }
    }
    */
};

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        BSTMap<int,int> *map = new BSTMap<int, int>();
        
        for (int i = 0; i < nums.size(); ++i) {
             if(map->contains(nums[i])){
                map->set(nums[i],map->get(nums[i])+1);
             }else{
                map->set(nums[i],1);
             }
        }
        PriorityQueue<Freq> *pq = new PriorityQueue<Freq>();
        vector<int> keys = map->keySet();
        for(int i=0; i< keys.size();++i){
            if(pq->getLength()<k){
                pq->enqueue(Freq(keys[i],map->get(keys[i])));
            }else if(map->get(keys[i]) > pq->getFront().freq){
                pq->dequeue();
                pq->enqueue(Freq(keys[i],map->get(keys[i])));
            }
        }
        vector<int> res;
        while (!pq->isEmpty()) {
            res.push_back(pq->dequeue().key);
        }
        return res;
    }

};

int main(){
    return 0;
}
