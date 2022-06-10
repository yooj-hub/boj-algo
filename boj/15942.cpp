#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 202020

using namespace std;

int arr[MX];
int n, k, p;
int asc, descendent;
int counter = 1;

bool make_tree(int idx) {
    if (descendent > n) {
        return false;
    }
    arr[idx] = descendent++;
    bool ok = true;
    if (ok && idx * 2 <= n)
        ok &= make_tree(idx * 2);
    
    if (ok && idx * 2 + 1 <= n)
        ok &= make_tree(idx * 2 + 1);
    return ok;
}
void heapify(int idx) {
    while (idx > 1) {
        if (arr[idx] < arr[idx / 2])
            swap(arr[idx], arr[idx / 2]);
        idx /= 2;
    }
}
void insert(int idx) {
    if (counter == asc)
        counter = descendent;
    arr[idx] = counter++;
    heapify(idx);
    if (idx * 2 <= n)
        insert(idx * 2);
    if (idx * 2 + 1 <= n)
        insert(idx * 2 + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> p;
    descendent = k;
    if (!make_tree(p)) {
        cout << -1;
        return 0;
    }
    asc = k;
    while (p > 1) {
        p /= 2;
        arr[p] = --asc;
    }
    if (asc <= 0) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i])
            continue;
        insert(i);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << '\n';
    return 0;
}
