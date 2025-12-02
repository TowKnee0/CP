#include <iostream>
#include <string>


using namespace std;

int main() {
    int ans = 0;
    int curr = 50;
    string a;
    int sign;

    while (cin >> a) {
        if (a[0] == 'L') {
            sign = -1;
        } else {
            sign = 1;
        }

        curr = (curr + sign * stoi(a.substr(1))) % 100;
        if (curr == 0) {
            ans++;
        }
    }
    cout << ans;
}