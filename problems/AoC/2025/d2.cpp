#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string a;

void p1() {
    stringstream ss(a);
    string b, c;
    long long low, high;
    long long ans = 0;


    while (getline(ss, b, ',')){
        int split = b.find('-');
        low = stoll(b.substr(0, split));
        high = stoll(b.substr(split+1));
        
        for (long long i = low; i <= high; i++) {
            c = to_string(i);
            if (c.length() % 2 != 0) {
                continue;
            }
            if (c.substr(0, c.length()/2) == c.substr(c.length()/2)) {
                ans += i;
            }
        }
    }
    cout << ans << "\n";
}

void p2() {
    stringstream ss(a);
    string b, c, d;
    long long low, high;
    long long ans = 0;
    bool broke;


    while (getline(ss, b, ',')){
        int split = b.find('-');
        low = stoll(b.substr(0, split));
        high = stoll(b.substr(split+1));
        
        for (long long i = low; i <= high; i++) {
            c = to_string(i);
            for (int l = 1; l <= c.length()/2; l++) {
                if (c.length() % l != 0) {
                    continue;
                }
                d = c.substr(0, l);
                broke = false;
                for (int j = 0; j < c.length(); j+= l) {
                    if (c.substr(j, l) != d) {
                        broke = true;
                        break;
                    }
                }
                if (!broke) {
                    ans+= i;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> a;
    p1();
    p2();
}

