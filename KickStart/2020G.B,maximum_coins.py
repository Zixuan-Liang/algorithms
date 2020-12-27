T = int(input())
for case in range(T):
    print("Case #%d:" % (case+1), end=' ')
    
    N = int(input())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))
    ans = 0
    for i in range(N):
        x, y = 0, i
        lower, upper = 0, 0
        while x < N and y < N:
            lower += matrix[y][x]
            upper += matrix[x][y]
            ans = max(ans, lower, upper)
            x += 1
            y += 1
    print(ans)