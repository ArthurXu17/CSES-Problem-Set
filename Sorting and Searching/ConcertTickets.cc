#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >>n >> m;
    std::map<int, int> ticketPrices;
    vector<int> customerPrices;
    vector<int> result(m, -1);
    int input;
    for (int i = 0; i < n; i++) {
        cin>>input;
        if (ticketPrices.find(input) == ticketPrices.end()) {
            ticketPrices[input] = 1;
        } else {
            ticketPrices[input]++;
        }
    }   
    for (int i = 0; i < m; i++) {
        cin>>input;
        customerPrices.push_back(input);
    }
    
    for (auto & n : customerPrices) {
        auto firstElementGreater =ticketPrices.upper_bound(n);
        if (firstElementGreater == ticketPrices.begin()) {
            cout<<"-1"<<endl;
        } else {
            firstElementGreater--;
            pair<int, int> pair = *firstElementGreater;
            int price = pair.first;
            int count = pair.second;
            if (count == 1) {
                ticketPrices.erase(price);
            } else {
                ticketPrices[price]--;
            }
            cout<<price<<endl;
        }
    }
}