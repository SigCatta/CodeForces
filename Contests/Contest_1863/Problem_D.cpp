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
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	bool even = false;


	rep(i, n){
		int b = 0, w = 0;
		rep(j, m){
			if(s[i][j] != '.'){
				if(even){
					if(j % 2 == 0) {
						s[i][j] = 'B';
						b++;
					}
					else {
						s[i][j] = 'W';
						w++;
					}
				} else{
					if(j % 2 != 0){
						s[i][j] = 'B';
						b++;
					}
					else{
						s[i][j] = 'W';
						w++;
					}
				}
			}
		}
		b = 0;
		w = 0;
		even = !even;
	}

	rep(i,n){
		int b = 0;
		int w = 0;
		rep(j,n){
			if(s[i][j] == 'B') b++;
			else if (s[i][j] == 'W') w++;
		}
		if(w != b){
			cout << -1 << "\n";
			return;
		}
		b = 0;
		w = 0;
	}


	rep(i,n){
		int b = 0;
		int w = 0;
		rep(j,n){
			if(s[j][i] == 'B') b++;
			else if (s[j][i] == 'W') w++;
		}
		if(w != b){
			cout << -1 << "\n";
			return;
		}
		b = 0;
		w = 0;
	}

	rep(i, n){
		rep(j, m) cout << s[i][j];
		cout << "\n";
	}

	
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

