#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>


using namespace std;

vector<vector<char>> grid;
vector<tuple<int, int>> offsets = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool can_access(int i, int j) {
    int num_adjacent = 0;
    int posi, posj;
    for (auto offset: offsets) {
        
        posi = i + get<0>(offset);
        posj = j + get<1>(offset);
        if (posi >= 0 && posi < grid.size() && posj >= 0 && posj < grid[0].size()) {
            num_adjacent += (grid[posi][posj] == '@') ? 1 : 0;
        }
    }
    return num_adjacent <4;
}

void p1() {
    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '@' && can_access(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

void p2() {
    int ans = 0;
    int tmp;

    while (tmp != 0) { // lazy
        tmp = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '@' && can_access(i, j)) {
                    tmp++;
                    grid[i][j] = '.';
                }
            }
        }
        ans += tmp;
    }

    cout << ans << "\n";
}


int main(){
    string a;

    while (cin >> a) {
        vector<char> temp;
        for (auto c: a) {
            temp.push_back(c);
        }
        grid.push_back(temp);
    }

    p1();
    p2();
}