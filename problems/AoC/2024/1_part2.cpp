#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {

    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    int ans = 0;
    int occ;
    while (cin >> a) {
        cin >> b;
        m1[a] += 1;
        m2[b] += 1;
    }

    for (auto it = m1.begin(); it != m1.end(); it++) {
        auto found = m2.find(it->first);
        if (found != m2.end()) {
            occ = found->second;
        } else {
            occ = 0;
        }
        ans += it->first * it->second * occ;
    }
    
    cout << ans;
}