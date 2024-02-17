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
    string s;
    cin >> s;
    int flag, score, a_s = 0, b_s = 0;
    for (unsigned i = 0; i < s.length(); i += 2) {
        if (s[i] == 'A') flag = 1;
        else flag = 0;
        if (s[i + 1] == '1') score = 1;
        else score = 2;
        if (flag == 1) a_s += score;
        else b_s += score;
        // cout << score << endl;
        // cout << a_s << " " << b_s << endl;
        if (a_s >= 11 && a_s - b_s >= 2) {
            cout << "A" << endl;
            break;
        } 
        if (b_s >= 11 && b_s - a_s >= 2) {
            cout << "B" << endl;
            break;
        }
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