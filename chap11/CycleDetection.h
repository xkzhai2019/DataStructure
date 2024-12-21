#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;
class CycleDetection{
    private:
        Graph *g;
        bool *visited;
        bool hasCycle = false;

        // 从顶点v开始，判断图中是否有环
        bool dfs(int v,int parent){
            visited[v] = true;
            for(int w: g->adj_V(v)){
                if(!visited[w]){
                    if(dfs(w,v)) return true;
                }else{
                    if(w!=parent)
                        return true;
                }
            }
            return false;
        }
    public:
        CycleDetection(Graph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            for(int v=0;v < g->getV(); v++){
                if(!visited[v]){
                    if(dfs(v,v)){
                        hasCycle=true;
                        break;
                    }
                }
            }
        }
        bool existCycle(){
            return hasCycle;
        }
};
