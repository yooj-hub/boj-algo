#include<bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long int
#define MX 101010

using namespace std;

int n;

struct Node {
    int value;
    Node *nxt;
    Node *pre;

    Node(int x) {
        value = x;
        nxt = nullptr;
    }
    Node(){

    }

    void add_node(int x, Node *head) {
        Node *target = new Node(x);
        Node *cur = head;
        while (cur->nxt != nullptr) {
            cur = cur->nxt;
        }
        cur->nxt = target;
        target->pre = cur;
    }

    void delete_node(bool isOdd, Node *cur) {
        if (cur->nxt != nullptr) {
            delete_node(!isOdd, cur->nxt);
        }
        if (isOdd) {
            if (cur->pre != nullptr)
                cur->pre->nxt = cur->nxt;
            if (cur->nxt != nullptr)
                cur->nxt->pre = cur->pre;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    Node *head = new Node();
    for (int i = 1; i <= n; i++) {
        head->add_node(i, head);
    }
    while (true) {
        if (head->nxt->nxt == nullptr) break;
        head->delete_node(true, head->nxt);
    }
    cout << head->nxt->value;

}