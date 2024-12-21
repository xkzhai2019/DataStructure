#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AVLMap.h"
using namespace std;

class WeightedGraph{
    private:
        int V;
        int E;
        AVLMap<int,int> **adj;
    public:
        WeightedGraph(string filename){
            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                adj = new AVLMap<int,int>*[V];
                
                for(int i=0;i<V;i++){
                    adj[i] = new AVLMap<int,int>();
                }
                
                inFile >> E;
                int a,b,weight;
                for(int i = 0; i < E; i++){
                    inFile >> a >> b >> weight;
                    validateVertex(a);
                    validateVertex(b);
                    if(a==b){
                        throw "self loop is detected";
                    }
                    if(adj[a]->contains(b)){
                        throw "parallel edges are detected";
                    }

                    adj[a]->add(b,weight);
                    adj[b]->add(a,weight);
                }
                inFile.close();
            }else{
                cout<<"no this file"<<endl;
            }
        }
        bool hasEdge(int v,int w){
            validateVertex(v);
            validateVertex(w);
            return adj[v]->contains(w);
        }

        vector<int> adj_V(int v){
            validateVertex(v);
            AVLMap<int,int>* avlMap = adj[v];
            return avlMap->keySet();
        }

        int degree(int v){
            return adj_V(v).size(); 
        }
        int getV(){
            return V;
        }
        int getE(){
            return E;
        }
        int getWeight(int v, int w){
            if(hasEdge(v,w)){
                return adj[v]->get(w);
            }
            throw "no edge";
        }

        void validateVertex(int v){
            if(v<0 || v>=V){
                throw "vertex invalid";
            }
        }
        void print(){
            cout<<"V="<<V<<",E="<<E<<endl;
            for(int i=0;i<V;i++){
                cout<<i<<": ";
                adj[i]->print();
                cout<<endl;
            }
        }
};

int main(){
    WeightedGraph *g = new WeightedGraph("WeightedG.txt");
    g->print();
    return 0;
}
