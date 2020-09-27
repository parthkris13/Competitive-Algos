#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int M = 1e9 + 7, N = 1e6 + 5;
int parent[N], sz[N], vis[N];
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v){
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
 
int32_t main(){
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) make_set(i);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        union_sets(x, y);
    }
    for (int i = 1; i <= n; i++) vis[find_set(i)]++;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, vis[i]);
    cout << ans << endl;
}