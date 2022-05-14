import sys
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
a_base = a * 0.01
b_base = b * 0.01
inv_a_base = 1.0-a_base
inv_b_base = 1.0-b_base
comb = [[0] * 19 for _ in range(19)]

for i in range(19):
    comb[i][0] = 1
    comb[i][i] = 1
    for j in range(1, i):
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1]

ap = [0.0] * 19
bp = [0.0] * 19
for i in range(19):
    ap[i] = (a_base**(18-i))*(inv_a_base**(i)) * comb[18][i]
    bp[i] = (b_base**(18-i))*(inv_b_base**(i)) * comb[18][i]

isPrime = [True] * 19
for i in range(4, 19, 2):
    isPrime[i] = False

for j in range(3, 19, 2):
    if j * j > 19:
        break
    if isPrime[j]:
        for x in range(j*j, 19, j):
            isPrime[x] = False
isPrime[0] = False
isPrime[1] = False
answer = 1.0
print(isPrime)

for i in range(19):
    for j in range(19):
        if not isPrime[i] and not isPrime[j]:
            answer -= ap[i] * bp[j]

print(answer)
