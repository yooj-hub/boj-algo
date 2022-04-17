#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    
    ll k = n%5;

    if(k==2 || k==0){
        cout << "CY"<<'\n';
    }else{
        cout << "SK"<<'\n';
    }


}