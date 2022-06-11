#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, m;
int arr[MX * 10];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int current = m;
    for (int i = 1; i <= current + m - 1; i++) {
        pq.push({arr[i], i});
    }
    int pos = current + m - 1;
    while (true) {
        while (pq.top().second < current - m + 1)
            pq.pop();
        cout << pq.top().first << ' ';
        pos++;
        current++;
        if (pos > n)
            break;
        pq.push({arr[pos], pos});
    }
}