#include <bits/stdc++.h>

using namespace std;

int n, x, t;
map<int, vector<int>> vals;

int main() {
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> t;
        auto it = vals.find(x - t);
        if (it != vals.end()) {
            cout << i+1 << " " << it->second[0]+1;
            return 0;
        }

        vals[t].push_back(i);
    }
    cout << "IMPOSSIBLE";
}