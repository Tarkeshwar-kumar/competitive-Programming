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
ll mpow(ll a, ll n,ll p){ a%=p; ll res=1; while(n>0){ if(n&1LL)res=res*a%p; a=a*a%p; n>>=1; } return res; }
ll mul(ll a, ll b){ return ((a%mod)* (b%mod)) % mod;}
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
    vector<int> color(V+ 1, -1);
    for(int i = 1; i<=V; i++){
        if(color[i] == -1)
            if(!(isBipartiteUtil(i, adj,color, 0)))
                return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    int i = 1;
    while(t--){
        cout<<"Scenario #"<<i<<":\n";
        int V, n;   cin>>V>>n;
        vector<int> adj[V+ 1];
        while(n--){
            int u, v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool ans = isBipartite(V, adj);
        if(ans)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
        i++;
    }
}