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
    int n, a, b;
    cin >> n >> a >> b;
    int seen_min = 0, seen_max = 0, impossible = 0;

    for (int i = 0; i < n - 1; i++) {
        int current;
        cin >> current;
        if (current == a) seen_min = 1;
        if (current == b) seen_max = 1;
        if (current < a || current > b) impossible = 1;
    }
    if (impossible) {
        cout << -1 << endl;
        return;
    }
    if (seen_max && seen_min) {
        for (int i = a; i <= b; i++) {
            cout << i << endl;
        }
        return;
    } 
    if (seen_max) {
        cout << a << endl;
        return;
    } 
    if (seen_min) {
        cout << b << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}