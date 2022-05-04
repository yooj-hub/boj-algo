import sys

n = int(sys.stdin.readline())

left = 0
right = n
ans = -1
while left <= right:
    mid = (left+right)//2
    if mid ** 2 >= n:
        right = mid-1
        if ans == -1 or ans > mid:
            ans = mid
    else:
        left = mid+1

print(ans)
