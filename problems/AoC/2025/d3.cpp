#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

string a;

void p1() {
    int ans = 0;
    int high, low;
    int tmp;
    while (cin >> a) {
        high = a[a.length()-2] - '0';
        low = a[a.length()-1] - '0';
        for (int i = a.length()-3; i >= 0; i--) {
            tmp = a[i] - '0';
            if (tmp >= high) {
                low = max(low, high);
                high = tmp;
            }
        }
        ans += 10 * high + low;
    }
    cout << ans << "\n";
}

void p2() {
    long long ans = 0;
    int first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth, eleventh, twelfth;
    int tmp, store;
    while (cin >> a) {
        twelfth = a[a.length()-1] - '0';
        eleventh = a[a.length()-2] - '0';
        tenth = a[a.length()-3] - '0';
        ninth = a[a.length()-4] - '0';
        eighth = a[a.length()-5] - '0';
        seventh = a[a.length()-6] - '0';
        sixth = a[a.length()-7] - '0';
        fifth = a[a.length()-8] - '0';
        fourth = a[a.length()-9] - '0';
        third = a[a.length()-10] - '0';
        second = a[a.length()-11] - '0';
        first = a[a.length()-12] - '0';

        for (int i = a.length()-13; i >= 0; i--) {
            tmp = a[i] - '0';
            if (tmp >= first) {
                store = first;
                first = tmp;
                tmp = store;
                if (tmp >= second) {
                    store = second;
                    second = tmp;
                    tmp = store;
                    if (tmp >= third) {
                        store = third;
                        third = tmp;
                        tmp = store;
                        if (tmp >= fourth) {
                            store = fourth;
                            fourth = tmp;
                            tmp = store;
                            if (tmp >= fifth) {
                                store = fifth;
                                fifth = tmp;
                                tmp = store;
                                if (tmp >= sixth) {
                                    store = sixth;
                                    sixth = tmp;
                                    tmp = store;
                                    if (tmp >= seventh) {
                                        store = seventh;
                                        seventh = tmp;
                                        tmp = store;
                                        if (tmp >= eighth) {
                                            store = eighth;
                                            eighth = tmp;
                                            tmp = store;
                                            if (tmp >= ninth) {
                                                store = ninth;
                                                ninth = tmp;
                                                tmp = store;
                                                if (tmp >= tenth) {
                                                    store = tenth;
                                                    tenth = tmp;
                                                    tmp = store;
                                                    if (tmp >= eleventh) {
                                                        store = eleventh;
                                                        eleventh = tmp;
                                                        tmp = store;
                                                        if (tmp >= twelfth) {
                                                            store = twelfth;
                                                            twelfth = tmp;
                                                            tmp = store;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        long long whatever = twelfth + 10 * eleventh + pow(10, 2) * tenth + pow(10, 3) * ninth + pow(10, 4) * eighth + pow(10, 5) * seventh + pow(10, 6) * sixth + pow(10, 7) * fifth + pow(10, 8) * fourth + pow(10, 9) * third + pow(10, 10) * second + pow(10, 11) * first;
        cout << whatever << "\n";
        ans += twelfth + 10 * eleventh + pow(10, 2) * tenth + pow(10, 3) * ninth + pow(10, 4) * eighth + pow(10, 5) * seventh + pow(10, 6) * sixth + pow(10, 7) * fifth + pow(10, 8) * fourth + pow(10, 9) * third + pow(10, 10) * second + pow(10, 11) * first;
    }
    cout << ans << "\n";
}

int main() {
    // p1();
    p2();
}