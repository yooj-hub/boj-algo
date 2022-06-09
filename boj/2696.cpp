#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int t, m;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> m;
        priority_queue<int, vector<int>, greater<>> mnq;
        priority_queue<int> mxq;
        int pos = 1;
        int target;
        cout << (m+1)/2<<'\n';
        cin >> target;
        cout << target<<' ';
        int cnt = 1;
        while (pos != m) {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            if (target > a && target < b) {
                mnq.push(b);
                mxq.push(a);
            } else if (target < a) {
                mnq.push(a);
                mnq.push(b);
                mxq.push(target);
                target = mnq.top();;
                mnq.pop();
            } else if (target >= b) {
                mnq.push(target);
                mxq.push(b);
                mxq.push(a);
                target = mxq.top();
                mxq.pop();
            }
            
            cout << target << ' ';
            cnt++;
            pos += 2;
            if(cnt %10 == 0 && pos != m){
                cout << '\n';
            }
        }
        cout << '\n';
    }
}