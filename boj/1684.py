import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


mx = 0
tmp = []
arr.sort()
for i in range(n-1):
    tmp.append(arr[i+1] - arr[i])
mx = tmp[0]
for i in range(1, len(tmp)):
    mx = gcd(mx, tmp[i])
    
print(mx)
