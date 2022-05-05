#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>> b;
        cout << a * b / __gcd(a,b)<<'\n';
    }
    
}