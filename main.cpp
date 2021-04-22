#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

#include "HashTable.hpp"
#include "helpers.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

/*
    The tests will be as follows:
        - Test N additions
        - Test N/2 random retrievals
        - Test N/2 random removals
*/

int main() {

    srand(time(NULL));

    int iterations[] = {10, 100, 1000, 10000, 100000};
    int iteration;
    int rnd;
    string tempStr;
    vector<string> randomStrings;
    ofstream output("Results.csv");

    output << "Test Name,10,100,1000,10000,100000" << endl;

    // pre-test. Generate random data.
    cout << "Generating random data." << endl;
    for (int i = 0; i < 100000; ++i) {
        // generate 100,000 random strings to test with
        // string length between 2 and 100
        rnd = randint(2, 100);
        tempStr = randString(rnd);
        randomStrings.push_back(tempStr);
        if (i % 2000 == 0) {
            cout << '.';
        }
    }
    cout << endl << "Done." << endl;

    cout << "Starting test." << endl;
    for (int i = 0; i < 5; ++i) {
        HashTable test;
        vector<string> testStrings;
        iteration = iterations[i];
        cout << "Running tests for " << iteration << " iterations." << endl;
        for (int j = 0; j < iteration; ++j) {
            rnd = randint(0, 99999);
            testStrings.push_back(randomStrings[rnd]);
        }
        cout << "Running add test." << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for (auto it = testStrings.begin(); it != testStrings.end(); ++it) {
            test.add(*it, randint(0, 9999999));
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Done." << endl;
        cout << "Running get tests." << endl;
        for (int j = 0; j < iteration/2; ++j) {
            rnd = randint(0, iteration-1);
            tempStr = test.get(testStrings[rnd]);
        }
        cout << "Done." << endl;
        cout << "Running remove tests." << endl;
        for (int j = 0; j < iteration/2; ++j) {
            rnd = randint(0, iteration-1);
            tempStr = test.remove(testStrings[rnd]);
        }
        cout << "Done." << endl;
        cout << "Finished all tests for " << iteration << " iterations." << endl;
        cout << std::setfill('-') << std::setw(19) << '-' << endl;
    }

    output.close();

    return 0;
}