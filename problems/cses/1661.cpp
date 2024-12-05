#include <bits/stdc++.h>

using namespace std;

int x, n, t, a, b;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    long ans = 0;
    cin >> x >>  n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i ++ ) {
        cin >> t;
        pq.push(t);
    }

    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a+b);
    }
    cout << ans;
}