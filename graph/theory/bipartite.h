// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isBipartiteUtil(int node, vector<int> adj[], vector<int>& color, int col){
        color[node] = col;
        for(auto x:adj[node]){
            if(color[x] == -1){
                if(!(isBipartiteUtil(x, adj, color, 1- col)))
                    return false;
            }
            else if(color[x] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(int V, vector<int>adj[]){
        // Code here
        vector<int> color(V, -1);
        for(int i = 0; i<V; i++){
            if(color[i] == -1)
                if(!(isBipartiteUtil(i, adj,color, 0)))
                    return false;
        }
        return true;
    }

};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if(ans)cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends