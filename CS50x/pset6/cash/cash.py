from cs50 import get_float

change = get_float("Change owed: ")
while change < 0:
    change = get_float("Change owed: ")

change = round(change * 100)
count = 0

while change != 0:
    if change >= 25:
        change = change - 25
        count += 1
        continue
    elif change >= 10:
        change = change - 10
        count += 1
        continue
    elif change >= 5:
        change = change - 5
        count += 1
        continue
    change = change - 1
    count += 1
print(count)