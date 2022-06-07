import sys
m, n = map(int, sys.stdin.readline().split())
data = []
tot = 0
for i in range(n):
    tmp = int(sys.stdin.readline())
    tot += tmp
    data.append(tmp)


if tot < m:
    sys.stdout.write('0')
    exit(0)

tot -= m

answer = 0
mod = (1 << 64)
r = tot // n
x = tot % n

for i in range(n):
    answer = (answer + (r + (x > 0))**2) % mod
    x -= 1


sys.stdout.write(str(answer))
