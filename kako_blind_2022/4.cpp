#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
vector<vector<int>> anss;

bool cmp(vector<int> &a, vector<int> &b) {
    for (int i = 10; i >= 0; i--) {
        if (a[i] != b[i]) {
            return b[i] < a[i];
        }
    }
    return true;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int diff = 0;
    for (int i = 0; i < 2048; i++) {
        vector<int> tmp;
        vector<int> tmp2(11, 0);
        int current = n;
        int current_answer = 0;
        for (int j = 0; j <= 10; j++) {
            if (i & (1 << j)) {
                tmp.push_back(j);
            }
        }
        for (int k = 0; k < tmp.size(); k++) {
            current -= info[tmp[k]] + 1;
            tmp2[tmp[k]] = info[tmp[k]] + 1;
            current_answer += (10 - tmp[k]);
        }
        if (current < 0) {
            continue;
        }
        if (current != 0) {
            tmp2[10] += current;
        }
        int op = 0;
        for (int j = 0; j < 10; j++) {
            if (info[j] == 0)
                continue;
            if (tmp2[j] <= info[j]) {
                op += 10 - j;
            }
        }

        if (current_answer != 0 && current_answer - op > diff &&
            current_answer > op) {
            diff = current_answer - op;
            anss.clear();

            anss.push_back(tmp2);
        } else if (current_answer != 0 && current_answer - op == diff &&
                   current_answer > op) {
            anss.push_back(tmp2);
        }
    }

    if (anss.size() > 1) {
        sort(all(anss), cmp);
        answer = anss[0];
    } else if (anss.size() == 1) {
        answer = anss[0];
    }
    if (answer.size() == 0) {
        return vector<int>(1, -1);
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> res = solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0});
    for (int i = 0; i < res.size(); i++) {

        cout << res[i];
    }
}