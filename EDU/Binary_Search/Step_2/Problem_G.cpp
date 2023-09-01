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

ll k, n;
vll a;


bool good(ll cons){
	ll sum = 0;
	rep(i, n) sum += min(a[i], cons);
	return sum >= k * cons;
}


void solve(){
	cin >> k >> n;
	a = vll(n);
	rep(i, n){
		cin >> a[i];
	}
	sort(all(a));
	ll l = - 1, r = 1e15, m;
	while (l + 1 < r) {
		m = l + (r -l) / 2;
		if(good(m)) l = m;
		else r = m;
	}
	cout << l << "\n";
}

int main(){
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}

