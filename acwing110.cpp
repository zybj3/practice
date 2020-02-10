//
// Created by Yuan Zhao on 2/9/20.
//

#include <iostream>
using namespace std;
const int N = 4;
int A[N * N], B[N * N];
long long cnt;

void merge(int l, int r) {
    if(l >= r) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(k <= r) {
        if(i <= mid && j <= r) {
            if(A[i] > A[j]) {
                cnt += mid - i + 1;
                B[k ++] = A[j ++];
            }else {
                B[k ++] = A[i ++];
            }
        }else if(i <= mid) {
            B[k ++] = A[i ++];
        }else {
            B[k ++] = A[j ++];
        }
    }
    for(int in = l; in <= r; in ++) {
        A[in] = B[in];
    }
}

int main() {
    int n;
    while(cin >> n) {
        long long ra  = 0, rb = 0;
        int num;
        int p = 1;
        for(int i = 1; i <= n * n; i ++) {
            cin >> num;
            if(num) {
                A[p ++] = num;
            }
        }
        cout << endl;
        cnt = 0;
        merge(1, n * n - 1);
        ra = cnt;
        p = 1;
        for(int i = 1; i <= n * n; i ++) {
            cin >> num;
            if(num) {
                A[p ++] = num;
            }
        }
        cnt = 0;
        merge(1, n * n - 1);
        rb = cnt;
        cout << ra << " " << rb << endl;
        if(!abs(ra - rb) % 2) {
            cout << "TAK" << endl;
        }else {
            cout << "NIE" << endl;
        }
    }
    return 0;
}