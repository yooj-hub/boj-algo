#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int t,n,m;
int a;
int b;
int tmp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        a = 0;
        b = 0;
        for(int i=1; i<=n; i++){
            cin >> tmp;
            a = max(a, tmp);
        }
        cin >> m;
        for(int i=1; i<=m; i++){
            cin >> tmp;
            b = max(b, tmp);
        }
        if(a > b){
            cout << "Alice\n";
            cout << "Alice\n";
        }
        else if(a==b){
            cout << "Alice\n";
            cout << "Bob\n";
        }
        else{
            cout << "Bob\n";
            cout << "Bob\n";
        }
        
    }
    
}