#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;
class CCByDFS{
    private:
        Graph *g;
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
        CCByDFS(Graph *g){
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

int main(){
    //Graph *g = new Graph("gDFS.txt");
    Graph *g = new Graph("gDFS2CC.txt");
    g->print();
    CCByDFS *cc = new CCByDFS(g);
    cout<<cc->count();
    return 0;
}
