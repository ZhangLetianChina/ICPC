t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    houses = [int(x) for x in input().split()]
    
    colors = list(set(houses))
    ans = 1e5 + 1
    for color in colors:
        it = 0
        current = 0
        while it < n:
            if houses[it] == color:
                it += 1
                continue
            it += k
            current += 1
        # print(current, color)
        ans = min(ans, current)
    print(ans)
