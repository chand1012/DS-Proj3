#include <iostream>
#include <string>
#include <cstdlib>

#include "HashTable.hpp"
#include "helpers.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {

    srand(time(NULL));

    int iterations = 10000;
    string charset = "012";
    int length;

    vector<string> test_strings;

    for (int i = 0; i < iterations; ++i) {
        length = rand() % 10 + 1;
        test_strings.push_back(randString(length));
    }

    HashTable table;

    for (int i = 0; i < iterations; ++i) {
        string test = test_strings.at(i);
        table.add(test, i);
    }


    return 0;
}