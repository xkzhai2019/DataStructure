#include "WeightedGraph.h"

using namespace std;
class CCWeightedG{
    private:
        WeightedGraph *g;
        bool *visited;
        int cccount = 0;

        void dfs(int v){
            visited[v] = true;
            for(int w: g->adj_V(v)){
                if(!visited[w]){
                    dfs(w);
                }
            }
        }
    public:
        CCWeightedG(WeightedGraph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            for(int v=0;v < g->getV(); v++){
                if(!visited[v]){
                    dfs(v);
                    cccount++;
                }
            }
        }
        int count(){
            return cccount;
        }
};
