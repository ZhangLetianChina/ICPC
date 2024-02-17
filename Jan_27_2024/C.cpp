#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define MAXN 1000005
#define MAXS 5005
#define ll long long

using namespace std;

int n;
double k, f[MAXN], d[MAXN];

struct Node {
    double remain, day;
    Node(double r0 = 0.0, double d0 = 0.0):
        remain(r0), day(d0) {}
    bool operator < (const Node &x) const {
        return day < x.day;
    }
};

bool chk(double req) {
    priority_queue<Node> q;
    double fi, temp_req;
    for (int i = 1; i <= n; ++i) {
        q.push(Node(f[i], d[i]));
        temp_req = req;
        while (true) {
            if (q.empty() && temp_req > 0) return false;
            else if (q.empty()) break;
            Node tmp = q.top(); q.pop();
            // cout << "i rem day " << i << " " << tmp.remain << " " << tmp.day << endl;

            if (tmp.day < i) continue;
            if (tmp.remain == 0.0) continue;
            if (tmp.remain >= temp_req) {
                tmp.remain -= temp_req;
                q.push(tmp);
                break;
            } else {
                temp_req -= tmp.remain;
            }
            
        }
        if (q.empty()) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    double food, day;
    for (int i = 1; i <= n; ++i) {
        cin >> food >> day;
        f[i] = food;
        d[i] = day;
    }
    if (f[1] == 0) {
        cout << -1 << endl;
        return;
    }

    double l = 0.0, r = 1000000008, mid;
    while (r - l > 0.000000001) {
        mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << " " << chk(mid) << endl;
        if (chk(mid)) l = mid;
        else r = mid;
    }

    cout << r / k;
}

int main() {

    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
