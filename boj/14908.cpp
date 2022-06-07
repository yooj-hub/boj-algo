#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;



vector<pair<double, int>> works;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        works.push_back({(double)a/b, i});
    }
    sort(all(works));
    for (int i = 0; i < n; i++) {
        cout << works[i].second+1 <<' ';
    }
}