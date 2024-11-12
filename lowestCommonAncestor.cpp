#include <bits/stdc++.h>

using namespace std;

vector<int> height, euler, first, segtree;
vector<bool> visited;
int n;

void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
        if (!visited[to]) {
            dfs(adj, to, h + 1);
            euler.push_back(node);
        }
    }
}

void build(int ind, int b, int e) { //range minimum query
    if (b == e) {
        segtree[ind] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(ind << 1, b, mid);
        build(ind << 1 | 1, mid + 1, e);
        int l = segtree[ind << 1], r = segtree[ind << 1 | 1];
        segtree[ind] = (height[l] < height[r]) ? l : r;
    }
}

int query(int ind, int b, int e, int L, int R) {
    if (b > R || e < L)
        return -1;
    if (b >= L && e <= R)
        return segtree[ind];
    int mid = (b + e) >> 1;

    int left = query(ind << 1, b, mid, L, R);
    int right = query(ind << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
}

int lca(int u, int v) {
    int left = first[u], right = first[v];
    cout<<left<<" "<<right<<endl;
    if (left > right)
        swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
}

int main() {
    // ... (rest of your main function code)

    // Example usage:
    int node,ed;
    cin>>node>>ed;
    vector<vector<int>> adj(node+1);
    for(int i=0;i<ed;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int root = 1;

    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);

    dfs(adj, root);

    int m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1);

    int u = 2, v = 4;
    int ancestor = lca(u, v);
    cout << "LCA of " << u << " and " << v << " is: " << ancestor << endl;

    return 0;
}