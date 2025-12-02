#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int ans = 0;
    int curr = 50;
    string a;
    int sign;
    int val;
    int mod;
    int prev;

    while (cin >> a) {
        if (a[0] == 'L') {
            sign = -1;
        } else {
            sign = 1;
        }

        val = stoi(a.substr(1));

        ans += abs(val /100);
        mod = (curr + sign * val) % 100;
        curr = (mod < 0) ? (mod + 100) : mod;

        if (sign == -1 && curr > prev && prev != 0) {
            ans++;
        }  else if (sign == 1 && curr < prev && curr != 0) {
            ans++;
        }

        if (curr == 0) {
            ans ++;
        }
        prev = curr;
    }
    cout << ans;
}