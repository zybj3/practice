//
// Created by Yuan Zhao on 2/4/20.
//


#include <iostream>
#include <cstring>
using namespace std;

void dfs(int cur, int count, int n, int m, int state) {
    if(count > m) {
        return;
    }
    if(count == m) {
        for(int i = 0; i < n; i ++) {
            if(state >> i & 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        return;
    }

    for(int i = cur; i <= n; i ++) {
        dfs(i + 1, count + 1, n, m, state ^ (1 << (i - 1)));
    }
}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    dfs(1, 0, n, m, 0);
//}