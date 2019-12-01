# First part
with open("input", "r") as f:
    print(sum(int(i) // 3 - 2 for i in f.readlines()))

# Second part
def get_fuel(i):
    fuel = i // 3 - 2
    return fuel if fuel >= 0 else None


def get_total_fuel(fuel):
    while fuel := get_fuel(fuel):
        yield fuel


with open("input", "r") as f:
    print(sum(sum(get_total_fuel(int(i))) for i in f.readlines()))
