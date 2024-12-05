#include <bits/stdc++.h>

using namespace std;

int n, a, b;


int main() {
    // earliest start time
    auto compare = [](vector<int> first, vector<int> second) {
        return second[0] < first[0];
    };

    cin >> n;
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> times(compare);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > rooms;

    for (int i = 0; i < n; i ++) {
        cin >> a >> b;
        times.push({a, b, i+1});
    }

    vector<int> curr_time;
    pair<int, int> curr_room;
    int max_size = 0;
    vector<int> orders(n);

    while (!times.empty()) {
        curr_time = times.top();
        times.pop();

        if (rooms.size() == 0 || rooms.top().first >= curr_time[0]) {
            orders[curr_time[2]-1] =  rooms.size()+1;
            rooms.push(make_pair(curr_time[1], rooms.size()+1));
            max_size++;
        } else {
            curr_room = rooms.top();
            rooms.pop();
            rooms.push(make_pair(curr_time[1], curr_room.second));
            orders[curr_time[2]-1] = curr_room.second;
        }
    }

    cout << max_size << endl;
    for (auto ord: orders) {
        cout << ord << " ";
    }
}