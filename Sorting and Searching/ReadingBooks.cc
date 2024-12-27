#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, a;
    ll sum = 0;
    int maxBook = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        maxBook = max(maxBook, a);
    }
    cout<<max((ll)2*maxBook,sum)<<endl;
}