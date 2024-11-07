n = int(input())
arr = list(map(int, input().split()))

# overcounts pais that are the same
pairs = n * (n - 1) // 2

repeats = {}
for num in arr:
    if num not in repeats:
        repeats[num] = 0
    repeats[num] += 1

for v in repeats.values():
    pairs -= v * (v - 1) // 2

print(pairs)


