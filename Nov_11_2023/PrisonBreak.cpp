#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    // cout << "ok" << endl;
    
    int t; cin >> t;
    
    while(t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        cout << max(abs(n - r), r - 1) + max(abs(m - c), c - 1) << endl;
    }
    
    return 0;
}