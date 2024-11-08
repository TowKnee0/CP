n = int(input())
arr = list(map(int, input().split()))
x = int(input())

# sum upto and including index
prefix = []

curr = 0
for i in range(len(arr)):
    curr += arr[i]
    prefix.append(curr)

# number of times all of A fits into x
multiples = x // prefix[-1]
remainder = x - multiples * prefix[-1]

for i in range(len(prefix)):
    if prefix[i] > remainder:
        print(multiples * len(arr) + i+1)
        break


