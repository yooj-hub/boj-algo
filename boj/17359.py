from itertools import permutations
import sys
countings = []
bulbs = []
input = sys.stdin.readline
n = int(input())
bulbs = [input().rstrip() for _ in range(n)]
base = 0
x = []

for i in bulbs:
    base += i.count('01') + i.count('10')
    x.append([i[0],i[-1]])

cnt = int(1e9+7)
per = list(permutations(x))
for p in per:
    tmp = base
    for i in range(len(p)-1):
        if p[i][-1] != p[i+1][0]:
            tmp += 1
    cnt = min(tmp, cnt)
print(cnt)