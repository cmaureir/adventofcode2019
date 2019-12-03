def get_path(wire):
    port = (0, 0)
    path = []
    d = {"R": (1, 0), "L": (-1, 0), "U": (0, 1), "D": (0, -1)}

    for pa in wire.split(","):
        for i in range(int(pa[1:])):
            port = tuple(map(sum, zip(port, d[pa[0]])))
            path.append(port)

    return path


if __name__ == "__main__":

    with open("input", "r") as f:
        wire_a, wire_b = f.read().strip().split("\n")

        a = get_path(wire_a)
        b = get_path(wire_b)

        s = set(a) & set(b)

        # Part 1
        print(min(abs(x) + abs(y) for x, y in s))

        # Part 2
        print(min(a.index(e) + b.index(e) + 2 for e in s))
