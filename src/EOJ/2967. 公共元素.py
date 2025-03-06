T = int(input())

for I in range (T):
    a, b, c = input().split()
    l1 = tuple(map(int, input().split()))
    l2 = tuple(map(int, input().split()))
    l3 = tuple(map(int, input().split()))
    l4 = []

    for x in l1:
        if(x in l2 and x in l3):
            l4.append(x)

    l4.sort()
    print(f'case #{I}:')
    if len(l4) == 0:
        print(-1)
    else:
        for x in range (len(l4) - 1):
            print(l4[x], end=' ')
        print(l4[-1])
