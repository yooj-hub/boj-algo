import sys

first_line = sys.stdin.readline().rstrip()


n, m = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))
answer = -1

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            tmp = cards[i] + cards[j] + cards[k]
            if tmp > m:
                continue
            if answer == -1 or tmp > answer:
                answer = tmp
print(answer)
