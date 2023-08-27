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

    ll ans = 1;
    if(k >= 31) {
        for(int i = 1; i <= n; i <<= 1) {
            if((i & n) >= 1) {
                ans += i;
            }
        }
    } else {
        ll maxNum = 0;
        for(int i = 0; i < k; i++) {
            maxNum += (1 << i);
        }

        if(maxNum < n) {
            ans += maxNum;
        } else {
            for(int i = 1; i <= n; i <<= 1) {
                if((i & n) >= 1) {
                    ans += i;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}