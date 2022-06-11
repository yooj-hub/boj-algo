#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 501

using namespace std;

int d[MX][MX];
vector<int>arr[MX];
vector<int> res;
int n,t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    memset(d, -1, sizeof(d));
    for(int i=1; i<=n; i++){
        cin >> t;
        int idx = t%n;
        arr[idx].push_back(t);
    }
    for(int i=1; i<=n; i++){
        if(arr[i].size() >= n){
            for(int j=0; j<n; j++){
                cout << arr[i][j]<<' ';
            }
            return 0;
        }
    }
    


    
    
    
}