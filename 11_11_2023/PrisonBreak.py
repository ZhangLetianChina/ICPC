t = int(input())
for i in range(t):
    n, m, r, c = map(int, input().split())
    print(max(m - c, c - 1) + max(n - r, r - 1))