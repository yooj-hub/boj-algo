#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout <<"==";
    }else if(a<b){
        cout << "<";
    }else{
        cout << ">";
    }

}