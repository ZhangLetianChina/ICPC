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
string s;
vector<int> um_list;

bool is_dl(char x) {
    if (x >= '0' && x <= '9') return true;
    if (x >= 'a' && x <= 'z') return true;
    if (x >= 'A' && x <= 'Z') return true;
    return false;
}

bool is_um(int x, int y) {
    if (x > y) return false;
    for (int i = x; i <= y; ++i) if (is_dl(s[i]) && s[i] != 'u' && s[i] != 'm') return false;
    return true;
}

void to_list(int x, int y) {
    for (int i = x; i <= y; ++i) {
        if (s[i] == 'u') um_list.push_back(1);
        else if (s[i] == 'm') um_list.push_back(0);
    }
}

void solve() {
    getline(cin, s);
    vector<int> vec;
    vec.push_back(-1);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') vec.push_back(i);
    }
    vec.push_back(s.length());
    for (int i = 1; i < vec.size(); ++i) {
        if (is_um(vec[i - 1] + 1, vec[i] - 1)) to_list(vec[i - 1] + 1, vec[i] - 1);
    }
    for (int i = 0; i < um_list.size(); i += 7) {
        //cout << um_list[i] << " ";
        int j = i, pla = 7;
        int co = 0;
        while (pla--) {
            co *= 2;
            co += um_list[j];
            ++j;
        }
        cout << (char)co;
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