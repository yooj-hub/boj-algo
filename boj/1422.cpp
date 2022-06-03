#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int n, k;
vector<int> numbers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k >> n;
    numbers.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> numbers[i];
    }
    sort(all(numbers));
    string ans = "";
    for (int i = 0; i < n - k; i++) {
        numbers.push_back(numbers[k-1]);
    }
    sort(all(numbers), [](int a, int b) {
        string left = to_string(a) + to_string(b);
        string right = to_string(b) + to_string(a);
        return right < left;
    });

    for (int i = 0; i < n; i++) {
        ans += to_string(numbers[i]);
    }
    cout << ans;
}