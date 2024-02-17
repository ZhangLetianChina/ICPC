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
vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void solve() {
    string s;
    cin >> s;
    vector<pair<ll, ll> > v;
    v.push_back(pair<ll, ll>(1, 0)); // first represents the number of strings, second represents the shortest length
    for (int i = 0; i < s.size(); i++) {
        v.push_back(pair<ll, ll>(v.back().first, v.back().second + 1));
        for (string num : nums) {
            ll relevant_index = i - (ll) num.size() + 1;
            if (relevant_index < 0) continue;
            // cout << num << relevant_index;
            if (num == s.substr(relevant_index, num.size())) {
                // cout << "good" << endl;
                if (v.at(relevant_index).second + 1 < v.back().second) {
                    v.back().second = v.at(relevant_index).second + 1;
                    v.back().first = v.at(relevant_index).first;
                    v.back().first %= 9302023;
                } else if (v.at(relevant_index).second + 1 == v.back().second) {
                    v.back().first += v.at(relevant_index).first;
                    v.back().first %= 9302023;
                }   
            }
        }
    }
    /*
    for (int i = 1; i < v.size(); i++) {
        cout << v.at(i).first << " " << v.at(i).second << endl;
    }
    */
    
    cout << v.back().second << endl;
    cout << v.back().first << endl;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}