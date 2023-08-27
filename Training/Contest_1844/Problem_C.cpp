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
#define rep(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X, S, Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve() {

    ll s;
    cin >> s;
    vll nums(s);
    ll min = INF;
    ll max = -INF;
    ll imin = 0;
    for (ll i = 0; i < s; i++) {
        cin >> nums[i];
        if (nums[i] < min) {
            min = nums[i];
            imin = i;
        }
        if (nums[i] > max) max = nums[i];
    }

    bool incr = false;
    while (nums.size() > 1) {
        if (nums.size() == 2) {
            cout << std::max<long long int>(nums[0], nums[1]) << "\n";
            return;
        }

        if (imin < 0) {
            for (ll i = 0; i < nums.size(); i++) {
                if (nums[i] < min) {
                    min = nums[i];
                    imin = i;
                }
            }
        }

        for (ll i = 1; i < nums.size() - 1; i++) {
            if (nums[i + 1] + nums[i - 1] > max) {
                max = nums[i - 1] + nums[i + 1];
                nums[i] = max;
                nums.erase(nums.begin() + i + 1);
                nums.erase(nums.begin() + i - 1);
                if (i == imin || i + 1 == imin || i - 1 == imin) imin = -1;
                incr = true;
                break;
            }
            if (!incr) {
                if (nums[0] > nums[nums.size() - 1]) nums.erase(nums.begin() + imin);
                else nums.erase(nums.begin());
            }
            incr = false;
        }
    }
    cout << nums[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
