#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int cnt[26];
vector<char> arr;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    sort(all(s));
    int half = (s.size() + 1) / 2;
    for (int i = half; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i])
            continue;
        int tmp = i + 1;
        while (tmp < s.size() && s[tmp] == s[i])
            tmp++;
        if (tmp == s.size()) {
            cout << "-1\n";
            exit(0);
        }
        swap(s[i], s[tmp]);
    }
    cout << s;
}