#include <bits/stdc++.h>

using namespace std;

int n, q, a;
unordered_map<int, vector<int>> indexes;

int main(){
    cin >> n;

    for (int i = 1;i <= n; i++) {
        cin >> a;
        indexes[a].push_back(i);
    }

    cin >> q;

    int l, r, x;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> x;

        auto it1 = lower_bound(indexes[x].begin(), indexes[x].end(), l);
        auto it2 = upper_bound(indexes[x].begin(), indexes[x].end(), r);
        cout << distance(it1, it2) << endl;;
    }
}