#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define MAXN 100005
#define MAXS 5005
#define ll long long

using namespace std;

int n, k, c, lim[MAXN];

struct Node {
    int id, school, filled, rank;
    Node(int id0 = 0, int school0 = 0, int filled0 = 0, int r0 = 0):
        id(id0), school(school0), filled(filled0), rank(r0){}
};

bool cmp(Node x, Node y) {
    return x.rank < y.rank;
}


vector<Node> combined;
int school_pla[MAXN];
vector<Node> ans;

void solve() {
    cin >> n >> k >> c;
    int t, s;
    for (int i = 0; i < n; ++i) {
        cin >> t >> s;
        combined.push_back(Node(t, s, 0, i));
    }

    for (int i = 0; i < n; ++i) {
        Node tmp = combined[i];
        if (school_pla[tmp.school] < c) {
            ++school_pla[tmp.school];
            combined[i].filled = 1;
            ans.push_back(tmp);
        }
    }

    for (int i = 0; i < n; ++i) {
        Node tmp = combined[i];
        if (tmp.filled != 1) {
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.begin() + k, cmp);

    for (int i = 0; i < k; ++i) {
        cout << ans[i].id << endl;
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