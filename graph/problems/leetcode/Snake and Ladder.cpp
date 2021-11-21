//
// Created by admin on 20/11/2021.
//

//
// Created by admin on 20/11/2021.
//

void solve(int n, int m, vector<vector<int>> edges, int s, vector<int>& v, vector<bool>& vis){
    int i = 0;
    vis[s] = true;
    v[s] = 0;
    queue<int> q;
    q.push(s);
    int dis = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        dis = v[p]+ 1;
        //dis++ is wrong
        for(int t:edges[p]){
            if(vis[t] == false){
                v[t] = dis;

                vis[t] = true;
                q.push(t);
            }
        }
    }
}
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> v(n+ 1, -1);
    vector<bool> vis(n+ 1, false);
    vector<vector<int>>adj(n+ 1);
    int i = 0;
    while(m--){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        i++;

    }
    solve(n, m, adj, s, v, vis);
    vector<int>ans;
    for(int i = 1; i<=n; i++){

        if(v[i] == -1)
            ans.push_back(-1);
        else if(v[i] != 0 && v[i] != -1){
            v[i] = 6*v[i];
            ans.push_back(v[i]);
        }
    }
    return ans;
}