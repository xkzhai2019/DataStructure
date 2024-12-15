#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class AdjMatrix{
    private:
        int V;
        int E;
        int** adj;
    public:
        AdjMatrix(string filename){
            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                adj = new int*[V];
                for(int i=0;i<V;i++){
                    adj[i] = new int[V];
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
                    if(adj[a][b]==1){
                        throw "parallel edges are detected";
                    }

                    adj[a][b] = 1;
                    adj[b][a] = 1;
                }
                inFile.close();
            }else{
                cout<<"no this file"<<endl;
            }
        }
        bool hasEdge(int v,int w){
            validateVertex(v);
            validateVertex(w);
            return adj[v][w]==1;
        }

        vector<int> adj_V(int v){
            validateVertex(v);
            vector<int> ret;
            for(int i=0;i<V;i++){
                if(adj[v][i] == 1){
                    ret.push_back(i);
                }
            }
            return ret;
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
                for(int j=0;j<V;j++){
                    cout<<adj[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    AdjMatrix *adjMatrix = new AdjMatrix("g.txt");
    adjMatrix->print();
    cout<<adjMatrix->degree(0);
    return 0;
}
