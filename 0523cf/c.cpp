#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101

using namespace std;

int t,n;
vector<int>a;
vector<int>b;
map<pair<int,int>, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        b.resize(n);
        mp.clear();
        for(int i=0; i<n;i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        vector<int> sa = a;
        vector<int> sb = b;
        sort(all(sa));
        sort(all(sb));
        for(int i=0; i<n; i++){
            mp[{sa[i],sb[i]}]++;
        }
        bool ok = true;
        for(int i=0; i<n; i++){
            if(mp.find({a[i],b[i]})==mp.end()){
                ok = false;
            }else{
                if(mp[{a[i],b[i]}]>=1){
                    mp[{a[i],b[i]}]--;
                }else{
                    ok = false;
                }
            }
        }
        if(!ok){
            cout << -1<<'\n';
        }else{
            vector<pair<int,int>> res;
            bool chk[MX];
            memset(chk, false, sizeof(chk));
            int idx = 0;
            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                    if(sa[i] == a[j] && sb[i] == b[j]){
                        idx = j;
                    }
                }
                if(idx == i) continue;
                swap(a[idx], a[i]);
                swap(b[idx], b[i]);
                res.push_back({idx,i});
            }
            cout << res.size()<<'\n';
            for(int i=0; i<res.size(); i++){
                cout << res[i].first+1 <<' ' <<res[i].second+1 <<'\n';
            }
        }
    }
    
}