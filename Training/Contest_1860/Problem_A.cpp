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
	string s;
	cin >> s;

	int n = s.size();
	if (s == "()"){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	for (int i=0; i < n - 1; i++){
		if(s.substr(i, 2) == ")("){
			for (int j=0; j < n; j++) cout << "(";
			for (int j=0; j < n; j++) cout << ")";
			cout << "\n";
			return;
		}
	}

	for (int j=0; j < n; j++){
		cout << "()";
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
