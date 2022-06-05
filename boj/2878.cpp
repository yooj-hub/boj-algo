#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

vector<unsigned long long> arr;
unsigned long long m,n;


unsigned long long mod(unsigned long long ans){
    unsigned long long MOD = (1<<64);
    if(ans & MOD){
        return ans - MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    int mx = -1;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        arr.push_back(t);
        mx = max(mx, t);
    }
    sort(all(arr));
    reverse(all(arr));
    unsigned long long left = 0;
    unsigned long long right = mx;
    unsigned long long ans = 0;
    bool ok = false;
    while(left <= right){
        unsigned long long mid = (left+right)>>1;
        unsigned long long tmp = 0;




    }

    
     
    
}