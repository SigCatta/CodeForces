#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define rep(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X, S, Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve() {
    int l;
    cin >> l;
    int arr[l];
    vi cum(l + 1, 0);
    bool abrt = false;

    rep(i, l){
        cin >> arr[i];
        if (arr[i] > l) abrt = true;
        else cum[arr[i]] += 1;
    }

    if (abrt){
        cout << "NO\n";
        return;
    }
    int c = 0;
    for (int i = l; i > 0; i--) {
        c += cum[i];
        if (arr[i - 1] != c) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
