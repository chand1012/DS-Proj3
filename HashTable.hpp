#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class HashTable {
    private:
        struct HashNode {
            string key;
            int value;
        };
        int hashKey(string);
        // stores table info
        vector<vector<HashNode>> table;
    public:
        HashTable();
        ~HashTable();
        // keys are strings
        // values are integers
        void add(string, int);
        // returns true if removal was successful
        bool remove(string);
        int get(string);
        size_t size();
        // number of values for a given key
        size_t size(string);
        bool isEmpty();
        // is key populated?
        bool isEmpty(string);
};