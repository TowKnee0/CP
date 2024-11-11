temp = input().split()
n, q = int(temp[0]), int(temp[1])

s = input()

queries = [input().split() for _ in range(q)]

start = 0

for query in queries:
    if query[0] == '1':
        start = (start - int(query[1])) % n
    else:
        idx = (start + int(query[1]) - 1) % n
        print(s[idx])