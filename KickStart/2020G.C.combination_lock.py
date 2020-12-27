def combination_lock():
    W, N = map(int, input().split())
    X = list(map(lambda x:int(x)-1, input().split()))

    X.sort()
    for i in range(len(X)-1):
        X.append(X[i]+N)
    prefix = [0]
    for x in X:
        prefix.append(prefix[-1]+x)
    return min((prefix[i+W]-prefix[(i+i+W)//2])-(prefix[(i+i+W-1)//2+1]-prefix[i]) for i in range(W))  # find median of window with min number of moves

for case in range(int(input())):
    print('Case #%d: %s' % (case+1, combination_lock()))