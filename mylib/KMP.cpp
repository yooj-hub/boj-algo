#include<bits/stdc++.h>

using namespace std;

vector<int> get_pi(string p) {
    int n = p.size();
    vector<int> pi(n);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) {
            pi[i] = j + 1;
            j++;
        }
    }
    return pi;

}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    int n = s.size();
    int m = p.size();

    vector<int> pi = get_pi(p);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }

        }
    }
    return ans;

}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}