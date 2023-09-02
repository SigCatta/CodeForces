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

ll n, m, d;
vector<vector<pair<ll, ll>>> g;
bool finished;
ll mid;
vll visits;
ll fin;
vll visited;

void dfs(int index, int iteration){
	if(!finished && visited[index] > iteration){
		visited[index] = iteration;
		visits[iteration] = index;
		rep(i, g[index].size()) if(g[index][i].first == n && g[index][i].second <= mid) {
			finished = true;
			fin = iteration + 1;
			visits[fin] = n;
			return;
		}
		if(iteration + 1 < d) {
			rep(i, g[index].size()) if(g[index][i].second <= mid) dfs(g[index][i].first, iteration + 1);
		}
	}
}

void solve(){
	cin >> n >> m >> d;
	ll a, b, c;
	g = vector<vector<pair<ll, ll>>>(n + 1);
	visited = vll(n + 1);
	ll maxD = 0;
	rep(i, m){
		cin >> a >> b >> c;
		g[a].pb(mp(b, c));
		if(maxD < c) maxD = c;
	}

	visits = vll(m);
	
	ll l = -1, r = maxD + 1;
	finished = false;

	while(l + 1 < r){
		rep(i, n + 1) visited[i] = INF;
		mid = l + (r - l) / 2;
		dfs(1, 0);
		if(finished) r = mid;
		else l = mid;
		finished = false;
	}

	if(mid != r){
		rep(i, n + 1) visited[i] = INF;
		fin = 0;
		mid = r;
		dfs(1, 0);
	}
	if(fin > d || fin == 0){
		cout << -1 << "\n";
		return;
	}
	cout << fin << "\n";
	rep(i, fin + 1) cout << visits[i] << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}

