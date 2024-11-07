temp = input().split()
a, b = int(temp[0]), int(temp[1])

if b < a:
    a, b = b, a

if b - a <= 1 or (a == 1 and b == 10):
    print("Yes")
else:
    print("No")