

#ifdef DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (auto & x : a) {
        cin >> x;
    }
    set<ll> cur = {a[0]};
    for (int i = 1; i < n; i++) {
        set<ll> t = {a[i]};
        for (auto & s : cur) {
            t.insert(s + a[i]);
        }
        for (auto & s : t) {
            cur.insert(s);
        }
        dbg(cur);
    }
    cout<<cur.size()<<'\n';
    for (auto & s : cur) {
        cout<<s<<" ";
    }
    cout<<'\n';
}