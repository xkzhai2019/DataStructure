#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AVLSet.h"
using namespace std;

class AdjAVLSet{
    private:
        int V;
        int E;
        AVLSet<int> **adj;
    public:
        AdjAVLSet(string filename){
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

        AVLSet<int>* adj_V(int v){
            validateVertex(v);
            return adj[v];
        }

        int degree(int v){
            return adj_V(v)->getSize(); 
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

int main(){
    AdjAVLSet *adjSet = new AdjAVLSet("g.txt");
    adjSet->print();
    cout<<adjSet->degree(0);
    return 0;
}
