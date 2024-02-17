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

char case_change(char x) {
    if (x >= 'a' && x <= 'z') return 'A' + (x - 'a');
    if (x >= 'A' && x <= 'Z') return 'a' + (x - 'A');
    return x;
}

void solve() {
    string s, p;
    cin >> s >> p;
    if (s == p) {
        cout << "Yes" << endl;
        return;
    }
    if (s.length() == p.length() + 1) {
        if (s.substr(0, s.length() - 1) == p && s[s.length() - 1] >= '0' && s[s.length() - 1] <= '9') {
            cout << "Yes" << endl;
            return;
        }
        if (s.substr(1, s.length()) == p && s[0] >= '0' && s[0] <= '9') {
            cout << "Yes" << endl;
            return;
        }
    }
    if (s.length() == p.length()) {
        bool flag = 1;
        for (unsigned i = 0; i <= s.length(); ++i) {
            if (case_change(s[i]) != p[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return;
        }
    }


    cout << "No" << endl;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}