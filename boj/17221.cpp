#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
const int inf = 1e9 + 7;
bool nxt = true;

vector<int> hps;
bool possible(int i, int hp, int matk) {
    if (hp < 10) {
        if (hp - i * 3 * matk > 0) {
            return true;
        } else
            return false;
    }
    return true;
}

int calc(int hp, int mhp, int matk, int atk, int t) {
    if (atk < 5) {
        nxt = false;
        if (matk >= atk) {
            int x = mhp / matk;
            if (mhp % matk != 0)
                x++;
            return x;
        } else {
            if (hp < 10) {
                int x = 0;
                while (hp > matk && mhp > 0) {
                    mhp -= atk;
                    hp -= atk;
                    x++;
                }
                if (mhp > 0) {
                    x += mhp / matk;
                    if (mhp % matk != 0)
                        x++;
                    return x;
                } else {
                    return x;
                }
            } else {
                
            }
        }

    } else {
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int hp, atk, mhp, matk;
    cin >> hp >> atk >> mhp >> matk;
    hps.push_back(hp);
    bool ok = (atk >= 5) ? true : false;
    bool hpok = (hp >= 10) ? true : false;
    vector<int> atks;
    int answer = inf;
    if (ok) {
        atks.push_back(atk);
        int pos = 0;
        while (atks[pos] < mhp) {
            atks.push_back(atks[pos++] * 1.2);
        }
        for (int i = 0; i < atks.size(); i++) {
            cout << atks[i] << endl;
        }
    }
    for (int i = 0; i < atks.size(); i++) {
        if (!possible(i, hp, matk))
            break;
    }
    cout << answer;
}