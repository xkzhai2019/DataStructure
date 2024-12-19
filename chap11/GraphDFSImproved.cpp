#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;
class GraphDFS{
    private:
        Graph *g;
        bool *visited;
        vector<int> preOrder;
        vector<int> postOrder;

        void dfs(int v){
            visited[v] = true;
            preOrder.push_back(v);
            for(int w: g->adj_V(v)){
                if(!visited[w]){
                    dfs(w);
                }
            }
            postOrder.push_back(v);
        }
    public:
        GraphDFS(Graph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            //dfs(0);
            for(int v=0;v < g->getV(); v++){
                if(!visited[v]){
                    dfs(v);
                }
            }
        }
        vector<int> pre(){
            return preOrder;
        }
        vector<int> post(){
            return postOrder;
        }
};

int main(){
    Graph *g = new Graph("gDFS2CC.txt");
    g->print();
    GraphDFS *gDFS = new GraphDFS(g);
    for(int v: gDFS->pre()){
        cout<<v<<" ";
    }
    cout<<endl;
    for(int v: gDFS->post()){
        cout<<v<<" ";
    }
    return 0;
}
