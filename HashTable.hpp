#pragma once
#include <string>
#include <vector>
#include <limits>

using std::string;
using std::vector;

class HashTable {
    private:
        struct HashNode {
            string key = "";
            int value = std::numeric_limits<int>::min();
        };
        int hashKey(string);
        size_t rows = 0;
        // stores table info
        vector<vector<HashNode>> table;
    public:
        HashTable(int);
        HashTable();
        ~HashTable();
        // keys are strings
        // values are integers
        void add(string, int);
        // returns true if removal was successful
        bool remove(string);
        int get(string);
        size_t size();
        // number of values for a given hash
        size_t size(int);
        bool isEmpty();
        // is hash populated?
        bool isEmpty(int);
};