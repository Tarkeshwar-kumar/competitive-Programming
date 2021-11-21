//
// Created by admin on 20/11/2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define pi pair<int, int>
#define vi vector<int>
#define vc vector<char>
#define MAX 1e9 + 7
#define len 100000
#define rep(i,a,b) for (int i = a; i < b; i++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const ll P2LIM = (ll)2e18;
const int mod = 1e9+ 7;
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
inline int gcd( int a, int b)
{
    return b?gcd(b,a%b):a;
}
int64_t power(int64_t x, int64_t y)
{
    ll result = 1;
    while (y > 0) {
        if (y % 2 == 0)
        {
            x = ((x%mod) * x)%mod;
            y = y / 2;
        }
        else
        {
            result = ((result%mod) * x)%mod;
            y = y - 1;
        }
    }
    return result%mod;
}
void bfs(vector<vector<int>>& adj, vector<int>& vis, int s){
    vis[s] = true;
    for(int x:adj[s]){
        if(vis[x] == false)
            bfs(adj, vis, x);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+ 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n+ 1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (vis[i] == false) {
            ans++;
            bfs(adj, vis, i);
        }
    }
    cout<<ans;
    return 0;
}