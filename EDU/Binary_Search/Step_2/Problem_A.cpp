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

unsigned long long w, h, n;

bool good(unsigned long long m){
	unsigned long long nH = floor(m / h);
	unsigned long long nB = floor(m / w);
	if(nB * nH >= n) return true;
	else return false;
}

void solve(){
	unsigned long long r = 1e15;
	unsigned long long l = -1;
	unsigned long long m;
	while(l + 1 < r) {
		m = l + (r - l) / 2;
		if(good(m))r = m;
		else l = m;
	}
	cout << r << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	cin >> w >> h >> n;

	solve();
}

