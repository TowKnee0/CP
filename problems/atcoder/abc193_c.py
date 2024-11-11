import math
n = int(input())

# logn = math.log(n)
# count_representable = 0

# loop_end = math.ceil(math.sqrt(n))
# if loop_end - math.sqrt(n) == 0:
#     loop_end += 1

# possible_a = [True for _ in range(2, loop_end)]

# for i in range(len(possible_a)):
#     a = i+2
#     if possible_a[a - 2]:
#         count_representable += math.floor(logn/math.log(a)) - 1

#         powers_of_a = a**2
#         while powers_of_a - 2 < len(possible_a):
#             possible_a[powers_of_a - 2] = False
#             powers_of_a *= a 

# print(n - count_representable)

# brute force since the number of representable numbers isnt that large

seen = set()
for a in range(2, math.ceil(math.sqrt(n)) + 1):
    total = a**2
    while total <= n:
        seen.add(total)
        total *= a
    
print(n - len(seen))