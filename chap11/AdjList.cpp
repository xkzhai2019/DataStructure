#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

class AdjList{
    private:
        int V;
        int E;
        LinkedList<int> **adj;
    public:
        AdjList(string filename){
            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                *adj = new LinkedList<int>[V];
                /*
                for(int i=0;i<V;i++){
                    adj[i] = new LinkedList<int>();
                }
                */
                inFile >> E;
                int a,b;
                for(int i = 0; i < E; i++){
                    inFile >> a >> b;
                    validateVertex(a);
                    validateVertex(b);
                    if(a==b){
                        throw "self loop is detected";
                    }
                    if((*adj[a])->contains(b)){
                        throw "parallel edges are detected";
                    }

                    (*adj[a])->addFirst(b);
                    (*adj[b])->addFirst(a);
                }
                inFile.close();
            }else{
                cout<<"no this file"<<endl;
            }
        }
        bool hasEdge(int v,int w){
            validateVertex(v);
            validateVertex(w);
            return (*adj[v])->contains(w);
        }

        LinkedList<int>* adj_V(int v){
            validateVertex(v);
            return *adj[v];
        }

        int degree(int v){
            return adj_V(v)->getLength(); 
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
                (*adj[i])->print();
                cout<<endl;
            }
        }
};

int main(){
    AdjList *adjList = new AdjList("g.txt");
    adjList->print();
    cout<<adjList->degree(0);
    return 0;
}
