#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;
class GraphDFS{
    private:
        Graph *g;
        bool *visited;
        vector<int> Oder;
        void dfs(int v){
            visited[v] = true;
            Oder.push_back(v);
            for(int w: g->adj_V(v)){
                if(!visited[w]){
                    dfs(w);
                }
            }
        }
    public:
        GraphDFS(Graph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            dfs(0);
        }
        vector<int> order(){
            return Oder;
        }
};

int main(){
    //Graph *g = new Graph("gDFS.txt");
    Graph *g = new Graph("gDFS2CC.txt");
    g->print();
    GraphDFS *gDFS = new GraphDFS(g);
    for(int v: gDFS->order()){
        cout<<v<<" ";
    }
    return 0;
}
