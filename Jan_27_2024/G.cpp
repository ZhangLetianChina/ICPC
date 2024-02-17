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

int n, l, a[MAXN];

void solve() {
    cin >> n >> l;
    l *= 5;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur + a[i] <= l) cur += a[i];
        else {
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}