#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void build(vector<int>& segTree, vector<int>& arr, int node, int nodel, int noder) {
    // leaves
    if (nodel == noder) {
        segTree[node] = arr[nodel];
    } else {
        int mid = (nodel + noder) / 2;
        build(segTree, arr, 2*node, nodel, mid);
        build(segTree, arr, 2*node + 1, mid + 1, noder);
        segTree[node] = min(segTree[2*node], segTree[2*node + 1]);
    }
}

int query(vector<int>& segTree, int node, int l, int r, int nodel, int noder) {
    if (l > r) {
        return INT_MAX;
    } else if (l == nodel && r == noder) {
        return segTree[node];
    } else {
        int mid = (nodel + noder) / 2;
        return min(query(segTree, 2*node, l, min(mid, r), nodel, mid),
                   query(segTree, 2*node + 1, max(mid + 1, l), r, mid + 1, noder));
    }
}

void update(vector<int>& segTree, int index, int newVal, int node, int nodel, int noder) {
    if (nodel == noder) {
        segTree[node] = newVal;
    } else {
        int mid = (nodel + noder) / 2;
        if (index <= mid) {
            update(segTree, index, newVal, 2*node, nodel, mid);
        } else {
            update(segTree, index, newVal, 2*node +  1, mid+1, noder);
        }
        segTree[node] = min(segTree[2*node], segTree[2*node + 1]);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    vector<int> segTree(4*n, INT_MAX);
    build(segTree, arr, 1, 0, n-1);
    int a, b, t, k, u;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> k >> u;
            k--;
            update(segTree, k, u, 1, 0, n-1);
        } else {
            cin>>a>>b;
            a--;
            b--;
            cout<<query(segTree, 1, a, b, 0, n-1)<<endl;
        }
        
    }
}