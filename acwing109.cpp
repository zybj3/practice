#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500010;
int n, m, t;
int A[N], B[N], C[N];

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while(k <= r) {
        if(i <= mid && j <= r) {
            if(C[i] > C[j]) {
                B[k ++] = C[j ++];
            }else B[k ++] = C[i ++];
        }else if(i <= mid) B[k ++] = C[i ++];
        else B[k ++] = C[j ++];
    }
}

bool check(int l, int mid, int r) {
    for(int i = mid; i <= r; i ++) {
        C[i] = A[i];
    }
    sort(C + mid, C + r + 1);
    merge(l, mid - 1, r);
    int cm = m;
    ll jyz = 0;
    for(int i = l, j = r; i < j && cm > 0; i ++, j --) {
        jyz += (B[j] - B[i]) * (B[j] - B[i]);
        cm --;
    }

    cout << l << " " << r << " " << jyz << endl;
    if(jyz <= t) {
        for(int i = l; i <= r; i ++) {
            C[i] = B[i];
        }
        return true;
    }else {
        return false;
    }
}
int calc() {
    int l = 1, r = 1, len = 1;
    C[l] = A[l];
    int res = 0;
    while(r <= n) {
        if(!len) {
            l = ++ r;
            C[l] = A[l];
            len = 1;
            res ++;
        }else if(r + len <= n && check(l, r + 1, r + len)) {
            r += len;
            len <<= 1;
        }else {
            len >>= 1;
        }
        cout << len << endl;
    }
    return res;
}


int main() {
    int k;
    cin >> k;
    while(k --) {
        cin >> n >> m >> t;
        for(int i = 1; i <= n; i ++) {
            cin >> A[i];
        }
        cout << calc() << endl;
    }
    return 0;
}