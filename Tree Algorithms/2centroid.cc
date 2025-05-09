#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
vector<vector<int>> neighbours;
vector<int> subtreeSize;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    int size = 1;
    //cout<<"dfs node: "<<u<<'\n';
    for (auto & v : neighbours[u]) {
        if (!visited[v]) {
            dfs(v);
        }
        size += subtreeSize[v];
    }
    subtreeSize[u] = size;
}

void rootAtOne() {
    visited = vector<bool>(n+1,false);
    subtreeSize = vector<int>(n+1, 0);
    dfs(1);
}

int main() {
    cin >> n;
    neighbours = vector<vector<int>>(n+1, vector<int>());
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a>>b;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }

    /*
    Algorithm: 

    At cur, only one subtree can have > n/2 nodes. Move to the culprit (if it exists). 
    The subtree of cur (with culprit as root) has size <= n/2 (since subtree of cur union subtree of culprit is all the nodes of tree, so n total).
    Each of the neighbours of culprit have subtrees strictly smaller than the original subtree size of culprit. 

    Let S(u) denote the size of the maximum subtree when the tree is rooted at u
    S(culprit) < S(cur) is what line 3 above says
    So we have a decreasing sequence of vertices, we must eventually dip below n/2
    */

    rootAtOne();
    int cur = 1;
    while (true) {
        int curSubtreeSize = 1;
        int culprit = -1;
        for (auto & v : neighbours[cur]) {
            if (subtreeSize[v] <= n/2) {
                curSubtreeSize += subtreeSize[v];
            } else {
                culprit = v;
            }
        }
        if (culprit == -1) {
            // all subtrees have size <= n/2
            cout<<cur<<'\n';
            break;
        } else {
            // root at culprint instead
            subtreeSize[cur] = curSubtreeSize;
            cur = culprit;
        }
    }
}