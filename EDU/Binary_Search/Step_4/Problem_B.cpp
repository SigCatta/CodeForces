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
#include <bitset>

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
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e8;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<pair<int, ld>>> adj;
vi prec;
int n, m;

bool good(ld mean, vi in_arc) {
    queue<int> q;
    vector<ld> dp(n + 1, INF);
    q.push(1); // start with exploring 1
    dp[1] = 0; // starting from 1 has weigth 0

    for(int i = 2; i < n; i++) { // if no nodes point to i, explore i
        if(in_arc[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(pii edge : adj[curr]) { // explore each edge from the current node
            int next = edge.first;
            ld weight = edge.second;
            in_arc[next]--; // the node we reached through the current edge has 1 less edge (burn the current edge)
            if(in_arc[next] == 0) q.push(next); // if the next node has 0 not burned connections, queue it for exploration
            if(dp[next] > dp[curr] + weight - mean) { // if arriving to the next node costs less then what we calculated
                dp[next] = dp[curr] + weight - mean; // the new cost is the current cost
                prec[next] = curr; // we reached the next node through this node
            }
        }
    }

    return dp[n] <= 0; // the cost cost of reaching the end is <= 0
}

void solve(){
    cin >> n >> m;
    adj = vector<vector<pair<int, ld>>>(n + 1);
    vi in_arc(n + 1);
    prec = vi(n + 1);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        in_arc[b]++;
    }

    ld l = -1, r = 101;
    rep(i, 80) {
        ld mid = l + (r - l) / 2;
        fill(all(prec), -1);

        if(good(mid, in_arc)) r = mid;
		else l = mid;
    }

    fill(all(prec), -1);
    good(r, in_arc);

    vi path;
    int node = n;
    while(node != -1) { // if node == -1 we are at the first node
        path.insert(path.begin(), node);
        node = prec[node];
    }

    cout << (path.size() - 1) << '\n';
    for(int x : path) {
        cout << x << " ";
    }
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}