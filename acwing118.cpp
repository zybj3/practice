//
// Created by Yuan Zhao on 2/12/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int change[5][5];

int get(int x, int y) {
    return x * 4 + y;
}

int main() {
    int state = 0;
    for(int i = 0; i < 4; i ++) {
        string line;
        cin >> line;
        for(int j = 0; j < 4; j ++) {
            if(line[j] == '+') {
                state += 1 << get(i, j);
            }
        }
    }

    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            for(int k = 0; k < 4; k ++) {
                change[i][j] += 1 << get(i, k);
                change[i][j] += 1 << get(k, j);
            }
            change[i][j] -= 1 << get(i, j);
        }
    }
    vector<pair<int, int>> res;
    for(int i = 0; i < 1 << 16; i ++) {
        int now = state;
        vector<pair<int, int>> path;
        for(int j = 0; j < 16; j ++) {
            if(i >> j & 1) {
                now ^= change[j / 4][j % 4];
                path.push_back({j / 4 + 1, j % 4 + 1});
            }
        }
        if(!now && (res.empty() || res.size() > path.size())) {
            res = path;
        }
    }
    cout << res.size() << endl;
    for(auto p: res) {
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}