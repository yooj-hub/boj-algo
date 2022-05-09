#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(all(arr));
    int ans = 0;
    do{
        int tmp = 0;
        for(int i=0; i<n-1; i++){
            tmp += abs(arr[i] - arr[i+1]);
        }
        ans = max(tmp, ans);


    }
    while(next_permutation(all(arr)));
    cout << ans <<'\n';
    
}