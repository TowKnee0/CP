#include <bits/stdc++.h>

using namespace std;

int n, q, t, x, k;
map<int, vector<int>> vals;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> t;
        vals[t].push_back(i);
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        if (vals[x].size() > k-1) {
            cout << vals[x][k-1] + 1<< endl;
        } else {
            cout << -1 << endl;
        }
    }
}