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
typedef long double ld;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll n;
vector<ld> x, v;

bool goodMin(ld m){
	ld l = x[0] - m * v[0];
	ld r = x[0] + m * v[0];
	rep(i, n){
		if(l < x[i] - m * v[i]) l = x[i] - m * v[i];
		if(r > m * v[i] + x[i]) r =  m * v[i] + x[i];
	}

	return r - l >= 0;
}

void solve(){
	cin >> n;
	x = vector<ld>(n);
	v = vector<ld>(n);
	
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> v[i];
	ld l = - 1, r = 1e9, m;


	rep(i, 100){
		m = l + (r - l) / 2;
		if(goodMin(m)) r = m;
		else l = m;
	}

	cout << r << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}
