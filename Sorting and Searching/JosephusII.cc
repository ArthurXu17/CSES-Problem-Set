#include <ext/pb_ds/assoc_container.hpp> 
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// Driver code
int main()
{
    int n, k;
    cin>>n>>k;
    if (n == 1) {
        cout<<"1"<<endl;
        return 0;
    } 
    ordered_set nums;
    for (int i = 1; i <= n; i++) {
        nums.insert(i);
    }
    int removeIndex = 0;
    while (nums.size() >= 1) {
        int curSize = nums.size();
        removeIndex = (removeIndex + k) % curSize;
        auto it = nums.find_by_order(removeIndex);
        cout<<*it<<" ";
        nums.erase(it);
    }
    cout<<endl;
	return 0;
}
