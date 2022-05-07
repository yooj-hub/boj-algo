#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

vector<int> d;
int arr[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    d.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if(d.back() < arr[i]){
            d.push_back(arr[i]);
        }else{
            d[lower_bound(all(d), arr[i])- d.begin()] = arr[i];
        }
    }
    cout << d.size()<<'\n';
}