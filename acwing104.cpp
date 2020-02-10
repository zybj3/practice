////
//// Created by Yuan Zhao on 2/7/20.
////
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int l, int r) {
    int p = nums[l];
    int i = l, j = l + 1;
    for(;j <= r; j ++) {
        if(nums[j] <= p) {
            i ++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[l]);
    return i;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i ++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int l = 0, r = n - 1;
    int med = 0;
    while(true) {
        int m = partition(nums, l, r);
        if(m == n / 2) {
            med = nums[m];
            break;
        }
        else if(m > n / 2) r = m - 1;
        else l = m + 1;
    }
    long long res = 0;
    for(auto num: nums) res += abs(num - med);
    cout << res << endl;
    return 0;
}