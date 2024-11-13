temp = input().split()
n, m, q = int(temp[0]), int(temp[1]), int(temp[2])

queries = [input().split() for _ in range(q)]
buckets = [[] for _ in range(m)]
buckets[0] = [i for i in range(n)]


for query in queries:
    if query[0] == 's':
        buckets[int(query[2])].append(buckets[int(query[1])].pop())
    else:
        a = int(query[1])
        i = int(query[2])

        if a >= len(buckets):
            print(-1)
        elif i >= len(buckets[a]):
            print(-1)
        else:
            print(buckets[a][i])
