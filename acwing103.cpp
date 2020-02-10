//
// Created by Yuan Zhao on 2/7/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int N = 200010;
vector<int> s_lang;
int s_lang_arr[N], lang[N], cc[N], c[N];

int search(int lang) {
    int l = 0, r = s_lang.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (s_lang[mid] >= lang) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (s_lang[l] == lang) return l + 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s_lang_arr[i];
        s_lang.push_back(s_lang_arr[i]);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> lang[i];
    for (int i = 1; i <= m; i++) cin >> cc[i];
    sort(s_lang.begin(), s_lang.end());
    s_lang.erase(unique(s_lang.begin(), s_lang.end()), s_lang.end());
    for (int i = 0; i < n; i++) {
        int idx = search(s_lang_arr[i]);
        c[idx]++;
    }
    vector<PIII> res;
    for (int i = 1; i <= m; i++) {
        res.push_back({{c[search(lang[i])], c[search(cc[i])]}, i});
    }
    sort(res.begin(), res.end());
    cout << res.back().second << endl;
    return 0;
}