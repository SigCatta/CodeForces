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
#define mp (k % (n - 1))
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

void solve(){
	ll n, k;
	cin >> n >> k;
	vll a;
	int f;
	bool pres[n + 1] = {};


	k = k % (n + 1);
	rep(i, n){
		cin >> f;
		pres[f] = true;
		a.pb(f);
	}
	n++;

	if(k == 0) {
		rep(i, n - 1){
			cout << a[i] << " ";
		}
		cout << "\n";
		return; 
	}
	rep(i, n) if(!pres[i]) a.pb(i);

	for(int i = n - k ; i < n; i++) cout << a[i] << " ";
	for(int i = 0; i < n - k - 1; i++) cout << a[i] << " ";
	cout << "\n";
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

