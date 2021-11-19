//
// Created by admin on 19/11/2021.
//

//bfs

/*
 *
 * the path found by breadth first search to any node is the shortest
 * path to that node, i.e the path that contains the smallest number
 * of edges in unweighted graphs.
 *
 * The algorithm works in O(n+m) time, where n is number of vertices and m
 * is the number of edges.
 *
 * The algorithm takes as input an unweighted graph and the id of the source
 * vertex s.
 * The input graph can be directed or undirected, it does not matter to the
 * algorithm.
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;

void bfs(){
    vector<vector<int>> adj;  // adjacency list representation
    int n; // number of nodes
    int s; // source vertex

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}
int main() {

}