T = int(input())

for case in range(T):
    text = input()
    
    print("Case #%d:" % (case+1), end=' ')
    kick = 0
    N = len(text)
    i = 0
    ans = 0
    while i<N:
        if text[i] == 'K':
            if i+3<N and text[i+1:i+4]=="ICK":
                kick += 1
        elif text[i] == 'S':
            if i+4<N and text[i+1:i+5]=="TART":
                ans += kick
        i += 1
    print(ans)
            