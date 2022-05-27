#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 1010101

using namespace std;
int arr[MX];
int b[MX];
int n;
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(b, -1, sizeof(b));
    for (int i = n; i >= 1; i--) {
        if (stk.empty()) {
            b[i] = -1;
        } else {
            while (!stk.empty()) {
                if (stk.top() <= arr[i]) {
                    stk.pop();
                }else{
                    break;
                }
            }
            if (stk.empty()) {
                b[i] = -1;
            } else {
                b[i] = stk.top();
            }
        }
        stk.push(arr[i]);

    }
    for (int i = 1; i <=n; i++) {
        cout << b[i] << ' ';
    }
}