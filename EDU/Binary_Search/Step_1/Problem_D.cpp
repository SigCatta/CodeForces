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

void solve(int x, int y){
	int l = -1, r = int(a.size());
	int m, i1 = 0, i2 = 0;
	
	while(l + 1 < r){
		m = l + (r - l) / 2;
		if(x > a[m]) l = m;
		else if (x <= a[m]) r = m; 
	}
	if(l == -1) i1 = 0; 
	else if(l == a.size() - 1) i1 = a.size();
	else if(a[l] == x) i1 = l;
	else i1 = l + 1;
	
	l = -1;
	r = int(a.size());
	while(l + 1 < r){
		m = l + (r - l) / 2;
		if(y >= a[m]) l = m;
		else if (y < a[m]) r = m;
	}
	if(l == -1) i2 = 0;
	else if(l == a.size() - 1) i2 = a.size();
	else i2 = r;


	cout << i2 - i1 << " "; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;
	int n;
	cin >> n;
	a = vi(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	int k;
	cin >> k;
	int t = 0;
	while(t++ < k){
		int i1, i2;
		cin >> i1 >> i2;
		solve(i1, i2);
	}
	cout << "\n";
}

