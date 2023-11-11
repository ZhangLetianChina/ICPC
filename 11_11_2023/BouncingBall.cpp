/*
Labels: 
Status: 
Date: 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define MAXN 500005
#define MAXS 5005
#define ll long long

using namespace std;

int n, k, a[MAXN];

void init() {

}

bool cmp(int x, int y) {
    return x > y;
}

void solve() {
    cin >> n >> k;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    sort(a, a + n, cmp);
    total -= a[n - 1];
    int accu = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (total < 0 && k > 0) {
            --k;
        } else {
            ans += total;
        }
        total -= a[i];
    }
    cout << ans << endl;
}

int main() {

    ll _ = 1;
    // cin >> _;
    while(_--) {
        init();
        solve();
    }
    return 0;
}