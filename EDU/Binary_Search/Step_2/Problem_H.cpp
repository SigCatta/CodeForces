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

ll b = 0, s = 0, c = 0;
ll r;
ll ingr[3];
ll price[3];


bool good(ll m){
	ll money = r;
	
	if(((m * b) - ingr[0]) * price[0] > 0) money -= ((m * b) - ingr[0]) * price[0];
	if(((m * s) - ingr[1]) * price[1] > 0) money -= ((m * s) - ingr[1]) * price[1];
	if(((m * c) - ingr[2]) * price[2] > 0) money -= ((m * c) - ingr[2]) * price[2];

	return money >= 0;

}

void solve(){
	string str;
	cin >> str;
	rep(i, str.size()){
		if(str[i] == 'B') b++;
		else if (str[i] == 'S') s++;
		else c++;
	}
	rep(i, 3) cin >> ingr[i]; // b s c
	rep(i, 3) cin >> price[i]; // b s c
	cin >> r;

	ll l = -1, r = 1e15, m;
	while ( l + 1 < r){
		m = l + (r - l) / 2;
		if(good(m)) l = m;
		else r = m;
	}
	if(l == - 1) cout << 0 << "\n";
	else cout << l << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.precision(10);
	cout << std::fixed;

	solve();
}

