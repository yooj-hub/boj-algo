#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

vector<int>a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        int t;
        cin >>t; 
        a.push_back(t);
    }
    sort(all(a));
    int m;
    cin >> m;
    for(int i=0; i<m;i++){
        int target;
        cin >> target;
        cout << binary_search(all(a), target)<<'\n';

    }
    
    
}