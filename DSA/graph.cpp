#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

// Adjacency list
class Graph {
    int V;
    list<int> *l;  // same as int *arr
    public:
        Graph(int sz){
            this->V = sz;
            l = new list<int> [V]; // same as arr = new int[V];
        }

        // undirected graph --  //O(V+E)
        void addEdge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void addDirectedEdge(int u, int v){
            l[u].push_back(v);
        }

        void printVertices(){
            for(int i=0;i<V;i++){
                cout << i << " : " << " ";
                for(int neibours : l[i]){
                    cout << neibours << " ";
                }
                cout << endl;
            }
        }

        // BFS Traversal : travel to immediate neighbours first --  //O(V+E)
        void bfs(){
            queue<int> q;
            vector<bool> vis(V,false);
            q.push(0);
            vis[0] = true;
            
            while(!q.empty()){
                int u = q.front();
                q.pop();
                cout << u << " ";
                for(int v : l[u]){  // v :- immediate neighbours
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    } 
                }
            }
            cout << endl;
        }

        // DFS :- keep going to 1st unvisited neighbours   -  //O(V+E)
        void dfsHelper(int u, vector<bool> & vis){  // u is like starting point or src vertices and v is like destination or ending point
            cout << u << " ";
            vis[u] = true;

            for(int v: l[u]){
                if(!vis[v]){
                    dfsHelper(v,vis);
                }
            }
        }
        void dfs(){
            vector<bool>vis(V,false);
            int u = 0;
            // --if there is not any disconnected graphs
            dfsHelper(u,vis);
            // --else
            // for(int i=0;i<V;i++){
            //     if(!vis[i]){
            //         dfsHelper(i,vis);
            //     }
            // }
        }

        // Detect a cycle in a undirected graph using DFS
        bool isCycleHelper(int src, int par, vector<int>&vis){ //O(V+E)
            vis[src] = true;
            list<int> neighbours = l[src];

            for(int v: neighbours){
                if(!vis[v]){
                    if(isCycleHelper(v,src,vis)) return true;
                }else if(v != par){
                    return true;
                }
            }
            return false;
        }
        bool isCycle(){
            vector<int> vis(V,false);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(isCycleHelper(i,-1,vis)) return true;
                }
            }
            return false;
        }

        // Detect a cycle in a undirected graph using BFS
        bool isCycleBFSHelper(int src, vector<int>&vis, int par){
            queue<pair<int,int>> q;
            q.push({src,par});
            vis[src] = true;
            while(!q.empty()){
                int u = q.front().first;
                int parU = q.front().second;
                cout << "parU--" << parU << endl; 
                q.pop();
                for(auto v:l[u]){
                    cout << "v--"<< v << " ";
                    if(!vis[v]){
                        vis[v] = true;
                        q.push({v,u});
                    }else if(v != parU){
                        return true;
                    }
                }
                
                cout << endl;
                
            }
            return false;
        }
        bool isCycleBFS(){
            vector<int>vis(V,false);

            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(isCycleBFSHelper(i,vis,-1)){
                        return true;
                    }
                }
            }
            return false;
        }
        
        // Detect a cycle in a directed graph using BFS

        bool helper(int src, vector<bool>&vis,vector<bool>&recPath){
            vis[src] = true;
            recPath[src] = true;
            for(int v : l[src]){
                if(!vis[v]){
                    if(helper(v,vis,recPath)) return true;
                }else if(recPath[v]) return true;
            }
            recPath[src] = false;
            return false;
        }

        bool isCycleDirected(){
            vector<bool>vis(V,false);
            vector<bool>recPath(V,false);
            for(int v=0 ; v<V; v++ ){
                if(!vis[v]){
                    if(helper(v,vis,recPath)) return true;
                }
            }
            return false;
        }
};

int main(){
    // Undirected Graph
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.addEdge(0,4);
    g.addEdge(4,5);

    // g.printVertices();
    // cout << "BFS : " ;
    // g.bfs();

    // cout << "DFS : " ;
    // g.dfs();

    // -----Detect a cycle in the graph using DFS
    // cout << endl;
    // cout << g.isCycle() << endl;

    // -----Detect a cycle in the graph using BFS
    // cout << endl;
    // cout << g.isCycleBFS() << endl;

    // -------------Directed Graph
    Graph gd(4);
    gd.addDirectedEdge(1,0);
    gd.addDirectedEdge(0,2);
    gd.addDirectedEdge(2,3);
    gd.addDirectedEdge(3,0);
    // g.addDirectedEdge(5,4);
    // g.addDirectedEdge(2,3);

    cout << gd.isCycleDirected() << endl;

    return 0;
}