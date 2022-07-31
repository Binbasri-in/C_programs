# Your code here

litters = dict()
l = int(input())
i = 0
while (i < l):
    string = input()
    temp = ""
    count = 0
    for c in string:
        temp = temp + c
        for cc in temp:
            litters[cc] = litters.get(cc, 0) + 1

        for k in litters.values():
            if k % 2 == 0:
                count += 1
    print(count)