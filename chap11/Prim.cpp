#include "WeightedEdge.h"
#include "WeightedGraph.h"
#include "CCWeightedG.h"
#include <iostream>
using namespace std;
class Prim{
    private:
        WeightedGraph *g;
        vector<WeightedEdge*> mst;
    public:
        Prim(WeightedGraph *g){
            this->g = g;
            CCWeightedG *cc= new CCWeightedG(g);
            if(cc->count()>1) return;

            //Prim
            bool *visited = new bool[g->getV()]{false};
            visited[0] = true;
            for(int i=1;i<g->getV();i++){
                WeightedEdge *minEdge = new WeightedEdge(-1,-1,10000);
                for(int v = 0; v < g->getV(); v++){
                    if(visited[v]){
                        for(int w: g->adj_V(v)){
                            if(!visited[w] && g->getWeight(v,w)<minEdge->getWeight()){
                                minEdge = new WeightedEdge(v,w,g->getWeight(v,w));
                            }
                        }
                    }
                }
                mst.push_back(minEdge);
                visited[minEdge->getV()] = true;
                visited[minEdge->getW()] = true;
            }
        }
        vector<WeightedEdge*> result(){
            return mst;
        }
};
int main(){
    WeightedGraph *g = new WeightedGraph("WeightedG.txt");
    g->print();
    CCWeightedG *cc = new CCWeightedG(g);
    cout<<cc->count()<<endl;

    Prim *prim = new Prim(g);
    for(WeightedEdge* edge: prim->result()){
        edge->print();
    }
    cout<<endl;
    return 0;
}
