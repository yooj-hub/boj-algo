#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

struct Queue {

    int size = 0;
    int arr[10000];
    int front = -1;
    int pos = 0;

    Queue() {
        size = 0;
        memset(arr, 0, sizeof(arr));
        front = 0;
        pos = 0;
    }

    void Push(int x) {
        arr[pos++] = x;
        size++;
    }

    int Pop() {
        if (!Empty()) {
            size--;
            return arr[front++];
        } else {
            return -1;
        }
    }
    int Empty() { return size == 0; }
    int Front() {
        if (Empty()) {
            return -1;
        } else {
            return arr[front];
        }
    }
    int Back() {
        if (Empty()) {
            return -1;
        }
        return arr[pos-1];
    }
    int Size() { return size; }

} q;

int n, val;
string op;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> val;
            q.Push(val);
        }
        if (op == "pop") {
            cout << q.Pop() << '\n';
        }
        if (op == "size") {
            cout << q.Size() << '\n';
        }
        if (op == "empty") {
            cout << q.Empty() << '\n';
        }
        if (op == "front") {
            cout << q.Front() << '\n';
        }
        if (op == "back") {
            cout << q.Back() << '\n';
        }
    }
}