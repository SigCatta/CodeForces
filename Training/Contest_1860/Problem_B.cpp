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
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    int ck = min(ak, m / k);
    int c1 = min(a1, m - (ck * k));
    int real = c1 + (ck * k);
    if(real == m) {
        cout << 0 << "\n";
        return;
    }
    
    int fancy = m - real;

    int fk = fancy / k;
    int f1 = fancy - (fk * k);
    if (f1 + c1 >= k && f1 > 0) cout << fk + 1 << "\n";
    else cout << f1 + fk << "\n";
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
