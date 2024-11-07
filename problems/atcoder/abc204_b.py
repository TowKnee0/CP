N = int(input())
arr = map(int, input().split())

total = 0
for num in arr:
    if num > 10:
        total += num - 10
print(total)


