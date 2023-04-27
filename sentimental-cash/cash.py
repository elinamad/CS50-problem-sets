# ask user for change (format 0.00 in dollars) and then tell the minimum number of
# coins with which said change can be made

import cs50

while True:
    cash = cs50.get_float("Change owed: ")
    if cash> 0:
        print("please input positive int")
        break

total, counter = cash * 100, 0

for x in [25, 10, 5, 1]:
    while total >= x:
        total -= x
        counter += 1

print(f"{counter}")