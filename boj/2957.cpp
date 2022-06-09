#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 301010

using namespace std;

int n, t;
ll c = 0LL;
int arr[MX];
set<int> s;

void insert(int x) {
    s.insert(x);
    auto iter = s.find(x);
    auto prev = --iter;
    ++iter;
    auto nxt = ++iter;
    arr[x] = max(arr[*prev] + 1, arr[*nxt] + 1);
    c = c+ arr[x];
    cout << c<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    s.insert(0);
    s.insert(n + 1);
    arr[0] = -1;
    arr[n + 1] = -1;
    while(n--){
        cin >> t;
        insert(t);
    }
}