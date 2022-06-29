n = int(input())

s = [0 for i in range(n)]
for i in range(n):
    s[i] = input()

k = int(input())

def conv(c):
    if ord('0') <= ord(c) <= ord('9'):
        return ord(c) - ord('0')
    else:
        return ord(c) - ord('A') + 10

def rev(n):
    if n >= 10:
        return chr(ord('A') + n - 10)
    else:
        return chr(ord('0') + n)

weight = {}
for si in s:
    mul = 1
    for c in si[::-1]:
        if c not in weight:
            weight[c] = 0
        weight[c] += mul * (35 - conv(c))
        mul *= 36

weight = dict(sorted(weight.items(), key=lambda item: -item[1]))

for i, key in enumerate(weight.keys()):
    if i == k:
        break

    for i, si in enumerate(s):
        s[i] = si.replace(key, 'Z')

ans_num = sum([int(si, 36) for si in s])
ans_list = []

if ans_num == 0:
    print(0)
else:
    while ans_num > 0:
        ans_list[0:0] = [ans_num % 36]
        ans_num //= 36

    print(''.join([rev(c) for c in ans_list]))