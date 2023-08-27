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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
	int x, y, n;
    cin >> x >> y >> n;
    int a[n];

    int d = 1;
    a[0] = x;
    a[n - 1] = y;
    for (int i = n - 2; i > 0; i--){
        a[i] = a[i + 1] - d;
        d = a[i +1] - a[i] + 1;
    }

    int prev = a[n - 1];
    d = 0;
    for (int i = n - 2; i >= 0; i--){
        if (d >= prev - a[i]){
            cout << -1 << "\n";
            return;
        }
        d = prev - a[i];
        prev = a[i];
    }
    rep (i, n) cout << a[i] << " ";
    cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0){
		solve();
	}
}
