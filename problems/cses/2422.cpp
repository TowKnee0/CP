#include <bits/stdc++.h>

using namespace std;

int n;

long long num_leq(long long x) {
    long long ans = 0;
    for (long long i = 1; i <= min(x, (long long)n); i++) {
        ans += min((long long)floor(x/i), (long long)n);
    }
    return ans;
}


int main() {
    cin >> n;

    long long low = 1;
    long long high = (long long)n* (long long)n;
    long long mid;
    long long nleq;
    long long median = ceil((long double)n * (long double)n / (long double)2);

    while (low < high) {
        mid = (low + high) / 2;
        nleq = num_leq(mid);

        if (nleq < median) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << (low + high) / 2 << endl;
}

