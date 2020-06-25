from cs50 import get_float

input = 0
while True:
    input = get_float("input: ")
    if input > 0:
        break

coins = round(input * 100, 0)

output = 0

while coins > 0:
    
    if (coins >= 25):
        coins -= 25
        output += 1

    elif (coins >= 10):
        coins -= 10
        output += 1

    elif(coins >= 5):
        coins -= 5
        output += 1

    else:
        coins -= 1
        output += 1
print(output)
