#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> parse_line(string line) {
    string i;
    vector<string> l;
    std::stringstream ss(line);
    while (ss.good()) {
        getline(ss, i, ',');
        l.push_back(i);
    }
    return l;
}

void read_lines_to_vector(string filename, vector<string> &a,
                          vector<string> &b) {
    ifstream in(filename);
    string line, i;

    if (getline(in, line)) {
        a = parse_line(line);
    }

    if (getline(in, line)) {
        b = parse_line(line);
    }
}

vector<pair<int, int>> get_path(vector<string> wire) {
    pair<int, int> port = make_pair(0, 0);
    vector<pair<int, int>> p;
    map<string, pair<int, int>> d;
    d["R"] = make_pair(1, 0);
    d["L"] = make_pair(-1, 0);
    d["U"] = make_pair(0, 1);
    d["D"] = make_pair(0, -1);

    string direction;
    int len;
    pair<int, int> step;
    for (string pa : wire) {
        direction = pa.substr(0, 1);
        len = stoi(pa.substr(1));
        step = d.at(direction);
        for (int i = 0; i < len; i++) {
            port =
                make_pair(port.first + step.first, port.second + step.second);
            p.push_back(port);
        }
    }
    return p;
}

int main(int argc, char *argv[]) {
    vector<string> wire_a, wire_b;
    read_lines_to_vector("input", wire_a, wire_b);

    auto a = get_path(wire_a);
    auto b = get_path(wire_b);

    auto order_a = a;
    auto order_b = b;
    sort(order_a.begin(), order_a.end());
    sort(order_b.begin(), order_b.end());

    vector<pair<int, int>> s;
    set_intersection(order_a.begin(), order_a.end(), order_b.begin(),
                     order_b.end(), back_inserter(s));

    auto min_val = min_element(
        s.begin(), s.end(),
        [](const pair<int, int> &l, const pair<int, int> &r) {
            return abs(l.first) + abs(l.second) < abs(r.first) + abs(r.second);
        });

    // First part
    cout << abs(min_val[0].first) + abs(min_val[0].second) << endl;

    // Second part
    vector<int> distances;
    vector<pair<int, int>>::iterator it;
    for (auto i : s) {
        it = find(a.begin(), a.end(), i);
        auto pos_a = std::distance(a.begin(), it);

        it = find(b.begin(), b.end(), i);
        auto pos_b = std::distance(b.begin(), it);
        distances.push_back(pos_a + pos_b + 2);
    }

    auto min_distance = *min_element(distances.begin(), distances.end());
    cout << min_distance << endl;

    return 0;
}
