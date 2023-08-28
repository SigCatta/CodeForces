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

void solve(){
	int n;
	string s;
	cin >> n >> s;

	string ans;
	char c = s[0];
	ans += c;
	for(int i = 1; i < n; i++){
		if(c == s[i]){
			if(++i >= n) break;
			c = s[i];
			ans += c;
		}
	}
	cout << ans << "\n";
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
