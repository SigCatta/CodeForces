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

int n;
vector<int> a;


bool good(int m){
	int l = a[0];
	int i;
	for(i = 1; i < n; i++){
		if(m < (a[i] - l + 1) / 2) break;
	}
	l = a[i];
	
	int j;
	for(j = i + 1; j < n; j++){
		if(m < (a[j] - l + 1) / 2) break;
	}

	if(j == n || i == n) return true;
	if(m < (a[n - 1] - a[j] + 1) / 2) return false;
	return true;
}

void solve(){
	cin >> n;
	a = vector<int>(n);
	rep(i, n) cin >> a[i];

	sort(all(a));

	int l = - 1, r = 1e9, m;
	while (l + 1 < r){
		m = l + (r - l) / 2;
		if(good(m)){
			r = m;
		} else{
			l = m;
		}
	}

	cout << r << "\n";
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
