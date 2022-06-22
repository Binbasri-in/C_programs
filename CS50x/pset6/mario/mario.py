# take height from user and check its int and around 1-8
try:
    height = int(input("Height: "))
except:
    height = int(input("Height: "))
while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except:
        height = int(input("Height: "))

# print the pyramid
for i in range(height):
    spaces = ' ' * (height - 1 - i)
    tags = '#' * (i + 1)
    print(spaces + tags + '  ' + tags)