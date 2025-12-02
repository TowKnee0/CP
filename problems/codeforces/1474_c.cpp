#include <bits/stdc++.h>

using namespace std;

int t, n, temp;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++ ) {
        cin >> n;
        multiset<int> vals;
        for (int j = 0; j < 2*n; j++) {
            cin >> temp;
            vals.insert(temp);
        }  

        bool possible = false;
        for (int k = 0; k < (2*n)-1; k++) {
            auto vals_cpy = vals;
            auto other_val = vals_cpy.begin();
            advance(other_val, k);
            
            int starting = *other_val + *prev(vals_cpy.end());
            int x = starting;
            vector<pair<int, int>> ops;
            while (vals_cpy.size() > 0) {
                int largest = *prev(vals_cpy.end());
                auto found = vals_cpy.find(x - largest);
                if (found != vals_cpy.end() && found != prev(vals_cpy.end())) {
                    ops.push_back(make_pair(largest, x-largest));

                    vals_cpy.erase(prev(vals_cpy.end()));
                    vals_cpy.erase(found);

                    x = largest;
                } else {
                    break;
                }
            }
            if (vals_cpy.size() == 0) {
                cout << "YES" << endl;
                cout << starting << endl;
                for (auto p: ops) {
                    cout << p.first << " " << p.second << endl;
                }
                possible = true;
                break;
            }
        }
        if (!possible) {
            cout << "NO" << endl;
        }
    }
}