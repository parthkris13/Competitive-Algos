#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX_N = 100000 + 5;

int V,E, dist[MAX_N];
vector<vector<int>> adj[MAX_N];
queue <int> Q;
int32_t main(){
    IOS;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    memset(dist, -1, sizeof dist);
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return 0;
}

