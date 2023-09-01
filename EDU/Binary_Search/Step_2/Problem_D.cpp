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
#define pb push_back
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

ll b, n;
vector<vll> a;
vll s;

bool good(ll m){
	ll c = 0;
	rep(i, n){
		ll t = a[i][0] * a[i][1] + a[i][2]; // time for 1 cycle
		ll cycles = m / t; // cycles
		ll curr = cycles * a[i][1]; // cycles * baloons per cycle 
		
		ll remTime = m % t;

		if (remTime != 0) {
			if (remTime >= a[i][1] * a[i][0]) {
				curr += a[i][1];
			}
			else {
				curr += remTime / a[i][0];
			}
		}

		if(c + curr <= b) s[i] = curr;
		else if (c <= b) s[i] = b - c;
		else s[i] = 0;

		c += curr;
	}
	
	return c >= b;
}

void solve(){
	ll l = -1;
	ll r = 1e15;
	ll m;
	while (l + 1 < r){
		m = l + (r - l) / 2;
		if(good(m)) r = m;
		else l = m;
	}
	cout << r << "\n";

	good(r);
	rep(i, n) cout << s[i] << " ";

	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	cin >> b >> n;
	a = vector<vector<ll>>(n, vector<ll>(3));
	s = vll(n);
	rep(i, n){
		rep(j, 3) cin >> a[i][j];
	}

	solve();
}

