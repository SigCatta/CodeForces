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

vi a;
vi b;

void solve(int q){
	int l = - 1;
	int r = a.size();
	int m;

	while (l + 1 < r){
		m = l + (r - l) / 2;
		
		if(a[m] <= q) l = m;
		else if(a[m] > q) r = m;
	}
	if(l == - 1){
		cout << 0 << "\n";
		return;
	}
	if(l == int(a.size()) - 1){
		cout << a.size() << "\n";
		return;
	} 
	
	cout << l + 1 << "\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	int n , k;
	cin >> n >> k;
	a = vi(n);
	b = vi(k);

	rep(i, n) cin >> a[i];
	rep(i, k) cin >> b[i];
	int t = 0;
	while (t < k){
		solve(b[t++]);
	}
}
