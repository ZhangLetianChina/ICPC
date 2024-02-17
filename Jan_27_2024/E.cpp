#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define MAXN 55
#define MAXS 5005
#define ll long long

using namespace std;

int n, dp[MAXN][3][MAXN][MAXN][MAXN], a[MAXN], b[MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int l = 0; l < MAXN; ++l) {
                for (int r = 0; r < MAXN; ++r) {
                    for (int k = 0; k < MAXN; ++k)
                    dp[i][j][l][r][k] = -1;
                }
            }
        }
    }

}

int main() {
    init();
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

    dp[1][0][0][0][0] = 0; // don't pick first student
    dp[1][1][a[1]][b[1]][1] = 0; // pick first student

    int ai, bi;
    for (int i = 2; i <= n; ++i) {
        ai = a[i];
        bi = b[i];


        for (int j = 0; j < 3; ++j) {
            if (j == 0) { // start with a new group
                dp[i][j][0][0][0] = dp[i - 1][j][0][0][0]; // don't pick this student
                dp[i][j + 1][ai][bi][i] = dp[i - 1][j][0][0][0]; // pick this student
            } else if (j == 1) { // start with a group with 1 student
                //don't pick this student
                for (int l = 1; l <= n; ++l) {
                    for (int r = 1; r <= n; ++r) {
                        for (int k = 1; k <= n; ++k) {
                            if (r < l) continue;
                            if (dp[i - 1][j][l][r][k] == -1) continue;
                            dp[i][j][l][r][k] = max(dp[i][j][l][r][k], dp[i - 1][j][l][r][k]);
                        }
                    }
                }
                //pick this student
                for (int l = 1; l <= n; ++l) {
                    for (int r = 1; r <= n; ++r) {
                        for (int k = 1; k <= n; ++k) {
                            if (r < l || i < l || i > r || k < ai) continue;
                            if (dp[i - 1][j][l][r][k] == -1) continue;
                            dp[i][j + 1][max(l, ai)][min(r, bi)][k] = max(dp[i][j + 1][max(l, ai)][min(r, bi)][k], dp[i - 1][j][l][r][k]);
                        }
                    }
                }
            } else if (j == 2) { // start with a group with 2 student
                //don't pick this student
                for (int l = 1; l <= n; ++l) {
                    for (int r = 1; r <= n; ++r) {
                        for (int k = 1; k <= n; ++k) {
                            if (r < l) continue;
                            if (dp[i - 1][j][l][r][k] == -1) continue;
                            dp[i][j][l][r][k] = max(dp[i][j][l][r][k], dp[i - 1][j][l][r][k]);
                        }

                    }
                }
                //pick this student
                for (int l = 1; l <= n; ++l) {
                    for (int r = 1; r <= n; ++r) {
                        for (int k = 1; k <= n; ++k) {
                            if (r < l || i < l || i > r || k < ai) continue;
                            if (dp[i - 1][j][l][r][k] == -1) continue;
                            dp[i][0][0][0][0] = max(dp[i][0][0][0][0], dp[i - 1][j][l][r][k] + 1);
                        }
                    }
                }
            }
        }





    }

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int l = 0; l < MAXN; ++l) {
                for (int r = 0; r < MAXN; ++r) {
                    for (int k = 0; k < MAXN; ++k) {
                        ans = max(ans, dp[i][j][l][r][k]);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}