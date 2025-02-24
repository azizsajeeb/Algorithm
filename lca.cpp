#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, l, timer;
vector<vector<int>> adj, up;
vector<int> tin, tout;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    
    if(tin[u]<tin[v])swap(u,v);
    /*or
 if(level[u]<level[v])swap(u,v);   
    */

    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    
    return up[u][0];
}
/*
If neither u nor v is an ancestor of the other,
 the function uses binary lifting to jump up
  the tree from u and v.
For each level i (starting from the highest power of 2 and going downwards),
 it checks if up[u][i] 
 (which stores the 2^i-th ancestor of node u) 
 is an ancestor of v. If it is not, it moves u to up[u][i]. 
 This process essentially brings u and v closer together by 
 removing their differing ancestors, step by step,
  until they meet at the same ancestor.
  After the loop, u will be the parent of both u and v at the same depth,
   and the function returns up[u][0],
   which is the lowest common ancestor of u and v.
*/

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n));
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vector<int>(l + 1));
    
    dfs(root, root);
}

int main() {
    cin >> n;
    adj.resize(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // Assuming 1-based input, converting to 0-based
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int root = 0;  // Assuming root is 0
    preprocess(root);
    
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // Convert to 0-based
        cout << lca(u, v) + 1 << endl;  // Convert back to 1-based output
    }
    
    return 0;
}
