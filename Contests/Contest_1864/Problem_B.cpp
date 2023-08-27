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
	int n, k;
	cin >> n >> k;
	vector<char> s(n);
	rep(i ,n) cin >> s[i];

	if(k % 2 == 0) {
		sort(all(s));
		rep(i, n) cout << s[i];
		cout << "\n";
		return;
	}

	k--;
	for(int i = 0; i < n - k; i++){
		if(s[i] > s[i +k]){
			for(int j = 0; j < k && (i + j) < (i + k - j); j++){
				char c = s[i + j];
				s[i + j] = s[i + k - j];
				s[i + k - j] = c;
			}
			i = i - 2 < 0 ? -1 : i - 2;
		}
	}

	vector<char> p;
	vector<char> d;

	rep(i, n){
		if(i % 2 == 0) p.push_back(s[i]);
		else d.push_back(s[i]);
	}

	sort(all(p));
	sort(all(d));

	int pi = 0;
	int di = 0;
	rep(i, n) {
		if (i % 2 == 0) cout << p[pi++];
		else cout << d[di++];
	}	
	cout << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0){
		solve();
	}
}
