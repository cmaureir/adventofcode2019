#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int intcode(vector<int> code) {
    int i = 0;
    while (code[i] != 99) {
        if (i > code.size())
            break;
        if (code[i] == 1) {
            code[code[i + 3]] = code[code[i + 1]] + code[code[i + 2]];
        } else if (code[i] == 2) {
            code[code[i + 3]] = code[code[i + 1]] * code[code[i + 2]];
        }
        i += 4;
    }
    return code[0];
}

vector<int> read_line_to_vector(string filename) {
    ifstream in(filename);
    string line;
    vector<int> code;

    if (getline(in, line)) {
        std::stringstream ss(line);
        int i;
        while (ss >> i) {
            code.push_back(i);
            if (ss.peek() == ',' || ss.peek() == ' ')
                ss.ignore();
        }
    }

    return code;
}

int main(int argc, char *argv[]) {
    // First part
    vector<int> code = read_line_to_vector("input-restored");
    cout << intcode(code) << endl;

    // Second part
    vector<int> code2 = read_line_to_vector("input");

    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            code2 = code;
            code2[1] = a;
            code2[2] = b;
            if (intcode(code2) == 19690720) {
                cout << 100 * a + b << endl;
                break;
            }
        }
    }

    return 0;
}
