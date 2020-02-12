#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int n, root;
struct Node{
    int p, v, s;
    double avg;
}nodes[N];

int find() {
    int max = -1, max_index = 0;
    for(int i = 1; i <= n; i ++) {
        if(nodes[i].avg > max && i != root) {
            max_index = i;
            max = nodes[i].avg;
        }
    }
    return max_index;
}
int main() {
    cin >> n >> root;
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> nodes[i].v;
        nodes[i].avg = nodes[i].v;
        nodes[i].s = 1;
        res += nodes[i].v;
    }
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        nodes[b].p = a;
    }

    for(int i = 0; i < n - 1; i ++) {
        int p = find();
        int father = nodes[p].p;
        res += nodes[p].v * nodes[father].s;
        nodes[p].avg = -1;
        for(int j = 1; j <= n; j ++) {
            if(nodes[j].p == p) {
                nodes[j].p = father;
            }
        }
        nodes[father].v += nodes[p].v;
        nodes[father].s += nodes[p].s;
        nodes[father].avg = (double)nodes[father].v / nodes[father].s;
    }
    cout << res << endl;
    return 0;
}