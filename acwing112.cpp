//
// Created by Yuan Zhao on 2/10/20.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double, double> PDD;
const int N = 1001;
const double eps = 1e-6;
PDD islands[N];

int main() {
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        if(y > d) {
            cout << "-1" << endl;
            return 0;
        }
        double len = sqrt(d * d - y * y);
        islands[i] = {x + len, x - len};
    }
    sort(islands, islands + n);

    double end = -1e10;
    int res = 0;
    for(int i = 0; i < n; i ++) {
        // cout << islands[i].first << endl;
        if(islands[i].second > end + eps) {
            res ++;
            end = islands[i].first;
        }else {
            end = max(islands[i].second, end);
        }
    }

    cout << res << endl;
    return 0;
}