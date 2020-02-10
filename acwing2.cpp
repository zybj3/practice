//
// Created by Yuan Zhao on 2/10/20.
//

#include <iostream>
using namespace std;
int dp[1010];
int v[1010];
int w[1010];

int main() {
    int N, V;
    cin >> N >> V;
    for(int i = 1; i <= N; i ++) {
        cin >> v[i];
        cin >> w[i];
    }
    for(int i = 1; i <= N; i ++) {
        for(int j = V; j >= v[i]; j --) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}