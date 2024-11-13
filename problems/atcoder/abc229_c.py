temp = input().split()
n, w = int(temp[0]), int(temp[1])

cheeses = [list(map(int, input().split())) for _ in range(n)]
cheeses.sort(key=lambda x: (-x[0]))

i = 0
ans = 0
while w > 0 and i < n:
    ans += cheeses[i][0] * min(w, cheeses[i][1])
    w -= min(w, cheeses[i][1])
    i += 1

print(ans)
