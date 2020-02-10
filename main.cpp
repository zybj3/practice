#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *test(ListNode *node) {
    ListNode head = ListNode(0);
    head.val = -11;
    head.next = node;
    ListNode *res = &head;
    return res;
}

void test1(ListNode &node) {
    node.val = 10;
}

void test3(int** &p) {
    int num = 7;
    int *p1 = &num;
    p = &p1;
}

void test4(ListNode n) {
    cout << n.next->val << endl;
    n.val = 4;
    n.next->val = 5;
}

void test5(int** p) {
    int a = 10;
    *p = &a;
}

//int main() {
//    int num = 4;
//    int* a = &num;
//    int** p = &a;
//    cout << *p << endl;
//    test5(p);
//    cout << *p << endl;
//
////    ListNode n1 = ListNode(1);
////    ListNode n2 = ListNode(2);
////    n1.next = &n2;
////    test4(n1);
////    cout << n1.val << endl;
////    cout << n1.next->val << endl;
//    return 0;
//}