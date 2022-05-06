import sys

nlist = sys.stdin.read().split('\n')

for n in nlist:
    if n == '':
        break

    n = int(n)
    ans = 1
    while True:
        if int('1' * ans) % n == 0:
            break
        ans += 1
    print(ans)
