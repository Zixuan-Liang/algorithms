


T = int(input())
for case_num in range(T):
    N, Q = map(int, raw_input().strip().split())
    names = raw_input().strip().split()
    
    dist = [[69 for i in range(26)] for i in range(26)]
    msks = [0 for i in range(N)]
    A = ord('A')
    for i in range(N):
        for char in names[i]:
            msks[i] |= 1 << (ord(char)-A)
        for x in range(26):
            if msks[i] >> x & 1:
                for y in range(26):
                    if msks[i] >> y & 1:
                        dist[x][y] = 1
    for i in range(26):
        dist[i][i] = 0
    for k in range(26):
        for i in range(26):
            for j in range(26):
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
    
    print "Case #" + str(case_num+1) + ":",
    for _ in range(Q):
        x, y = map(int, raw_input().strip().split())
        x, y = x-1, y-1
        best = 69
        for i in range(26):
            if msks[x] >> i & 1:
                for j in range(26):
                    if msks[y] >> j & 1:
                        best = min(best, dist[i][j])
        ans = best+2 if best < 26 else -1
        print ans,
    print "" 