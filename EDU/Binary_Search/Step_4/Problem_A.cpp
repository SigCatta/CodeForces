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

ll n, d;
vll a;
ll li, ri;


bool good(ld x){
	vld p(n + 1);
	p[0] = 0;
	ld mean = 0;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] + (a[i - 1] - x);
	}
	
	ll index = 0;
	for(int i = d; i <= n; i++){
		if(p[i - d] < mean){
			mean = p[i - d];
			index = i - d;
		}
		if(p[i] - mean >= 0){
			li = index + 1;
			ri = i;
			return true;
		}
	}
	return false;
}

void solve(){
	cin >> n >> d;
	a = vll(n);
	rep(i, n) cin >> a[i];

	ld l = - 1, r = 1e9, m;
	rep(i, 100){
		m = l + (r - l) / 2;
		if(good(m)) l = m;
		else r = m;
	}

	cout << li << " " << ri << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}
