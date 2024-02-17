#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;


void solve() {
    string s;
    cin >> s;
    int non = 0, include = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' || s.at(i) == 'o' || s.at(i) == 'u') {
            non++;
            include++;
        }
        if (s.at(i) == 'y') {
            // non++;
            include++;
        }
    }
    cout << non << " " << include << endl;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}