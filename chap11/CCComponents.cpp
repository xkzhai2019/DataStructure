#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;
class CCByDFS{
    private:
        Graph *g;
        int *visited;
        int cccount = 0;

        void dfs(int v,int ccid){
            visited[v] = ccid;
            for(int w: g->adj_V(v)){
                if(visited[w]==-1){
                    dfs(w,ccid);
                }
            }
        }
    public:
        CCByDFS(Graph *g){
            this->g = g;
            visited = new int[g->getV()];
            for(int i=0;i<g->getV();i++){
                visited[i] = -1;
            }
            for(int v=0;v < g->getV(); v++){
                if(visited[v]==-1){
                    dfs(v,cccount);
                    cccount++;
                }
            }
        }
        int count(){
            return cccount;
        }
        bool isConnected(int v, int w){
            g->validateVertex(v);
            g->validateVertex(w);
            return visited[v]==visited[w];
        }
        vector<vector<int>> components(){
            vector<vector<int>> ret(cccount);

            for(int v=0;v<g->getV();v++){
                ret[visited[v]].push_back(v);
            }
            return ret;
        }
};

int main(){
    Graph *g = new Graph("gDFS.txt");
    //Graph *g = new Graph("gDFS2CC.txt");
    g->print();
    CCByDFS *cc = new CCByDFS(g);
    vector<vector<int>> comp = cc->components();
    for(int ccid=0; ccid<comp.size(); ccid++){
        cout<<ccid<<": ";
        for(int w: comp[ccid]){
            cout<<w<<" ";
        }
        cout<<endl;
    }
    cout<<cc->isConnected(1,5);
    return 0;
}
