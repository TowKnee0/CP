# CANT DO UNLESS IMPLEMENT SEGMENT TREE FROM SCRATCH OR SOMETHING THAT IS LIKE CPP MULTISET

from sortedcontainers import SortedDict

temp = input().split()
n, m = int(temp[0]), int(temp[1])

prices = map(int, input().split())
customers = map(int, input().split())

# if we cannot import this we would have to implement it outselves using a balanced binary tree.
# same as cpp multiset which is standard library
tickets = SortedDict()
for price in prices:
    if price not in tickets:
        tickets[price] = 0
    tickets[price] += 1

print(tickets)
print(tickets.bisect_left(6))

for c in customers:
    idx = tickets.bisect_left(c)


    
