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
	int n;
	cin >> n;
	vector<vector<unsigned short>> b(n, vector<unsigned short>(n, 0));
	vector<vector<unsigned short>> c(n, vector<unsigned short>(n, 0));

	int count = 0;

	string m[n];
	rep(i, n) cin >> m[i];

	bool inv;
	bool bias = false;
	rep(i, n){
		inv = bias;
		rep(j, n){
			if(b[i][j]){
				inv = !inv;
				if(i + 1 < n){
					if(j - 1 >= 0) b[i + 1][j - 1] ^= 1;
					else bias = !bias;
				}
			}

			if(m[i][j] == '1' ^ inv){
				count++;
				if(i + 1 < n){
					if(j - 1 >= 0){
						b[i + 1][j - 1] ^= 1;
					} else bias = !bias;
					if(j + 1 < n) c[i + 1][j + 1] ^= 1;
				}
			}

			if(c[i][j]){
				inv = !inv;
				if(j + 1 < n && i + 1 < n) c[i + 1][j + 1] ^= 1;
			}
		}
	}

	cout << count << "\n";
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
