#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
int n;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    pair<int, int> ans;
    int tmp = 2e9 + 7;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = arr[left] + arr[right];

        if (tmp > abs(mid)) {
            tmp = abs(mid);
            ans.first = arr[left];
            ans.second = arr[right];
        }
        if (mid < 0)
            left++;
        else
            right--;
    }

    cout << ans.first << ' ' << ans.second;
}
