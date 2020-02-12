//
// Created by Yuan Zhao on 2/11/20.
//
#include <iostream>
using namespace std;


void change(int A[]) {
    for(int i = 0; i < 3; i ++) {
        A[i] = i + 1;
    }
}
void change1(int B[][3]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            B[i][j] = i * j + 1;
        }
    }
}
int main() {
    int A[3];
    for(int i = 0; i < 3; i ++) {
        A[i] = i;
    }
    change(A);
    for(int i = 0; i < 3; i ++) {
        cout << A[i] << endl;
    }

    int B[2][3];
    for(int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; ++j) {
            B[i][j] = i * j;
        }
    }

    change1(B);
    for(int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }


}

