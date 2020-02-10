//
// Created by Yuan Zhao on 2/8/20.
//
#include <queue>
#include <iostream>

using namespace std;

void push(int num, int &count, priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right) {
    if (count % 2 == 0) {
        if (!right.empty()) {
            int rf = right.top();
            if (num > rf) {
                right.pop();
                left.push(rf);
                right.push(num);
            } else {
                left.push(num);
            }
        } else {
            left.push(num);
        }
    } else {
        int lf = left.top();
        if (num < lf) {
            left.pop();
            right.push(lf);
            left.push(num);
        } else {
            right.push(num);
        }
    }
    count++;
}

int main() {
    int p;
    cin >> p;
    while (p--) {
        int mark, m;
        cin >> mark >> m;
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int size = 0, count = 0;
        cout << mark << " " << (1 + m) / 2 << endl;
        while (m) {
            int num;
            cin >> num;
            push(num, size, left, right);
            if (size % 2) {
                cout << left.top() << " ";
                count ++;
                if(count == 10) {
                    count = 0;
                    cout << endl;
                }
            }
            m --;
        }
        cout << endl;
    }

    return 0;
}