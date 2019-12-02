import itertools


def intcode(code):
    i = 0
    while code[i] != 99:
        if i > len(code):
            break
        if code[i] == 1:
            code[code[i + 3]] = code[code[i + 1]] + code[code[i + 2]]
        elif code[i] == 2:
            code[code[i + 3]] = code[code[i + 1]] * code[code[i + 2]]
        i += 4
    return code[0]


if __name__ == "__main__":
    # Part one
    code = None
    with open("input-restored", "r") as f:
        code = [int(i) for i in f.read().strip().split(",")]
    print(intcode(code))

    # Part two
    code = None
    with open("input-restored", "r") as f:
        code = [int(i) for i in f.read().strip().split(",")]
    for i, j in itertools.product(list(range(100)), repeat=2):
        newcode = code[:]
        newcode[1], newcode[2] = i, j
        if intcode(newcode) == 19690720:
            print(100 * i + j)
            break
