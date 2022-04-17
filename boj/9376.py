from collections import deque
import sys
from collections import deque
t = int(sys.stdin.readline().rstrip())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


for i in range(t):
    h, w = map(int, (sys.stdin.readline().split()))
    board = []
    board.append("."*(w+2))
    for j in range(h):
        board.append('.'+sys.stdin.readline().rstrip()+'.')
    board.append("."*(w+2))
    q0 = deque()
    q1 = deque()
    q2 = deque()
    for j in range(h+2):
        for k in range(w+2):
            if board[j][k] == "$":
                if q1:
                    q2.append((j, k))
                else:
                    q1.append((j, k))
    q0.append((0,0))
    dist0 = [[0] * (w+2) for _ in range(h+2)]
    dist1 = [[0] * (w+2) for _ in range(h+2)]
    dist2 = [[0] * (w+2) for _ in range(h+2)]
    chk = [[False] * (w+2) for _ in range(h+2)]
    while q0:
        x, y = q0.popleft()
        chk[x][y] = True
        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]
            if(nx < 0 or ny >= w+2 or ny < 0 or nx >= h+2):
                continue
            if chk[nx][ny]:
                continue
            if board[nx][ny] == "." or board[nx][ny] == "$":
                q0.appendleft((nx, ny))
                chk[nx][ny] = True
                dist2[nx][ny] = dist2[x][y]
            if board[nx][ny] == "#":
                q0.append((nx, ny))
                chk[nx][ny] = True
                dist2[nx][ny] = dist2[x][y]+1
    chk = [[False] * (w+2) for _ in range(h+2)]
    while q1:
        x, y = q1.popleft()
        chk[x][y] = True
        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]
            if(nx < 0 or ny >= w+2 or ny < 0 or nx >= h+2):
                continue
            if chk[nx][ny]:
                continue
            if board[nx][ny] == "." or board[nx][ny] == "$":
                q1.appendleft((nx, ny))
                chk[nx][ny] = True
                dist0[nx][ny] = dist0[x][y]
            if board[nx][ny] == "#":
                q1.append((nx, ny))
                chk[nx][ny] = True
                dist0[nx][ny] = dist0[x][y]+1
    chk = [[False] * (w+2) for _ in range(h+2)]
    while q2:
        x, y = q2.popleft()
        chk[x][y] = True
        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]
            if(nx < 0 or ny >= w+2 or ny < 0 or nx >= h+2):
                continue
            if chk[nx][ny]:
                continue
            if board[nx][ny] == "." or board[nx][ny] == "$":
                q2.appendleft((nx, ny))
                chk[nx][ny] = True
                dist1[nx][ny] = dist1[x][y]
            if board[nx][ny] == "#":
                q2.append((nx, ny))
                chk[nx][ny] = True
                dist1[nx][ny] = dist1[x][y]+1
    answer = -1
    
    for j in range(h+2):
        for k in range(w+2):
            if not chk[j][k] : continue
            if board[j][k] == "*": continue
            if board[j][k] == "#":
                tmp = dist0[j][k] + dist1[j][k] + dist2[j][k] -2
                if answer == -1 or answer > tmp:
                    answer = tmp
            if board[j][k] == "." or board[j][k] == "$":
                tmp = dist0[j][k] + dist1[j][k] + dist2[j][k]
                if answer == -1 or answer > tmp:
                    answer = tmp

    print(answer)
