#include <bits/stdc++.h>

using namespace std;

long long t, k, x;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k >> x;

        long long low = 0;
        long long high = 2*k;
        long long mid;
        long long emotes;
        long long temp;

        while (low < high) {
            mid = (low + high) / 2;
            
            if (mid <= k) {
                emotes = mid * (mid + 1) / 2;
            } else {
                temp = 2 * k - 1 - mid;
                emotes = k * k - (temp * (temp + 1) / 2);
            }
            
            if (emotes < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        cout << min((low + high) / 2, 2*k-1) << endl;
    }

}