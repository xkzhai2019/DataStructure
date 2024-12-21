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
        int getV(){
            return v;
        }
        int getW(){
            return w;
        }
        void print(){
            cout<<"("<<v<<"-"<<w<<": "<<weight<<")"<<endl;
        }
        bool operator<(const WeightedEdge &another) {
            if (this->weight < another.weight) {
                return true;
            } else {
                return false;
            }
        }

        bool operator>(const WeightedEdge &another) {
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
