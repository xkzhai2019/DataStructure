#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "LinkedListQueue.h"

using namespace std;
class GraphBFS{
    private:
        Graph *g;
        bool *visited;
        vector<int> Order;

        void bfs(int v){
            LinkedListQueue<int> *q = new LinkedListQueue<int>();
            q->enqueue(v);
            visited[v] = true;
            while(!q->isEmpty()){
                int s = q->dequeue();
                Order.push_back(s);
                for(int w: g->adj_V(s)){
                    if(!visited[w]){
                        q->enqueue(w);
                        visited[w] = true;
                    }
                }
            }
        }
    public:
        GraphBFS(Graph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            for(int v=0;v < g->getV(); v++){
                if(!visited[v]){
                    bfs(v);
                }
            }
        }
        vector<int> order(){
            return Order;
        }
};

int main(){
    Graph *g = new Graph("gBFS.txt");
    g->print();
    GraphBFS *gBFS = new GraphBFS(g);
    for(int v: gBFS->order()){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
