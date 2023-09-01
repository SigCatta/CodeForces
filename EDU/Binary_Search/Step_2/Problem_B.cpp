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

vector<double> a;
ll n, k;


bool good(long double m){
	ll c = 0;
	rep(i, n) c += floor(a[i] / m);
	return c >= k;
}

void solve(){
	long double l = 0, r = 1;
	long double m;
	while(good(r)) r *= 2;

	rep(i , 100){
		m = l + (r - l) / 2;
		if(good(m)) l = m;
		else r = m;
	}
	cout << setprecision(10) << l << "\n";	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << std::fixed;

	cin >> n >> k;
	a = vector<double>(n);
	rep(i, n) cin >> a[i];

	solve();
}
