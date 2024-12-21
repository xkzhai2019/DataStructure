#include "WeightedEdge.h"
#include "WeightedGraph.h"
#include "CCWeightedG.h"
#include "PriorityQueue.h"
#include <iostream>
using namespace std;
class Prim{
    private:
        WeightedGraph *g;
        vector<WeightedEdge> mst;
    public:
        Prim(WeightedGraph *g){
            this->g = g;
            CCWeightedG *cc= new CCWeightedG(g);
            if(cc->count()>1) return;

            //Prim by PriorityQueue
            bool *visited = new bool[g->getV()]{false};
            visited[0] = true;
            PriorityQueue<WeightedEdge> *pq = new PriorityQueue<WeightedEdge>();
            for(int w: g->adj_V(0)){
                pq->enqueue(WeightedEdge(0,w,g->getWeight(0,w)));
            }
            while(!pq->isEmpty()){
                WeightedEdge minEdge = pq->dequeue();
                if(visited[minEdge.getV()] && visited[minEdge.getW()])
                    continue;

                 mst.push_back(minEdge);

                 int newv = visited[minEdge.getV()] ? minEdge.getW() : minEdge.getV();
                 visited[newv] = true;
                 for(int w: g->adj_V(newv)){
                     if(!visited[w]){
                         pq->enqueue(WeightedEdge(newv, w, g->getWeight(newv, w)));
                     }
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
    cout<<cc->count()<<endl;

    Prim *prim = new Prim(g);
    for(WeightedEdge edge: prim->result()){
        edge.print();
    }
    cout<<endl;
    return 0;
}
