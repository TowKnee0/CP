import math
n = int(input())

l = len(str(n))

if l < 2:
    print(0)
else:
    total = 0
    for i in range(1, int(str(n)[0:math.ceil(l/2)])+1):
        if int(str(i) * 2) <= n:
            total += 1
        else:
            break
    print(total)