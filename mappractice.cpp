//
// Created by Yuan Zhao on 2/10/20.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> map;
    for(int i = 0; i <= 10; i ++) {
        map[i] = i;
    }
    auto it = map.lower_bound(5);
    cout << map.end()->first << endl;
    cout << it->first << endl;
    it = map.upper_bound(5);
    cout << it->first << endl;
    it = map.lower_bound(0);
    cout << it->first << endl;
    it--;
}
