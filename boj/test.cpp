#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
vector<int> arr;

int BinarySearchLowerBound(int s, int e, int number)
{
    int left=s,right=e,mid;
    int lower_bnd = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] >= number)
        {
            lower_bnd = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return lower_bnd;
}

int BinarySearchUpperBound(int s, int e, int number)
{
    int left=s,right=e,mid;
    int upper_bnd=-1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] <= number)
        {
            upper_bnd = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return upper_bnd+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int j = 1; j <= 4; j++) {
        for (int i = 0; i < 3; i++) {
            arr.push_back(j*2);
        }
    }
    cout << lower_bound(all(arr), 2) - arr.begin() << endl;
    cout << upper_bound(all(arr), 2) - arr.begin() << endl;
    cout << BinarySearchLowerBound(0, arr.size() - 1, 2) << endl;
    cout << BinarySearchUpperBound(0, arr.size() - 1, 2) << endl;
}