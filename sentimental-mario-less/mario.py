from cs50 import get_int


def main():
    height = get_height()
    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i)


def get_height():
    while True:
        n = get_int("Heigth: ")
        if n > 0 and n <= 8:
            break
    return n


main()