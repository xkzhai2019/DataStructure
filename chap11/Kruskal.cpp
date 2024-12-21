#include "WeightedEdge.h"
#include "CycleDetection.h"
#include "WeightedGraph.h"
#include "Graph.h"
#include "CCWeightedG.h"
#include <iostream>
using namespace std;
class Kruskal{
    private:
        WeightedGraph *g;
        vector<WeightedEdge> mst;
    public:
        Kruskal(WeightedGraph *g){
            this->g = g;
            CCWeightedG *cc= new CCWeightedG(g);
            if(cc->count()>1) return;

            //Kruskal
            vector<WeightedEdge> edges;
            for(int v=0;v< g->getV();v++){
                for(int w: g->adj_V(v)){
                    if(v<w)
                        edges.push_back(WeightedEdge(v,w,g->getWeight(v,w)));
                }
            }
            std::sort(edges.begin(),edges.end());
            // 判断是否形成环
            Graph *tmpG = new Graph();
            for(WeightedEdge edge: edges){
                int v = edge.getV();
                int w = edge.getW();
                tmpG->addEdge(v,w);
                CycleDetection *cycle = new CycleDetection(tmpG);
                if(cycle->existCycle()){
                    tmpG->removeEdge(v,w);
                }else{
                    mst.push_back(edge);
                }
            }
        }
        vector<WeightedEdge> result(){
            return mst;
        }
};
int main(){
    WeightedGraph *g = new WeightedGraph("WeightedG.txt");
    g->print();
    CCWeightedG *cc = new CCWeightedG(g);
    cout<<cc->count();

    Kruskal *kruskal = new Kruskal(g);
    for(WeightedEdge edge: kruskal->result()){
        edge.print();
    }
    return 0;
}
