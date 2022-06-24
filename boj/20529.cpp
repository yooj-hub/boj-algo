#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int t, n;
map<string, int> mp;
const int inf = 1e9 + 7;
int answer;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        mp.clear();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s]++;
            cnt = max(mp[s], cnt);
        }
        if (cnt >= 3) {
            cout << 0 << '\n';
        } else {
            answer = inf;
            vector<pair<string, int>> tmp;
            for (auto iter = mp.begin(); iter != mp.end(); iter++) {
                tmp.push_back({(*iter).first, (*iter).second});
            }
            for (int i = 0; i < tmp.size(); i++) {
                
                for (int j = i + 1; j < tmp.size(); j++) {
                    int x = tmp[j].second + tmp[i].second;
                    if (x >= 3) {
                        int y = 0;
                        for (int l = 0; l < 4; l++) {
                            if (tmp[i].first[l] != tmp[j].first[l]) {
                                y++;
                            }
                        }
                        y*=2;
                        answer = min(answer, y);
                    }
                    for (int k = j + 1; k < tmp.size(); k++) {
                        int y = 0;
                        // ij
                        for (int l = 0; l < 4; l++) {
                            if (tmp[i].first[l] != tmp[j].first[l]) {
                                y++;
                            }
                        }

                        // jk
                        for (int l = 0; l < 4; l++) {
                            if (tmp[j].first[l] != tmp[k].first[l]) {
                                y++;
                            }
                        }

                        // ik
                        for (int l = 0; l < 4; l++) {
                            if (tmp[i].first[l] != tmp[k].first[l]) {
                                y++;
                            }
                        }
                        answer = min(answer, y);
                    }
                }
            }
            cout << answer << '\n';
        }
    }
}