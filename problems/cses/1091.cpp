#include <bits/stdc++.h>

using namespace std;

int n, m, t;
map<int, int> prices;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        prices[t] += 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        if (prices.size() == 0)  {
            cout << -1 << endl;
            continue;
        }
        auto it = prices.upper_bound(t);
        if (it == prices.begin()) {
            cout << -1 << endl;
            continue;
        }
        it--;
        cout << it->first << endl;
        it->second--;
        if (it->second == 0) {
            prices.erase(it);
        }
    }
}