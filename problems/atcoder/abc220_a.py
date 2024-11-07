import math 
temp = input().split()
a, b, c = int(temp[0]), int(temp[1]), int(temp[2])

if math.ceil(a/c) <= math.floor(b/c):
    print(math.ceil(a/c) * c)
else:
    print("-1")
