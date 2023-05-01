from cs50 import get_float


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    pennies = calculate_pennies(cents)

    total_coins = quarters + dimes + nickels + pennies

    print(total_coins)


def get_cents():
    while True:
        dollars = get_float("Change owed: ")
        if dollars > 0:
            break

    cents = round(dollars * 100)
    return cents


def calculate_quarters(cents):
    return cents // 25


def calculate_dimes(cents):
    cents %= 25
    return cents // 10


def calculate_nickels(cents):
    cents %= 10
    return cents // 5


def calculate_pennies(cents):
    cents %= 5
    return cents


if __name__ == "__main__":
    main()