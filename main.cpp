#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "HashTable.hpp"
#include "helpers.hpp"

//#include "Hopscotch.h"

using namespace std;

/*
    The tests will be as follows:
        - Test N additions
        - Test N/2 random retrievals
        - Test N/2 random removals
*/

int main() {

    srand(time(NULL));

    #ifdef HOPSCOTCH_H
    int iterations[] = {10, 100, 1000, 2000, 3000};
    #else
    int iterations[] = {10, 100, 1000, 10000, 100000};
    #endif
    int iteration;
    int rnd;
    string tempStr;
    vector<string> randomStrings;
    vector<int> randomValues;

    // for HashTable
    stringstream add;
    stringstream get;
    stringstream remove;
    // for HopHash
    stringstream insert;
    stringstream search;
    stringstream deleteh;


    add << "Array Hash Table Add,";
    get << "Array Hash Table Get,";
    remove << "Array Hash Table Remove,";
    insert << "HopHash Table Insert,";
    search << "HopHash Table Search,";
    deleteh << "HopHash Table Delete,";

    #ifdef HOPSCOTCH_H
    ofstream output("HashTable_vs_Hopscotch.csv");
    output << "Test Name,10,100,1000,2000,3000" << endl;
    #else
    ofstream output("Results.csv");
    output << "Test Name,10,100,1000,10000,100000" << endl;
    #endif

    // pre-test. Generate random data.
    cout << "Generating random data." << endl;
    #ifdef HOPSCOTCH_H
    for (int i = 0; i < 3000; ++i) {
    #else
    for (int i = 0; i < 100000; ++i) {
    #endif
        // generate 100,000 random strings to test with
        // string length between 2 and 100
        rnd = randint(2, 100);
        tempStr = randString(rnd);
        randomStrings.push_back(tempStr);
        randomValues.push_back(randint(0, 9999999));
        if (i % 2000 == 0) {
            cout << '.';
        }
    }
    cout << endl << "Done." << endl;

    cout << "Starting test." << endl;
    for (int i = 0; i < 5; ++i) {
        HashTable test;
        iteration = iterations[i];
        cout << "Running tests for " << iteration << " iterations." << endl;
        cout << "Running HashTable Add test." << endl;
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration; ++j) {
            test.add(randomStrings[j], randomValues[j]);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        add << duration.count() << ",";
        cout << "Done." << endl;
        cout << "Running HashTable Get tests." << endl;
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration/2; ++j) {
            rnd = randint(0, iteration-1);
            test.get(randomStrings[rnd]);
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        get << duration.count() << ",";
        cout << "Done." << endl;
        cout << "Running HashTable Remove tests." << endl;
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration/2; ++j) {
            rnd = randint(0, iteration-1);
            test.remove(randomStrings[rnd]);
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        remove << duration.count() << ",";
        cout << "Done." << endl;
        // if other test file is included
        // Hopscotch.h was modified to have
        // 100,000 bucket placements and distance of 20
        #ifdef HOPSCOTCH_H
        HopHash hoptest;
        cout << "Running Hopscotch insert tests." << endl;
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration; ++j) {
            hoptest.insertHop(randomValues[j]);
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        insert << duration.count() << ',';
        cout << "Done." << endl;
        cout << "Running Hopscotch search tests." << endl;
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration; ++j) {
            rnd = randint(0, iteration-1);
            hoptest.searchHash(randomValues[rnd]);
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        search << duration.count() << ',';
        start = chrono::high_resolution_clock::now();
        for (int j = 0; j < iteration; ++j) {
            rnd = randint(0, iteration-1);
            hoptest.deleteHash(randomValues[rnd]);
        }
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);
        deleteh << duration.count() << ',';
        #endif
        cout << "Finished all tests for " << iteration << " iterations." << endl;
        cout << setfill('-') << setw(25) << '-' << endl;
    }

    output << add.str() << endl;
    output << get.str() << endl;
    output << remove.str() << endl;

    #ifdef HOPSCOTCH_H
    output << insert.str() << endl;
    output << search.str() << endl;
    output << deleteh.str() << endl;
    #endif

    output.close();

    return 0;
}