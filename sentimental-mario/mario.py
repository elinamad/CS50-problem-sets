# TODO
# program that prints out pyramid with a height of the inputed value (0-8)
from cs50 import get_int


def main():

    height = get_height()

    counter = 0
    # do height times
    for i in range(height):
        counter += 1
        # add the whitespaces
        for i in range((height-1)-i):
            print(" ", end="")
        # add the hash symbol
        for i in range(counter):
            print("#", end="")
        # print new line
        print("\n", end="")


def get_height():
    # ask for height until user cooperates
    while True:
        try:
            n = get_int("Height:")
            if n > 0 and n <= 8:
                return n
        except ValueError:
            print("input an integer from 0 - 8")


main()