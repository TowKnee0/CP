q = int(input())
queries = [input().split() for _ in range(q)]

books = {}

for query in queries:
    if query[0] == 'a':
        if query[1] not in books:
            books[query[1]] = 0
        books[query[1]] += 1
    elif query[0] == 't':
        books[query[1]] -= 1
    else:
        if query[1] not in books:
            print(0)
        else:
            print(books[query[1]])
