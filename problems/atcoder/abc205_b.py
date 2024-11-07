N = int(input())
arr = map(int, input().split())

seen = set()
cmax = 0
cmin = N + 1
for num in arr:
    seen.add(num)
    cmax = max(cmax, num)
    cmin = min(cmin, num)

if cmax == N and cmin == 1 and len(seen) == N:
    print("Yes")
else:
    print("No")