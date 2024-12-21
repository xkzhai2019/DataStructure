#include <iostream>
using namespace std;

class WeightedEdge{
    private:
        int v,w,weight;
    public:
        WeightedEdge(int v, int w, int weight){
            this->v = v;
            this->w = w;
            this->weight = weight;
        }
        WeightedEdge(){
            v = -1;
            w = -1;
            weight = 10000;
        }
        int getV(){
            return v;
        }
        int getW(){
            return w;
        }
        int getWeight(){
            return weight;
        }
        void print(){
            cout<<"("<<v<<"-"<<w<<": "<<weight<<") ";
        }

        //bool operator<(const WeightedEdge &another) {
        bool operator>(const WeightedEdge &another) {
            if (this->weight < another.weight) {
                return true;
            } else {
                return false;
            }
        }

        //bool operator>(const WeightedEdge &another) {
        bool operator<(const WeightedEdge &another) {
            if (this->weight > another.weight) {
                return true;
            } else {
                return false;
            }
        }
        bool operator==(const WeightedEdge &another) {
            if (this->weight == another.weight) {
                return true;
            } else {
                return false;
            }
        }

};
