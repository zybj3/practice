//
// Created by Yuan Zhao on 2/10/20.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 50010;
pair<PII, int> cows[N];
int id[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i;
    }
    sort(cows, cows + n);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.empty() || cows[i].first.first <= pq.top().first) {
            PII stall = {cows[i].first.second, pq.size() + 1};
            id[cows[i].second] = stall.second;
            pq.push(stall);
        } else {
            PII stall = pq.top();
            pq.pop();
            stall.first = cows[i].first.second;
            id[cows[i].second] = stall.second;
            pq.push(stall);
        }
    }

    cout << pq.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << id[i] << " ";
    }
    cout << endl;
    return 0;
}