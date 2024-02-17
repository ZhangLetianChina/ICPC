#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define MAXN 5000005
#define MAXS 5005
#define ll long long

using namespace std;

int n, a[MAXN];

void solve() {
    ll n, k, p;
    cin >> n >> k >> p;
    set<ll> v;
    
    for (ll i = 1; i < min((ll) 1000000, p + 1); i++) { // i represents p, number of pills
        if (n % i == 0 && n / i <= k) {
            v.insert(n / i);
        }
    }

    for (ll i = 1; i < min((ll) 1000000, k + 1); i++) { // i represents p, number of pills
        if (n % i == 0 && n / i <= p) {
            v.insert(i);
        }
    }
    
    
    cout << v.size() << endl;
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << (*i) << endl;
    }
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}