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
	ll n, x, y;
	cin >> n >> x >> y;

	if(x == y){
		cout << 0 << "\n";
		return;
	}

	ll ans = 0;
	ll sov = 0;
	ll max = std::max(x, y);
	ll min = std::min(x, y);
	if(max % min == 0) sov = n / max;
	else{
		for(ll i = max; i <= n; i += max){
			if((i % min) == 0){
				sov = n / i;
				break;
			}
		}
	}
	

	ll divX = n / x;
	ll divY = n / y;
	ans += ((n + 1) * (divX - sov)) - (((divX - sov) * (divX - sov + 1)) / 2);
	ans -= ((divY - sov) * (divY - sov + 1)) / 2;
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

