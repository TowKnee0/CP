#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    int ans = 0;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    while (cin >> a){
        cin >> b;
        pq1.push(a);
        pq2.push(b);
    }

    while (!pq1.empty()) {
        ans += abs(pq1.top() - pq2.top());
        pq1.pop();
        pq2.pop();
    }
    cout << ans;
}