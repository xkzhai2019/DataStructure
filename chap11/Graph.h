#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AVLSet.h"
using namespace std;

class Graph{
    private:
        int V;
        int E;
        AVLSet<int> **adj;
    public:
        Graph(string filename){
            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                adj = new AVLSet<int>*[V];
                
                for(int i=0;i<V;i++){
                    adj[i] = new AVLSet<int>();
                }
                
                inFile >> E;
                int a,b;
                for(int i = 0; i < E; i++){
                    inFile >> a >> b;
                    validateVertex(a);
                    validateVertex(b);
                    if(a==b){
                        throw "self loop is detected";
                    }
                    if(adj[a]->contains(b)){
                        throw "parallel edges are detected";
                    }

                    adj[a]->add(b);
                    adj[b]->add(a);
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
            AVLSet<int>* avlSet = adj[v];
            return avlSet->allElement();
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
