#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int get_fuel(int i) { return (i / 3) - 2; }

int get_total_fuel(int i) {
    int total_fuel = 0;
    int fuel = get_fuel(i);
    while (fuel >= 0) {
        total_fuel += fuel;
        fuel = get_fuel(fuel);
    }
    return total_fuel;
}

int main(int argc, char *argv[]) {
    ifstream in("input");
    string line;

    // First part
    int total = 0;
    while (in >> line) {
        total += get_fuel(stoi(line));
    }
    cout << total << endl;

    // Reset the file to the beginning
    in.clear();
    in.seekg(0);

    // Second part
    int real_total = 0;
    while (in >> line) {
        real_total += get_total_fuel(stoi(line));
    }
    cout << real_total << endl;

    return 0;
}
