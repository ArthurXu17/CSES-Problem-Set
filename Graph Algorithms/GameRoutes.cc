#include <bits/stdc++.h>

using namespace std;

vector<int> top;
vector<bool> visited;
vector<vector<int>> g;
int n;

void dfs(int u) {
    visited[u] = true;
    for (auto & v : g[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    top.push_back(u);
}

void topSort() {
    //top = vector<int>();
    visited = vector<bool>(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(top.begin(), top.end());

}

int main() {
    const int mod = 1e9 + 7;
    int m, a, b;
    cin >> n >> m;
    g = vector<vector<int>>(n+1, vector<int>());
    vector<vector<int>> rg(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    topSort();
    //cout<<top.size()<<endl;
    //for (auto & t : top){
    //    cout<<t<<" ";
    //}
    //cout<<endl;

    vector<int> dp(n+1, 0);
    auto it = top.begin();
    while (it != top.end()) {
        if (*it == 1) {
            break;
        }
        it++;
    }
    dp[1] = 1;
    while (it != top.end()) {
        int u = *it;
        for (auto & v : rg[u]) {
            dp[u] += dp[v];
            dp[u] %= mod;
        }
        it++;
    }
    //for (int i = 1; i <= n; i++) {
    //    cout<<dp[i]<<" ";
    //}
    //cout<<endl;
    cout<<dp[n]<<'\n';

    

}