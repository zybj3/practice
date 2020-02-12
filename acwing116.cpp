#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
PII p[1010];
int n;
vector<int> div(vector<int> a, int b) {
    int t = 0;
    bool is_first = true;
    vector<int> c;
    for(int i = a.size() - 1; i >= 0; i --) {
        t = t * 10 + a[i];
        int x = t / b;
        if(!is_first || x) {
            is_first = false;
            c.push_back(x);
            t %= x;
        }
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> pdt(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for(int i : a) {
        t += i * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

vector<int> larger(vector<int> a, vector<int> b) {
    if(a.size() > b.size()) return a;
    if(b.size() > a.size()) return b;
    if(vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;
    return b;
}
int main() {
    cin >> n;
    for(int i = 0; i < n + 1; i ++) {
        int a, b;
        cin >> a >> b;
        p[i].first = a * b;
        p[i].second = b;
    }
    sort(p + 1, p + n + 1);
    vector<int> res(1, 0);
    vector<int> product(1, 1);
    for(int i = 0; i < n + 1; i ++) {
        if(i) res = larger(div(product, p[i].second), res);
        product = pdt(product, p[i].first / p[i].second);
    }
    for(int i = res.size() - 1; i >= 0; i --) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}