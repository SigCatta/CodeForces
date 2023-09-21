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
typedef vector<long double> vld;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";


long long smallest_divisor(long long x){
	if(x <= 3) return 1; // is prime
	if(x % 2 == 0) return 2;
	for(long long i = 5; i * i <= x; i += 2){
		if(x % i == 0) return i;
	}
	return 1; // is prime
}

bool is_prime(long long x){
	if(x <= 3) return true;
	if(x % 2 == 0) return false;
	for(long long i = 5; i * i <= x; i += 2){
		if(x % i == 0) return false;
	}
	return true;
}
vi a;
int n, x;


bool good(ll m){
	ll sum = 0;
	rep(i, n) sum += (m - a[i]) < 0 ? 0 : m - a[i]; 
	return sum <= x;
}

void solve(){
	cin >> n >> x;
	a = vi(n);
	rep(i, n) cin >> a[i];

	ll l = 1, r = 4 * 1e9, m;
	while(l + 1 < r){
		m = l + (r - l) / 2;
		if(good(m)) l = m;
		else r = m;
	}
	cout << l << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	int t;
	cin >> t;
	while (t-- > 0){
		solve();
	}
}

