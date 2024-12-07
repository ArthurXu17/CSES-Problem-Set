#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
    int n, m;
    cin >>n >> m;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    vector<int> indices(n+1, -1); // arr[i] is whether or not i has been seen yet or not
    int numBehind = 0;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (num != n && indices[num + 1] != -1) {
            numBehind++;
        }
        indices[num] = i;
    }

    for (int i = 0; i < m; i++) {
        /*
        cout<<"Num behind: "<<numBehind<<endl;
        for (int i = 1; i < indices.size(); i++) {
            cout<<indices[i]<<" ";
        }
        cout<<endl;*/
        int a,b;
        cin >> a >>b;
        a--;
        b--;
        if (a == b) {
            cout<<numBehind + 1<<endl;
            continue;
        }
        if (b < a) {
            swap(a,b);
        }
        int na = arr[a];
        int nb = arr[b];
        // na gets moved to index b (to the right)
        // check if na + 1 is initially right of na and if na gets moved to the right of na+1. If so numBehind++
        // check if na - 1 is intially right of na, if na gets moved so that na is right of na-1, numBehind-- 
        // nb gets moved to index a (to the left)
        // check if nb + 1 is initially to the left of nb and if nb gets moved to the left of nb+1. If so numBehind--
        // check if nb - 1 is intially  to the left of nb, if nb gets moved to the left of nb-1, numBehind++
        if (abs(na - nb) > 1) {
            // 1.
            if (na < n) {
                int bigNumIndex = indices[na+1];
                if (bigNumIndex > a && bigNumIndex < b) {
                    numBehind++;
                }
            } 
            // 2.
            if (na > 1) {
                int smallNumIndex = indices[na-1];
                if (smallNumIndex > a && smallNumIndex < b) {
                    numBehind--;
                }
            }

            // 3.
            if (nb < n) {
                int bigNumIndex = indices[nb+1];
                if (bigNumIndex > a && bigNumIndex < b) {
                    numBehind--;
                }
            }

            // 4.
            if (nb > 1) {
                int smallNumIndex = indices[nb-1];
                if (smallNumIndex > a && smallNumIndex < b) {
                    numBehind++;
                }
            }
        } else {
            if (na < nb) {
                numBehind++; 
                // still need to check na - 1 and nb + 1
                if (na > 1) {
                    int smallNumIndex = indices[na-1];
                    if (smallNumIndex > a && smallNumIndex < b) {
                        numBehind--;
                    }
                }
                if (nb < n) {
                    int bigNumIndex = indices[nb+1];
                    if (bigNumIndex > a && bigNumIndex < b) {
                        numBehind--;
                    }
                }
            } else {
                numBehind--;
                // need to check nb - 1 and na + 1
                if (na < n) {
                    int bigNumIndex = indices[na+1];
                    if (bigNumIndex > a && bigNumIndex < b) {
                        numBehind++;
                    }
                } 
                if (nb > 1) {
                    int smallNumIndex = indices[nb-1];
                    if (smallNumIndex > a && smallNumIndex < b) {
                        numBehind++;
                    }
                }
            }
            
        }
        
        cout<<numBehind + 1<<endl;
        //cout<<"na: "<<na<<", b: "<<b<<endl;
        //cout<<"nb: "<<nb<<", a: "<<a<<endl;
        indices[na] = b;
        indices[nb] = a;
        arr[a] = nb;
        arr[b] = na;
    }
    /*
    cout<<"Num behind: "<<numBehind<<endl;
    for (int i = 1; i < indices.size(); i++) {
        cout<<indices[i]<<" ";
    }
    cout<<endl;*/

}