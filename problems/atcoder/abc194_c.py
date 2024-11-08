n = int(input())
arr = list(map(int, input().split()))


prefix_sum = []
squared_prefix_sum = []

total = 0
squared_total = 0

for num in arr:
    prefix_sum.append(total)
    squared_prefix_sum.append(squared_total)

    total += num
    squared_total += num**2
ans = 0
for i in range(1, n):
    ans += i*arr[i]**2 - 2 * arr[i] * prefix_sum[i] + squared_prefix_sum[i]
print(ans)

# other method. since A_i is limited in scope, store the counts of each A_i and operate on that
# counts = {}

# for num in arr:
#     if num not in counts:
#         counts[num] = 0
#     counts[num] += 1

# total = 0
# kvs = list(counts.items())

# for i in range(0, len(kvs) - 1):
#     for j in range(i+1, len(kvs)):
#         total += kvs[i][1] * kvs[j][1] * (kvs[i][0] - kvs[j][0])**2
# print(total)